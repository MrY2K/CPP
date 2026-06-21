#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data myData;
    myData.id = 42;
    myData.name = "Ayoub's Payload";

    std::cout << "--- Original Data ---" << std::endl;
    std::cout << "Address: " << &myData << std::endl;
    std::cout << "ID:      " << myData.id << std::endl;
    std::cout << "Name:    " << myData.name << std::endl;

    std::cout << "\n--- Serializing ---" << std::endl;
    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Raw uintptr_t value (hex): 0x" << std::hex << raw << std::dec << std::endl;

    std::cout << "\n--- Deserializing ---" << std::endl;
    Data* deserializedData = Serializer::deserialize(raw);
    
    std::cout << "Address: " << deserializedData << std::endl;
    std::cout << "ID:      " << deserializedData->id << std::endl;
    std::cout << "Name:    " << deserializedData->name << std::endl;

    std::cout << "\n--- Final Check ---" << std::endl;
    if (&myData == deserializedData)
        std::cout << "SUCCESS: Addresses match perfectly!" << std::endl;
    else
        std::cout << "FAILURE: Addresses do not match!" << std::endl;

    return 0;
}
