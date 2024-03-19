#include "../header/vector.h"

#include <iostream>
#include <initializer_list>
#include <stdexcept>

template <typename T>
DS::Vector<T>::Vector()
            : m_size(0)
            , m_capacity(0)
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
    if (this -> m_array)
        delete [] this -> m_array;

    this -> m_size = 0;
    this -> m_capacity = 0;
    this -> m_array = nullptr;
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

template <typename T>
bool DS::Vector<T>::operator==(const Vector<T>& other) const 
{
    return (this -> m_size == other.m_size);
}

template <typename T>
bool DS::Vector<T>::operator!=(const Vector<T>& other) const
{
    return (this -> m_size != other.m_size);
}

template <typename T>
bool DS::Vector<T>::operator<(const Vector<T>& other) const
{
    return (this -> m_size < other.m_size);
}

template <typename T>
bool DS::Vector<T>::operator<=(const Vector<T>& other) const
{
    return (this -> m_size <= other.m_size);
}

template <typename T>
bool DS::Vector<T>::operator>(const Vector<T>& other) const
{
    return (this -> m_size > other.m_size);
}

template <typename T>
bool DS::Vector<T>::operator>=(const Vector<T>& other) const
{
    return (this -> m_size >= other.m_size);
}

template <typename T>
T& DS::Vector<T>::operator[](std::size_t pos)
{
    return this -> m_array[pos];
}

template <typename T>
const T& DS::Vector<T>::operator[](std::size_t pos) const
{
    return this -> m_array[pos];
}

template <typename T>
T& DS::Vector<T>::at(int pos)
{
    if ((pos < 0) || (pos >= this -> m_size))
        throw std::out_of_range("Index out of range");

    return this -> m_array[pos];
}

template <typename T>
const T& DS::Vector<T>::at(int pos) const
{
    if ((pos < 0) || (pos >= this -> m_size))
        throw std::out_of_range("Index out of range");

    return this -> m_array[pos];
}

template <typename T>
T& DS::Vector<T>::front()
{
    return this -> m_array[this -> m_size - this -> m_size];
}

template <typename T>
const T& DS::Vector<T>::front() const
{
    return this -> m_array[this -> m_size - this -> m_size];
}

template <typename T>
T& DS::Vector<T>::back()
{
    return this -> m_array[this -> m_size - 1];
}

template <typename T>
const T& DS::Vector<T>::back() const
{
    return this -> m_array[this -> m_size - 1];
}

template <typename T>
T* DS::Vector<T>::data() noexcept
{
    return this -> m_array;
}

template <typename T>
const T* DS::Vector<T>::data() const noexcept
{
    return this -> m_array;
}

template <typename T>
bool DS::Vector<T>::empty() const noexcept
{
    return !(this -> m_size);
}

template <typename T>
std::size_t DS::Vector<T>::size() const noexcept
{
    return this -> m_size;
}

template <typename T>
std::size_t DS::Vector<T>::max_size() const noexcept
{
    std::size_t max = -1;

    return max;
}

template <typename T>
void DS::Vector<T>::reserve(std::size_t new_cap)
{
    this -> m_capacity += new_cap;
    T* temp = new T[this -> m_capacity];

    for (std::size_t i = 0; i < this -> m_size; ++i)
        temp[i] = this -> m_array[i];

    if (this -> m_array)
        delete [] this -> m_array;

    this -> m_array = temp;
}

template <typename T>
std::size_t DS::Vector<T>::capacity() const noexcept
{
    return this -> m_capacity;
}

template <typename T>
void DS::Vector<T>::shrink_to_fit() noexcept
{
    if (this -> m_size == this -> m_capacity)
        return;

    if (!(this -> m_size) && this -> m_capacity)
    {
        delete [] this -> m_array;
        this -> m_array = nullptr;
        this -> m_capacity = this -> m_size;
        return;
    }

    T* temp = new T[this -> m_size];

    for (std::size_t i = 0; i < this -> m_size; ++i)
        temp[i] = this -> m_array[i];

    delete [] this -> m_array;
    this -> m_array = temp;
    this -> m_capacity = this -> m_size;
}

template <typename T>
void DS::Vector<T>::clear() noexcept
{
    this -> m_size = 0;
}

template <typename T>
void DS::Vector<T>::push_back(const T& value)
{
    if (!(this -> m_array))
    {
        this -> m_capacity = 50;
        this -> m_array = new T[this -> m_capacity];
    }

    if (this -> m_size == this -> m_capacity)
    {
        this -> m_capacity *= 2;
        T* temp = new T[this -> m_capacity];

        for (std::size_t i = 0; i < this -> m_size; ++i)
            temp[i] = this -> m_array[i];

        delete [] this -> m_array;
        this -> m_array = temp;
    }

    this -> m_array[(this -> m_size)++] = value;
}

template <typename T>
void DS::Vector<T>::push_back(T&& value)
{
    if (!(this -> m_array))
    {
        this -> m_capacity = 50;
        this -> m_array = new T[this -> m_capacity];
    }

    if (this -> m_size == this -> m_capacity)
    {
        this -> m_capacity *= 2;
        T* temp = new T[this -> m_capacity];

        for (std::size_t i = 0; i < this -> m_size; ++i)
            temp[i] = this -> m_array[i];

        delete [] this -> m_array;
        this -> m_array = temp;
    }
    
    this -> m_array[(this -> m_size)++] = value;
}

template <typename T>
void DS::Vector<T>::pop_back()
{
    if (this -> m_size)
        --(this -> m_size);
}

template <typename T>
void DS::Vector<T>::resize(std::size_t count)
{
    if (!count)
        return;

    if (this -> m_size > count)
    {
        for (std::size_t i = 0; i < (this -> m_size) - count; ++i)
            DS::Vector<T>::pop_back();

        return;
    }

    for (std::size_t i = 0; i < count - (this -> m_size); ++i)
        DS::Vector<T>::push_back(T{});
}

template <typename T>
void DS::Vector<T>::resize(std::size_t count, const T& value)
{
    if (!count)
        return;

    if (this -> m_size > count)
    {
        for (std::size_t i = 0; i < (this -> m_size) - count; ++i)
            DS::Vector<T>::pop_back();

        return;
    }

    for (std::size_t i = 0; i < count - (this -> m_size); ++i)
        DS::Vector<T>::push_back(value);
}

template <typename T>
void DS::Vector<T>::swap(Vector& other)
{
    if (this == &other)
        return;

    std::size_t tempSize = this -> m_size;
    std::size_t tempCapacity = this -> m_capacity;
    T* tempArray = this -> m_array;

    this -> m_size = other.m_size;
    this -> m_capacity = other.m_capacity;
    this -> m_array = other.m_array;

    other.m_size = tempSize;
    other.m_capacity = tempCapacity;
    other.m_array = tempArray;
}