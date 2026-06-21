#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    // "Trust me bro, treat this memory address as an integer"
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    // "Trust me bro, treat this integer as a pointer to a Data struct"
    return reinterpret_cast<Data*>(raw);
}