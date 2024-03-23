#include "../header/vector.h"

#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <unistd.h> 

template <typename T>
DS::Vector<T>::Base_Iterator::Base_Iterator(T* p)
            : ptr(p)
{

}

template <typename T>
DS::Vector<T>::Base_Iterator::~Base_Iterator()
{
    this -> ptr = nullptr;
}

template <typename T>
bool DS::Vector<T>::Base_Iterator::operator<(const DS::Vector<T>::Base_Iterator& rhv) const
{
    return ((this -> ptr) < (rhv.ptr));
}

template <typename T>
bool DS::Vector<T>::Base_Iterator::operator>(const DS::Vector<T>::Base_Iterator& rhv) const
{
    return ((this -> ptr) > (rhv.ptr));
}

template <typename T>
bool DS::Vector<T>::Base_Iterator::operator<=(const DS::Vector<T>::Base_Iterator& rhv) const
{
    return ((this -> ptr) <= (rhv.ptr));
}

template <typename T>
bool DS::Vector<T>::Base_Iterator::operator>=(const DS::Vector<T>::Base_Iterator& rhv) const
{
    return ((this -> ptr) >= (rhv.ptr));
}

template <typename T>
bool DS::Vector<T>::Base_Iterator::operator==(const DS::Vector<T>::Base_Iterator& rhv) const
{
    return ((this -> ptr) == (rhv.ptr));
}

