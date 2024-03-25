#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <unistd.h>
#include "./allocator.h"
#include "../header/string.h"

DS::String::Base_Iterator::Base_Iterator(char* p)
            : ptr(p)
{

}

DS::String::Base_Iterator::~Base_Iterator()
{
    this -> ptr = nullptr;
}

bool DS::String::Base_Iterator::operator<(const DS::String::Base_Iterator& rhv) const
{
    return ((this -> ptr) < (rhv.ptr));
}

bool DS::String::Base_Iterator::operator>(const DS::String::Base_Iterator& rhv) const
{
    return ((this -> ptr) > (rhv.ptr));
}

bool DS::String::Base_Iterator::operator<=(const DS::String::Base_Iterator& rhv) const
{
    return ((this -> ptr) <= (rhv.ptr));
}

bool DS::String::Base_Iterator::operator>=(const DS::String::Base_Iterator& rhv) const
{
    return ((this -> ptr) >= (rhv.ptr));
}

bool DS::String::Base_Iterator::operator==(const DS::String::Base_Iterator& rhv) const
{
    return ((this -> ptr) == (rhv.ptr));
}

bool DS::String::Base_Iterator::operator!=(const DS::String::Base_Iterator& rhv) const
{
    return !(*this == rhv);
}

const typename DS::String::Base_Iterator& DS::String::Base_Iterator::operator=(const DS::String::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;
    
    return *this;
} 

const typename DS::String::Base_Iterator& DS::String::Base_Iterator::operator=(DS::String::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;

    return *this;
}

DS::String::Const_Iterator::Const_Iterator(char* p)
            : DS::String::Base_Iterator(p)
{

}

DS::String::Const_Iterator::Const_Iterator()
            : DS::String::Base_Iterator(nullptr)
{

}

DS::String::Const_Iterator::Const_Iterator(const DS::String::Base_Iterator& rhv)
            : DS::String::Base_Iterator(rhv.ptr)
{

}

DS::String::Const_Iterator::Const_Iterator(DS::String::Base_Iterator&& rhv)
            : DS::String::Base_Iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

const typename DS::String::Const_Iterator& DS::String::Const_Iterator::operator=(const DS::String::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;

    return *this;
}

const typename DS::String::Const_Iterator& DS::String::Const_Iterator::operator=(DS::String::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;

    return *this;
}

const char& DS::String::Const_Iterator::operator*()
{
    return *(this -> ptr);
}

const char* DS::String::Const_Iterator::operator->()
{
    return this -> ptr;
}

const  typename DS::String::Const_Iterator& DS::String::Const_Iterator::operator++()
{
    ++(this -> ptr);

    return *this;
}

const typename DS::String::Const_Iterator& DS::String::Const_Iterator::operator++(int)
{
    const DS::String::Const_Iterator& temp = *this;
    ++(this -> ptr);

    return temp;
}

const typename DS::String::Const_Iterator& DS::String::Const_Iterator::operator--()
{
    --(this -> ptr);

    return *this;
}

const typename DS::String::Const_Iterator& DS::String::Const_Iterator::operator--(int)
{
    const DS::String::Const_Iterator& temp = *this;
    --(this -> ptr);

    return temp;
}

const typename DS::String::Const_Iterator DS::String::Const_Iterator::operator+(long long int arg) const
{
    return DS::String::Const_Iterator((this -> ptr) + arg);
}

const typename DS::String::Const_Iterator DS::String::Const_Iterator::operator-(long long int arg) const
{
    return DS::String::Const_Iterator((this -> ptr) - arg);
}

const typename DS::String::Const_Iterator& DS::String::Const_Iterator::operator+=(long long int arg)
{
    this -> ptr += arg;

    return *this;
}

const typename DS::String::Const_Iterator& DS::String::Const_Iterator::operator-=(long long int arg)
{
    this -> ptr -= arg;

    return *this;
}

const char& DS::String::Const_Iterator::operator[](std::size_t index) const
{
    return this -> ptr[index];
}

DS::String::Iterator::Iterator()
            : DS::String::Const_Iterator(nullptr)
{

}

DS::String::Iterator::Iterator(const DS::String::Base_Iterator& rhv)
            : DS::String::Const_Iterator(rhv.ptr)
{

}

