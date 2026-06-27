#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

//--------------------------------------------------------------------------------

std::string BitcoinExchange::trim(const std::string& str) const
{
    size_t first = str.find_first_not_of(" \t\n\r");
    
    if (first == std::string::npos)
        return "";
    
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');
        {
            std::string date = trim(line.substr(0, commaPos));
            std::string rateStr = trim(line.substr(commaPos + 1));
            
            float rate = std::atof(rateStr.c_str());
            _database[date] = rate;
        }
    }
    file.close();
}

//--------------------------------------------------------------------------------

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    //YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }
    
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const
{
    char* endPtr;
    double val = std::strtod(valueStr.c_str(), &endPtr);
    
    if (*endPtr != '\0' && *endPtr != 'f')
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }
    if (val < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    
    value = static_cast<float>(val);
    return true;
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty()) 
            continue;

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));



        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valueStr, value))
        {
            continue; // if there is an error the message is already printed in ValidateValue func
        }



        std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
        
        if (it != _database.end() && it->first == date)
        {
            // landed the exact date
            std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
        }
        else if (it == _database.begin())
        {
            // date is older than the very first record in our database
            std::cerr << "Error: no older date found in database for => " << date << std::endl;
        }
        else
        {
            // step back one to get the closest lower date
            --it;
            std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
        }
    }
    file.close();
}