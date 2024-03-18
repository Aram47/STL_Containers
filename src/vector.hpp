#include "../header/vector.h"

#include <iostream>
#include <initializer_list>

template <typename T>
DS::Vector<T>::Vector()
            : m_size(0)
            , m_capacity(50)
            , m_array(nullptr)
{

}

template <typename T>
DS::Vector<T>::Vector(const Vector<T>& other)
            : m_size(other.m_size)
            , m_capacity(other.m_capacity)
            , m_array(new T[m_capacity])
{
    for (std::size_t i = 0; i < this -> m_size; ++i)
        this -> m_array[i] = other.m_array[i];
}

template <typename T>
DS::Vector<T>::Vector(Vector<T>&& other) noexcept
            : m_size(other.m_size)
            , m_capacity(other.m_capacity)
            , m_array(other.m_array)
{
    other.m_array = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
}

template <typename T>
DS::Vector<T>::Vector(std::initializer_list<T> list) 
            : m_size(list.size())
            , m_capacity(list.size())
            , m_array(new T[m_capacity]) 
{
        std::copy(list.begin(), list.end(), this -> m_array);
}



template <typename T>
DS::Vector<T>::Vector(int count)
{
    if (count <= 0)
        throw std::invalid_argument("");

    this -> m_size = 0;
    this -> m_capacity = count;
    this -> m_array = new T[this -> m_capacity];
}

template <typename T>
DS::Vector<T>::Vector(int count, const T& value)
{
    if (count <= 0)
        throw std::invalid_argument("");

    this -> m_size = count;
    this -> m_capacity = count;
    this -> m_array = new T[this -> m_capacity];

    for (std::size_t i = 0; i < this -> m_size; ++i)
        this -> m_array[i] = value;
}

template <typename T>
DS::Vector<T>::~Vector()
{
    DS::Vector<T>::clear();
}

template<typename T>
DS::Vector<T>& DS::Vector<T>::operator=(const Vector<T>& other)
{
    if (this == &other)
        return *this;

    DS::Vector<T>::clear();

    this -> m_size = other.m_size;
    this -> m_capacity = other.m_capacity;
    this -> m_array = new T[this -> m_capacity];

    for (std::size_t i = 0; i < this -> m_size; ++i)
        this -> m_array[i] = other.m_array[i];

    return *this;
}

template <typename T>
DS::Vector<T>& DS::Vector<T>::operator=(Vector&& other) noexcept
{
    if (this == other)
        return *this;

    DS::Vector<T>::clear();

    this -> m_size = other.m_size;
    this -> m_capacity = other.m_capacity;
    this -> m_array = other.m_array;

    other.m_size = 0;
    other.m_capacity = 0;
    other.m_array = nullptr;

    return *this;
}

template <typename T>
DS::Vector<T>& DS::Vector<T>::operator=(std::initializer_list<T> list)
{
    if (list.size() > this -> m_capacity) 
    {
        DS::Vector<T>::clear();
        this -> m_capacity = list.size();
        this -> m_array = new T[this -> m_capacity];
    }

    std::copy(list.begin(), list.end(), this -> m_array);
    this -> m_size = list.size();

    return *this;
}