DS::String::Iterator::Iterator(DS::String::Base_Iterator&& rhv)
            : DS::String::Const_Iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

DS::String::Iterator::Iterator(char* p)
            : DS::String::Const_Iterator(p)
{

}

const typename DS::String::Iterator& DS::String::Iterator::operator=(const DS::String::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;

    return *this;
}

const typename DS::String::Iterator& DS::String::Iterator::operator=(DS::String::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;

    return *this;
}

char& DS::String::Iterator::operator*()
{
    return *(this -> ptr);
}

char* DS::String::Iterator::operator->()
{
    return this -> ptr;
}

typename DS::String::Iterator& DS::String::Iterator::operator++()
{
    ++(this -> ptr);

    return *this;
}

typename DS::String::Iterator& DS::String::Iterator::operator++(int)
{
    DS::String::Iterator& temp = *this;
    ++(this -> ptr);

    return temp;
}

typename DS::String::Iterator& DS::String::Iterator::operator--()
{
    --(this -> ptr);

    return *this;
}

typename DS::String::Iterator& DS::String::Iterator::operator--(int)
{
    DS::String::Iterator& temp = *this;
    --(this -> ptr);

    return temp;
}

typename DS::String::Iterator DS::String::Iterator::operator+(long long int arg) const
{   
    return DS::String::Iterator((this -> ptr) + arg);
}

typename DS::String::Iterator DS::String::Iterator::operator-(long long int arg) const
{
    return DS::String::Iterator((this -> ptr) - arg);
}

typename DS::String::Iterator& DS::String::Iterator::operator+=(long long int arg)
{
    this -> ptr += arg;

    return *this;
}

typename DS::String::Iterator& DS::String::Iterator::operator-=(long long int arg)
{
    this -> ptr -= arg;

    return *this;
}

char& DS::String::Iterator::operator[](std::size_t index)
{
    return this -> ptr[index];
}

DS::String::Const_Reverse_Iterator::Const_Reverse_Iterator(char* p)
                    : DS::String::Base_Iterator(p)
{

}

DS::String::Const_Reverse_Iterator::Const_Reverse_Iterator()
                    : DS::String::Base_Iterator(nullptr)
{

}

DS::String::Const_Reverse_Iterator::Const_Reverse_Iterator(const DS::String::Base_Iterator& rhv)
                    : DS::String::Base_Iterator(rhv.ptr)
{

}

DS::String::Const_Reverse_Iterator::Const_Reverse_Iterator(DS::String::Base_Iterator&& rhv)
                    : DS::String::Base_Iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

const typename DS::String::Const_Reverse_Iterator& DS::String::Const_Reverse_Iterator::operator=(const DS::String::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;

    return *this;
}

const typename DS::String::Const_Reverse_Iterator& DS::String::Const_Reverse_Iterator::operator=(DS::String::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;

    return *this;
}

const char& DS::String::Const_Reverse_Iterator::operator*()
{
    return *(this -> ptr);
}

const char* DS::String::Const_Reverse_Iterator::operator->()
{
    return this -> ptr;
}

const typename DS::String::Const_Reverse_Iterator& DS::String::Const_Reverse_Iterator::operator++()
{
    --(this -> ptr);

    return *this;
}

const typename DS::String::Const_Reverse_Iterator& DS::String::Const_Reverse_Iterator::operator++(int)
{
    DS::String::Const_Reverse_Iterator& temp = *this;
    --(this -> ptr);

    return temp;
}

const typename DS::String::Const_Reverse_Iterator& DS::String::Const_Reverse_Iterator::operator--()
{
    ++(this -> ptr);

    return *this;
}

const typename DS::String::Const_Reverse_Iterator& DS::String::Const_Reverse_Iterator::operator--(int)
{
    const DS::String::Const_Reverse_Iterator& temp = *this;
    ++(this -> ptr);

    return temp;
}

const typename DS::String::Const_Reverse_Iterator DS::String::Const_Reverse_Iterator::operator+(long long int arg) const
{
    return DS::String::Const_Reverse_Iterator((this -> ptr) - arg);
}

const typename DS::String::Const_Reverse_Iterator DS::String::Const_Reverse_Iterator::operator-(long long int arg) const
{
    return DS::String::Const_Reverse_Iterator((this -> ptr) + arg);
}

