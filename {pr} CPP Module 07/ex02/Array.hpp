#pragma once

template <typename T>
class Array
{
    private:
        T* _elements;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);2
        Array& operator=(const Array& other);
        ~Array();

};

template <typename T>
Array<T>::Array(): _elements(NULL), _size(_size = 0) {}

template <typename T>
Array<T>::Array(unsigned int n): _elements(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other)
{

}


template <typename T>
Array<T>::Array& operator=(const Array& other)
{

}

template <typename T>
Array<T>::~Array()
{
    
}