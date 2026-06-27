#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

//--------------------------------------------------------------------------------

// --- Jacobsthal Sequence Generator ---
size_t PmergeMe::getJacobsthal(size_t n) const
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2);
}

// --- Display Helper ---
void PmergeMe::printVector(const std::string& prefix) const
{
    std::cout << prefix;

    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";

    std::cout << std::endl;
}

//--------------------------------------------------------------------------------

// --- Parsing ---
void PmergeMe::parseInput(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg.empty() || arg.find_first_not_of("0123456789 ") != std::string::npos)
            throw std::runtime_error("Error: Invalid character detected.");

        std::stringstream ss(arg);
        std::string token;
        
        while (ss >> token)
        {
            long val = std::atol(token.c_str());
            
            if (val < 0 || val > 2147483647)
                throw std::runtime_error("Error: Number out of bounds.");
            
            _vec.push_back(static_cast<int>(val));
            _deq.push_back(static_cast<int>(val));
        }
    }
}

//--------------------------------------------------------------------------------

// --- Algorithm for vectooor ---
void PmergeMe::sortVector()
{
    if (_vec.size() < 2)
        return;

    // Group into pairs
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (_vec.size() % 2 != 0);
    
    if (hasStraggler) 
        straggler = _vec.back();

    for (size_t i = 0; i + 1 < _vec.size(); i += 2)
    {
        if (_vec[i] > _vec[i+1]) pairs.push_back(std::make_pair(_vec[i], _vec[i+1]));
        else pairs.push_back(std::make_pair(_vec[i+1], _vec[i]));
    }

    // 2 & 3 - Sort pairs based on the larger element (first)
    std::sort(pairs.begin(), pairs.end());

    // 4- Separate into Main Chain and Pend
    std::vector<int> mainChain;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    // the rule of first element: Insert the first element of pend into mainChain
    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    // 5 -  Jacobsthal Insertion
    size_t prev_j = 1; 
    size_t curr_step = 3;

    while (prev_j < pend.size())
    {
        size_t next_j = getJacobsthal(curr_step);
        
        if (next_j > pend.size())
            next_j = pend.size();

        for (size_t i = next_j - 1; i >= prev_j; --i)
        {
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
            mainChain.insert(it, pend[i]);
            
            if (i == 0)
                break;
        }
        prev_j = next_j;
        curr_step++;
    }

    // 6 - Insert Straggler
    if (hasStraggler)
    {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }
    _vec = mainChain;
}

// --- Algorithm for std::deque ---
void PmergeMe::sortDeque()
{
    if (_deq.size() < 2)
        return;

    std::deque<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (_deq.size() % 2 != 0);
    if (hasStraggler)
        straggler = _deq.back();

    for (size_t i = 0; i + 1 < _deq.size(); i += 2)
    {
        if (_deq[i] > _deq[i+1])
            pairs.push_back(std::make_pair(_deq[i], _deq[i+1]));
        else
            pairs.push_back(std::make_pair(_deq[i+1], _deq[i]));
    }

    std::sort(pairs.begin(), pairs.end());

    std::deque<int> mainChain;
    std::deque<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    size_t prev_j = 1; 
    size_t curr_step = 3;
    while (prev_j < pend.size())
    {
        size_t next_j = getJacobsthal(curr_step);
        if (next_j > pend.size()) next_j = pend.size();

        for (size_t i = next_j - 1; i >= prev_j; --i)
        {
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
            mainChain.insert(it, pend[i]);
            if (i == 0)
                break;
        }
        prev_j = next_j;
        curr_step++;
    }

    if (hasStraggler)
    {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    _deq = mainChain;
}

//--------------------------------------------------------------------------------

// --- Execution & Timing ---
void PmergeMe::execute()
{
    printVector("Before: ");

    clock_t startVec = clock();
    sortVector();
    clock_t endVec = clock();

    clock_t startDeq = clock();
    sortDeque();
    clock_t endDeq = clock();

    printVector("After:  ");

    double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
    double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << deqTime << " us" << std::endl;
}