const typename DS::String::Const_Reverse_Iterator& DS::String::Const_Reverse_Iterator::operator+=(long long int arg)
{
    this -> ptr -= arg;

    return *this;
}

const typename DS::String::Const_Reverse_Iterator& DS::String::Const_Reverse_Iterator::operator-=(long long int arg)
{
    this -> ptr += arg;

    return *this;
}

const char& DS::String::Const_Reverse_Iterator::operator[](std::size_t index) const
{
    return *(this -> ptr - index);
}

DS::String::Reverse_Iterator::Reverse_Iterator(char* p)
                    : DS::String::Const_Reverse_Iterator(p)
{

}

DS::String::Reverse_Iterator::Reverse_Iterator()
                    : DS::String::Const_Reverse_Iterator(nullptr)
{

}

DS::String::Reverse_Iterator::Reverse_Iterator(const DS::String::Base_Iterator& rhv)
                    : DS::String::Const_Reverse_Iterator(rhv.ptr)
{

}

DS::String::Reverse_Iterator::Reverse_Iterator(DS::String::Base_Iterator&& rhv)
                    : DS::String::Const_Reverse_Iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

const typename DS::String::Reverse_Iterator& DS::String::Reverse_Iterator::operator=(const DS::String::Base_Iterator& rhv)
{
    this -> ptr = rhv.ptr;

    return *this;
}

const typename DS::String::Reverse_Iterator& DS::String::Reverse_Iterator::operator=(DS::String::Base_Iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;

    return *this;
}

char& DS::String::Reverse_Iterator::operator*()
{
    return *(this -> ptr);
}

char* DS::String::Reverse_Iterator::operator->()
{
    return this -> ptr;
}

typename DS::String::Reverse_Iterator& DS::String::Reverse_Iterator::operator++()
{
    --(this -> ptr);

    return *this;
}

typename DS::String::Reverse_Iterator& DS::String::Reverse_Iterator::operator++(int)
{
    DS::String::Reverse_Iterator& temp = *this;
    --(this -> ptr);

    return temp;
}

typename DS::String::Reverse_Iterator& DS::String::Reverse_Iterator::operator--()
{
    ++(this -> ptr);

    return *this;
}

typename DS::String::Reverse_Iterator& DS::String::Reverse_Iterator::operator--(int)
{
    DS::String::Reverse_Iterator& temp = *this;
    ++(this -> ptr);

    return temp;
}

typename DS::String::Reverse_Iterator DS::String::Reverse_Iterator::operator+(long long int arg) const
{
    return DS::String::Const_Reverse_Iterator((this -> ptr) - arg);
}

typename DS::String::Reverse_Iterator DS::String::Reverse_Iterator::operator-(long long int arg) const
{
    return DS::String::Const_Reverse_Iterator((this -> ptr) + arg);
}

typename DS::String::Reverse_Iterator& DS::String::Reverse_Iterator::operator+=(long long int arg)
{
    this -> ptr -= arg;

    return *this;
}

typename DS::String::Reverse_Iterator& DS::String::Reverse_Iterator::operator-=(long long int arg)
{
    this -> ptr += arg;

    return *this;
}

char& DS::String::Reverse_Iterator::operator[](std::size_t index)
{
    return *(this -> ptr - index);
}

DS::String::String()
        : m_data(nullptr)
{

}

DS::String::String(const char* s)
{
    if (!(*s))
        throw std::invalid_argument("");
    
        std::size_t sSize = 0;
        // "Hello World!"
        while (s[sSize++]); // 0 - 11 // 12
    
        DS::Allocator<char> alloc;

        this -> m_data = alloc.allocate(sSize + 1);

        for (std::size_t i = 0; i < sSize; ++i)
            alloc.construct(&(this -> m_data[i]) , s[i]);

        alloc.construct(&(this -> m_data[sSize]) , '\0');   
}

DS::String::String(const DS::String& other)
{
    DS::Allocator<char> alloc;
    this -> m_data = alloc.allocate(other.size() + 1);

    for (std::size_t i = 0; i < other.size(); ++i)
        alloc.construct(&(this -> m_data[i]) ,other.m_data[i]);

    alloc.construct(&(this -> m_data[other.size()]) , '\0');
}

DS::String::String(DS::String&& other)
        : m_data(other.m_data)
{
    other.m_data = nullptr;
}