template <typename T>
bool DS::Vector<T>::Base_Iterator::operator!=(const DS::Vector<T>::Base_Iterator& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
const typename DS::Vector<T>::Base_Iterator& DS::Vector<T>::Base_Iterator::operator=(const DS::Vector<T>::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;
    
    return *this;
} 

template <typename T>
const typename DS::Vector<T>::Base_Iterator& DS::Vector<T>::Base_Iterator::operator=(DS::Vector<T>::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;

    return *this;
}

template <typename T>
DS::Vector<T>::Const_Iterator::Const_Iterator(T* p)
            : DS::Vector<T>::Base_Iterator(p)
{

}

template <typename T>
DS::Vector<T>::Const_Iterator::Const_Iterator()
            : DS::Vector<T>::Base_Iterator(nullptr)
{

}

template <typename T>
DS::Vector<T>::Const_Iterator::Const_Iterator(const DS::Vector<T>::Base_Iterator& rhv)
            : DS::Vector<T>::Base_Iterator(rhv.ptr)
{

}

template <typename T>
DS::Vector<T>::Const_Iterator::Const_Iterator(DS::Vector<T>::Base_Iterator&& rhv)
            : DS::Vector<T>::Base_Iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename DS::Vector<T>::Const_Iterator& DS::Vector<T>::Const_Iterator::operator=(const DS::Vector<T>::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;

    return *this;
}

template <typename T>
const typename DS::Vector<T>::Const_Iterator& DS::Vector<T>::Const_Iterator::operator=(DS::Vector<T>::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;

    return *this;
}

template <typename T>
const T& DS::Vector<T>::Const_Iterator::operator*()
{
    return *(this -> ptr);
}

template <typename T>
const T* DS::Vector<T>::Const_Iterator::operator->()
{
    return this -> ptr;
}

template <typename T>
const  typename DS::Vector<T>::Const_Iterator& DS::Vector<T>::Const_Iterator::operator++()
{
    ++(this -> ptr);

    return *this;
}

template <typename T>
const typename DS::Vector<T>::Const_Iterator& DS::Vector<T>::Const_Iterator::operator++(int)
{
    const DS::Vector<T>::Const_Iterator& temp = *this;
    ++(this -> ptr);

    return temp;
}

template <typename T>
const typename DS::Vector<T>::Const_Iterator& DS::Vector<T>::Const_Iterator::operator--()
{
    --(this -> ptr);

    return *this;
}

template <typename T>
const typename DS::Vector<T>::Const_Iterator& DS::Vector<T>::Const_Iterator::operator--(int)
{
    const DS::Vector<T>::Const_Iterator& temp = *this;
    --(this -> ptr);

    return temp;
}

template <typename T>
const typename DS::Vector<T>::Const_Iterator DS::Vector<T>::Const_Iterator::operator+(long long int arg) const
{
    return DS::Vector<T>::Const_Iterator((this -> ptr) + arg);
}

template <typename T>
const typename DS::Vector<T>::Const_Iterator DS::Vector<T>::Const_Iterator::operator-(long long int arg) const
{
    return DS::Vector<T>::Const_Iterator((this -> ptr) - arg);
}

template <typename T>
const typename DS::Vector<T>::Const_Iterator& DS::Vector<T>::Const_Iterator::operator+=(long long int arg)
{
    this -> ptr += arg;

    return *this;
}

template <typename T>
const typename DS::Vector<T>::Const_Iterator& DS::Vector<T>::Const_Iterator::operator-=(long long int arg)
{
    this -> ptr -= arg;

    return *this;
}

template <typename T>
const T& DS::Vector<T>::Const_Iterator::operator[](std::size_t index) const
{
    return this -> ptr[index];
}

template <typename T>
DS::Vector<T>::Iterator::Iterator()
            : DS::Vector<T>::Const_Iterator(nullptr)
{

}

template <typename T>
DS::Vector<T>::Iterator::Iterator(const DS::Vector<T>::Base_Iterator& rhv)
            : DS::Vector<T>::Const_Iterator(rhv.ptr)
{

}

template <typename T>
DS::Vector<T>::Iterator::Iterator(DS::Vector<T>::Base_Iterator&& rhv)
            : DS::Vector<T>::Const_Iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

template <typename T>
DS::Vector<T>::Iterator::Iterator(T* p)
            : DS::Vector<T>::Const_Iterator(p)
{

}

template <typename T>
const typename DS::Vector<T>::Iterator& DS::Vector<T>::Iterator::operator=(const DS::Vector<T>::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;

    return *this;
}

template <typename T>
const typename DS::Vector<T>::Iterator& DS::Vector<T>::Iterator::operator=(DS::Vector<T>::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;

    return *this;
}

template <typename T>
T& DS::Vector<T>::Iterator::operator*()
{
    return *(this -> ptr);
}

template <typename T>
T* DS::Vector<T>::Iterator::operator->()
{
    return this -> ptr;
}

template <typename T>
typename DS::Vector<T>::Iterator& DS::Vector<T>::Iterator::operator++()
{
    ++(this -> ptr);

    return *this;
}

template <typename T>
typename DS::Vector<T>::Iterator& DS::Vector<T>::Iterator::operator++(int)
{
    DS::Vector<T>::Iterator& temp = *this;
    ++(this -> ptr);

    return temp;
}

template <typename T>
typename DS::Vector<T>::Iterator& DS::Vector<T>::Iterator::operator--()
{
    --(this -> ptr);

    return *this;
}

template <typename T>
typename DS::Vector<T>::Iterator& DS::Vector<T>::Iterator::operator--(int)
{
    DS::Vector<T>::Iterator& temp = *this;
    --(this -> ptr);

    return temp;
}

template <typename T>
typename DS::Vector<T>::Iterator DS::Vector<T>::Iterator::operator+(long long int arg) const
{   
    return DS::Vector<T>::Iterator((this -> ptr) + arg);
}

template <typename T>
typename DS::Vector<T>::Iterator DS::Vector<T>::Iterator::operator-(long long int arg) const
{
    return DS::Vector<T>::Iterator((this -> ptr) - arg);
}

template <typename T>
typename DS::Vector<T>::Iterator& DS::Vector<T>::Iterator::operator+=(long long int arg)
{
    this -> ptr += arg;

    return *this;
}

template <typename T>
typename DS::Vector<T>::Iterator& DS::Vector<T>::Iterator::operator-=(long long int arg)
{
    this -> ptr -= arg;

    return *this;
}

template <typename T>
T& DS::Vector<T>::Iterator::operator[](std::size_t index)
{
    return this -> ptr[index];
}

template <typename T>
DS::Vector<T>::Const_Reverse_Iterator::Const_Reverse_Iterator(T* p)
                    : DS::Vector<T>::Base_Iterator(p)
{

}

template <typename T>
DS::Vector<T>::Const_Reverse_Iterator::Const_Reverse_Iterator()
                    : DS::Vector<T>::Base_Iterator(nullptr)
{

}

template <typename T>
DS::Vector<T>::Const_Reverse_Iterator::Const_Reverse_Iterator(const DS::Vector<T>::Base_Iterator& rhv)
                    : DS::Vector<T>::Base_Iterator(rhv.ptr)
{

}

template <typename T>
DS::Vector<T>::Const_Reverse_Iterator::Const_Reverse_Iterator(DS::Vector<T>::Base_Iterator&& rhv)
                    : DS::Vector<T>::Base_Iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename DS::Vector<T>::Const_Reverse_Iterator& DS::Vector<T>::Const_Reverse_Iterator::operator=(const DS::Vector<T>::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;

    return *this;
}

template <typename T>
const typename DS::Vector<T>::Const_Reverse_Iterator& DS::Vector<T>::Const_Reverse_Iterator::operator=(DS::Vector<T>::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;

    return *this;
}

template <typename T>
const T& DS::Vector<T>::Const_Reverse_Iterator::operator*()
{
    return *(this -> ptr);
}

template <typename T>
const T* DS::Vector<T>::Const_Reverse_Iterator::operator->()
{
    return this -> ptr;
}

template <typename T>
const typename DS::Vector<T>::Const_Reverse_Iterator& DS::Vector<T>::Const_Reverse_Iterator::operator++()
{
    --(this -> ptr);

    return *this;
}

template <typename T>
const typename DS::Vector<T>::Const_Reverse_Iterator& DS::Vector<T>::Const_Reverse_Iterator::operator++(int)
{
    DS::Vector<T>::Const_Reverse_Iterator& temp = *this;
    --(this -> ptr);

    return temp;
}

template <typename T>
const typename DS::Vector<T>::Const_Reverse_Iterator& DS::Vector<T>::Const_Reverse_Iterator::operator--()
{
    ++(this -> ptr);

    return *this;
}

template <typename T>
const typename DS::Vector<T>::Const_Reverse_Iterator& DS::Vector<T>::Const_Reverse_Iterator::operator--(int)
{
    const DS::Vector<T>::Const_Reverse_Iterator& temp = *this;
    ++(this -> ptr);

    return temp;
}

template <typename T>
const typename DS::Vector<T>::Const_Reverse_Iterator DS::Vector<T>::Const_Reverse_Iterator::operator+(long long int arg) const
{
    return DS::Vector<T>::Const_Reverse_Iterator((this -> ptr) - arg);
}

template <typename T>
const typename DS::Vector<T>::Const_Reverse_Iterator DS::Vector<T>::Const_Reverse_Iterator::operator-(long long int arg) const
{
    return DS::Vector<T>::Const_Reverse_Iterator((this -> ptr) + arg);
}

template <typename T>
const typename DS::Vector<T>::Const_Reverse_Iterator& DS::Vector<T>::Const_Reverse_Iterator::operator+=(long long int arg)
{
    this -> ptr -= arg;

    return *this;
}

template <typename T>
const typename DS::Vector<T>::Const_Reverse_Iterator& DS::Vector<T>::Const_Reverse_Iterator::operator-=(long long int arg)
{
    this -> ptr += arg;

    return *this;
}

template <typename T>
const T& DS::Vector<T>::Const_Reverse_Iterator::operator[](std::size_t index) const
{
    return *(this -> ptr - index);
}

template <typename T>
DS::Vector<T>::Reverse_Iterator::Reverse_Iterator(T* p)
                    : DS::Vector<T>::Const_Reverse_Iterator(p)
{

}

template <typename T>
DS::Vector<T>::Reverse_Iterator::Reverse_Iterator()
                    : DS::Vector<T>::Const_Reverse_Iterator(nullptr)
{

}

template <typename T>
DS::Vector<T>::Reverse_Iterator::Reverse_Iterator(const DS::Vector<T>::Base_Iterator& rhv)
                    : DS::Vector<T>::Const_Reverse_Iterator(rhv.ptr)
{

}

template <typename T>
DS::Vector<T>::Reverse_Iterator::Reverse_Iterator(DS::Vector<T>::Base_Iterator&& rhv)
                    : DS::Vector<T>::Const_Reverse_Iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename DS::Vector<T>::Reverse_Iterator& DS::Vector<T>::Reverse_Iterator::operator=(const DS::Vector<T>::Base_Iterator& rhv)
{
    this -> ptr = rhv.ptr;

    return *this;
}

template <typename T>
const typename DS::Vector<T>::Reverse_Iterator& DS::Vector<T>::Reverse_Iterator::operator=(DS::Vector<T>::Base_Iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;

    return *this;
}

template <typename T>
T& DS::Vector<T>::Reverse_Iterator::operator*()
{
    return *(this -> ptr);
}

template <typename T>
T* DS::Vector<T>::Reverse_Iterator::operator->()
{
    return this -> ptr;
}

template <typename T>
typename DS::Vector<T>::Reverse_Iterator& DS::Vector<T>::Reverse_Iterator::operator++()
{
    --(this -> ptr);

    return *this;
}

template <typename T>
typename DS::Vector<T>::Reverse_Iterator& DS::Vector<T>::Reverse_Iterator::operator++(int)
{
    DS::Vector<T>::Reverse_Iterator& temp = *this;
    --(this -> ptr);

    return temp;
}

template <typename T>
typename DS::Vector<T>::Reverse_Iterator& DS::Vector<T>::Reverse_Iterator::operator--()
{
    ++(this -> ptr);

    return *this;
}

template <typename T>
typename DS::Vector<T>::Reverse_Iterator& DS::Vector<T>::Reverse_Iterator::operator--(int)
{
    DS::Vector<T>::Reverse_Iterator& temp = *this;
    ++(this -> ptr);

    return temp;
}

template <typename T>
typename DS::Vector<T>::Reverse_Iterator DS::Vector<T>::Reverse_Iterator::operator+(long long int arg) const
{
    return DS::Vector<T>::Const_Reverse_Iterator((this -> ptr) - arg);
}

template <typename T>
typename DS::Vector<T>::Reverse_Iterator DS::Vector<T>::Reverse_Iterator::operator-(long long int arg) const
{
    return DS::Vector<T>::Const_Reverse_Iterator((this -> ptr) + arg);
}

template <typename T>
typename DS::Vector<T>::Reverse_Iterator& DS::Vector<T>::Reverse_Iterator::operator+=(long long int arg)
{
    this -> ptr -= arg;

    return *this;
}

template <typename T>
typename DS::Vector<T>::Reverse_Iterator& DS::Vector<T>::Reverse_Iterator::operator-=(long long int arg)
{
    this -> ptr += arg;

    return *this;
}

template <typename T>
T& DS::Vector<T>::Reverse_Iterator::operator[](std::size_t index)
{
    return *(this -> ptr - index);
}

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
DS::Vector<T>::Vector(std::size_t count)
{
    this -> m_size = count;
    this -> m_capacity = this -> m_size;
    this -> m_array = new T[this -> m_capacity];

    for (std::size_t i = 0; i < this -> m_size; ++i)
        this -> m_array[i] = T{};
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
    if (m_array)
        delete [] m_array;

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
    if (this == &other)
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
    if (this -> m_size != other.m_size)
        return false;

    for (std::size_t i = 0; i < this -> m_size; ++i)
        if (this -> m_array[i] != other.m_array[i])
            return false;

    return true;
}

template <typename T>
bool DS::Vector<T>::operator!=(const Vector<T>& other) const
{
    if (this -> m_size != other.m_size)
        return true;

    for (std::size_t i = 0; i < this -> m_size; ++i)
        if (this -> m_array[i] != other.m_array[i])
            return true;

    return false;
}

template <typename T>
bool DS::Vector<T>::operator<(const Vector<T>& other) const
{
    if (this -> m_size > other.m_size)
        return false;

    for (std::size_t i = 0; i < other.m_size; ++i)
        if (this -> m_array[i] < other.m_array[i])
            return true;

    return false;
}

template <typename T>
bool DS::Vector<T>::operator<=(const Vector<T>& other) const
{
    if (this -> m_size > other.m_size)
        return false;

    for (std::size_t i = 0; i < this -> m_size; ++i)
        if (this -> m_array[i] > other.m_array[i])
            return false;
    
    return true;
}

template <typename T>
bool DS::Vector<T>::operator>(const Vector<T>& other) const
{
    if (this -> m_size > other.m_size)
        return true;

    for (std::size_t i = 0; i < this -> m_size; ++i)
        if (this -> m_array[i] < other.m_array[i])
            return false;

    return true;

}

template <typename T>
bool DS::Vector<T>::operator>=(const Vector<T>& other) const
{
    if (this -> m_size > other.m_size)
        return true;

    for (std::size_t i = 0; i < this -> m_size; ++i)
        if (this -> m_array[i] < other.m_array[i])
            return false;

    return true;
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
    std::size_t elem_size = sizeof(T);
    std::size_t max_bytes, max_elements;

    max_bytes = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE);
    max_elements = max_bytes / elem_size;

    return max_elements;
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

template <typename T>
typename DS::Vector<T>::Iterator DS::Vector<T>::begin() noexcept
{
    return DS::Vector<T>::Iterator(this -> m_array);
}

template <typename T>
typename DS::Vector<T>::Const_Iterator DS::Vector<T>::cbegin() const noexcept
{
    return DS::Vector<T>::Const_Iterator(this -> m_array);
}

template <typename T>
typename DS::Vector<T>::Iterator DS::Vector<T>::end() noexcept
{
    return DS::Vector<T>::Iterator(this -> m_array + DS::Vector<T>::size());
}

template <typename T>
typename DS::Vector<T>::Const_Iterator DS::Vector<T>::cend() const noexcept
{
    return DS::Vector<T>::Const_Iterator(this -> m_array + DS::Vector<T>::size());
}

template <typename T>
typename DS::Vector<T>::Reverse_Iterator DS::Vector<T>::rbegin() noexcept
{
    return DS::Vector<T>::Reverse_Iterator(this -> m_array + DS::Vector<T>::size() - 1);
}

template <typename T>
typename DS::Vector<T>::Const_Reverse_Iterator DS::Vector<T>::crbegin() const noexcept
{
    return DS::Vector<T>::Const_Reverse_Iterator(this -> m_array + DS::Vector<T>::size() - 1);
}

template <typename T>
typename DS::Vector<T>::Reverse_Iterator DS::Vector<T>::rend() noexcept
{
    return DS::Vector<T>::Reverse_Iterator(this -> m_array - 1);
}

template <typename T>
typename DS::Vector<T>::Const_Reverse_Iterator DS::Vector<T>::crend() const noexcept
{
    return DS::Vector<T>::Const_Reverse_Iterator(this -> m_array - 1);
}

template <typename T>
typename DS::Vector<T>::Iterator DS::Vector<T>::insert(const DS::Vector<T>::Base_Iterator& pos, const T& value)
{
    std::size_t index = pos.ptr - m_array;

    if (index < 0 || index >= DS::Vector<T>::size())
        throw std::out_of_range("Invalid address");

    if (m_size == m_capacity)
        DS::Vector<T>::reserve(m_capacity * 2);

    for (std::size_t i = m_size; i > index; --i)
        m_array[i] = std::move(m_array[i - 1]);

    m_array[index] = value;
    ++m_size;

    return DS::Vector<T>::Iterator(m_array + index);
}

template <typename T>
typename DS::Vector<T>::Iterator DS::Vector<T>::insert(const DS::Vector<T>::Base_Iterator& pos, int count, const T& value)
{
    std::size_t index = pos.ptr - m_array;

    if (index < 0 || index >= DS::Vector<T>::size())
        throw std::out_of_range("Invalid address");

    std::size_t oldSize = m_size;

    m_size += count;

    if (m_size > m_capacity)
        DS::Vector<T>::reserve(m_size * 2);

    for (std::size_t i = oldSize + count - 1; i >= index + count; --i)
        m_array[i] = std::move(m_array[i - count]);

    for (std::size_t i = index; i < index + count; ++i)
        m_array[i] = value;

    return DS::Vector<T>::Iterator(m_array + index);
}

template <typename T>
typename DS::Vector<T>::Iterator DS::Vector<T>::insert(const DS::Vector<T>::Base_Iterator& pos, const Base_Iterator& first, const Base_Iterator& last)
{
    std::size_t index = pos.ptr - m_array;

    std::size_t count = last.ptr - first.ptr + 1;

    if (m_size + count > m_capacity)
        DS::Vector<T>::reserve(m_size + count);

    for (std::size_t i = m_size + count - 1; i >= index + count; --i)
        m_array[i] = std::move(m_array[i - count]);

    std::size_t i = index;

    for (Base_Iterator it = first; it != last; ++it)
        m_array[i++] = *it;

    m_size += count;

    return DS::Vector<T>::Iterator(m_array + index);
}

template <typename T>
typename DS::Vector<T>::Iterator DS::Vector<T>::insert(const DS::Vector<T>::Base_Iterator& pos, std::initializer_list<T> list)
{
    std::size_t index = pos.ptr - m_array;
    std::size_t count = list.size();
    std::size_t oldSize = m_size;

    m_size += count;
    if (m_size > m_capacity)
        DS::Vector<T>::reserve(m_size * 2);

    for (std::size_t i = oldSize + count - 1; i >= index + count; --i)
        m_array[i] = std::move(m_array[i - count]);

    for (const auto& elem : list)
        m_array[index++] = elem;

    return DS::Vector<T>::Iterator(m_array + index - count);
}

template <typename T>
typename DS::Vector<T>::Iterator DS::Vector<T>::erase(const DS::Vector<T>::Base_Iterator& pos)
{
    std::size_t index = pos.ptr - m_array;

    for (std::size_t i = index; i < m_size - 1; ++i)
        m_array[i] = std::move(m_array[i + 1]);

    --m_size;

    return DS::Vector<T>::Iterator(m_array + index);
}

template <typename T>
typename DS::Vector<T>::Iterator DS::Vector<T>::erase(const DS::Vector<T>::Base_Iterator& first, const DS::Vector<T>::Base_Iterator& last)
{
    std::size_t firstIndex = first.ptr - m_array;
    std::size_t lastIndex = last.ptr - m_array;

    std::size_t shift = lastIndex - firstIndex + 1;

    for (std::size_t i = firstIndex; i < m_size - shift; ++i)
        m_array[i] = std::move(m_array[i + shift]);

    m_size -= shift;

    return DS::Vector<T>::Iterator(m_array + firstIndex);
}