DS::String::String(std::initializer_list<char> list)
{
    DS::Allocator<char> alloc;

    if (!(list.size()))
    {
        this -> m_data = alloc.allocate(sizeof(char));
        alloc.construct(this -> m_data, '\0');
    }
    else
    {
        this -> m_data = alloc.allocate(list.size() + 1);
        std::size_t i = 0;

        for (auto it = list.begin() ; it < list.end(); ++it)
            alloc.construct(&(this -> m_data[i++]), *it);

        alloc.construct(&(this -> m_data[i]), '\0');
    }
}

DS::String::~String()
{
    if (this -> m_data)
    {
        DS::Allocator<char> alloc;

        for (std::size_t i = 0; i < this -> size(); ++i)
            alloc.destroy(&(this -> m_data[i]));

        alloc.deallocate(this -> m_data, this -> size());
    }

    this -> m_data = nullptr;
}

typename DS::String& DS::String::operator=(const DS::String& other)
{
    if (this == &other)
        return *this;

    DS::Allocator<char> alloc;

    if (this -> m_data)
    {
        for (std::size_t i = 0; i < this -> size(); ++i)
            alloc.destroy(this -> m_data + i);

        alloc.deallocate(this -> m_data, this -> size());

        this -> m_data = nullptr;    
    }

    this -> m_data = alloc.allocate(other.size() + 1);

    for (std::size_t i = 0; i < other.size(); ++i)
        alloc.construct(this -> m_data + i, other.m_data[i]);

    alloc.construct(this -> m_data + other.size(), '\0');

    return *this;   
}

typename DS::String& DS::String::operator=(DS::String&& other)
{
    if (this == &other)
        return *this;

    if (this -> m_data)
    {
        DS::Allocator<char> alloc;

        for (std::size_t i = 0; i < this -> size(); ++i)
            alloc.destroy(this -> m_data + i);

        alloc.deallocate(this -> m_data, this -> size());

        this -> m_data = nullptr;    
    }

    this -> m_data = other.m_data;
    other.m_data = nullptr;

    return *this;
}

typename DS::String& DS::String::operator=(std::initializer_list<char> list)
{

    DS::Allocator<char> alloc;

    for (std::size_t i = 0; i < this -> size(); ++i)
        alloc.destroy(this -> m_data + i);

    alloc.deallocate(this -> m_data, this -> size());

    this -> m_data = nullptr;

    if (!list.size())
    {
        this -> m_data = alloc.allocate(sizeof(char));
        alloc.construct(this -> m_data, '\0');
    }
    else
    {
        this -> m_data = alloc.allocate(list.size() + 1);

        std::size_t i = 0;

        for (auto it = list.begin(); it != list.end(); ++it)
            alloc.construct(this -> m_data + (i++), *it);

        alloc.construct(this -> m_data + list.size(), '\0');
    }

    return *this;
}

typename DS::String::Iterator DS::String::begin()
{
    return DS::String::Iterator(this -> m_data);
}

typename DS::String::Iterator DS::String::end()
{
    return DS::String::Iterator(this -> m_data + DS::String::size());
}

typename DS::String::Reverse_Iterator DS::String::rbegin()
{
    return DS::String::Reverse_Iterator(this -> m_data + DS::String::size() - 1);
}

typename DS::String::Reverse_Iterator DS::String::rend()
{
    return DS::String::Reverse_Iterator(this -> m_data - 1);
}

typename DS::String::Const_Iterator DS::String::cbegin() const
{
    return DS::String::Const_Iterator(this -> m_data);
}

typename DS::String::Const_Iterator DS::String::cend() const
{
    return DS::String::Const_Iterator(this -> m_data + DS::String::size());
}

typename DS::String::Const_Reverse_Iterator DS::String::crbegin() const
{
    return DS::String::Const_Reverse_Iterator(this -> m_data + DS::String::size() - 1);
}

typename DS::String::Const_Reverse_Iterator DS::String::crend() const
{
    return DS::String::Const_Reverse_Iterator(this -> m_data - 1);
}

std::size_t DS::String::size() const
{
    if (!(*(this -> m_data)))
        return 0;

    std::size_t strSize = 0;

    while (this -> m_data[strSize++]);

    return strSize - 1;
}