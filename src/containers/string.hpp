#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <unistd.h>
#include <string.h>
#include "../../header/allocator/allocator.h"
#include "../../header/containers/string.h"

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

typename DS::String::Const_Iterator DS::String::Const_Iterator::operator+(long long int arg) const
{
    return DS::String::Const_Iterator((this -> ptr) + arg);
}

typename DS::String::Const_Iterator DS::String::Const_Iterator::operator-(long long int arg) const
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

typename DS::String::Const_Reverse_Iterator DS::String::Const_Reverse_Iterator::operator+(long long int arg) const
{
    return DS::String::Const_Reverse_Iterator((this -> ptr) - arg);
}

typename DS::String::Const_Reverse_Iterator DS::String::Const_Reverse_Iterator::operator-(long long int arg) const
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
    if (!s || !(*s))
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

        alloc.deallocate(this -> m_data, 0);
    }

    this -> m_data = nullptr;
}

typename DS::String& DS::String::operator=(const char* other)
{
    if (!other || !(*other))
        throw std::invalid_argument("");

    if (this -> m_data == other)
        return *this;

    std::size_t sSize = 0;
    
    while (other[sSize++]);
    
    DS::Allocator<char> alloc;

    if (this -> m_data)
    {
        for (std::size_t i = 0; i < this -> size(); ++i)
            alloc.destroy(this -> m_data + i);

        alloc.deallocate(this -> m_data, 0);

        this -> m_data = nullptr;
    }

    this -> m_data = alloc.allocate(sSize + 1);

    for (std::size_t i = 0; i < sSize; ++i)
        alloc.construct(&(this -> m_data[i]) , other[i]);

    alloc.construct(&(this -> m_data[sSize]) , '\0');

    return *this;
}
// ----------------
typename DS::String& DS::String::operator=(const DS::String& other)
{
    if (this == &other)
        return *this;

    DS::Allocator<char> alloc;

    if (this -> m_data)
    {
        for (std::size_t i = 0; i < this -> size(); ++i)
            alloc.destroy(this -> m_data + i);

        alloc.deallocate(this -> m_data, 0);

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

        alloc.deallocate(this -> m_data, 0);

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

    alloc.deallocate(this -> m_data, 0);

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
    if (!(this -> m_data) || !(*(this -> m_data)))
        return 0;

    std::size_t strSize = 0;

    while (this -> m_data[strSize++]);

    return strSize - 1;
}

std::size_t DS::String::length() const
{
    return this -> size();
}

std::size_t DS::String::max_size() const
{
    std::size_t elem_size = sizeof(char);
    std::size_t max_bytes, max_elements;

    max_bytes = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE);
    max_elements = max_bytes / elem_size;

    return max_elements;
}

void DS::String::resize(std::size_t n)
{

    if (n == this -> size())
        return;

    DS::Allocator<char> alloc;
    char* temp = nullptr;

    if (n > this -> size())
    {
        temp = alloc.allocate(n + 1);
        alloc.construct(temp + n, '\0');

        for (std::size_t i = 0; i < this -> size(); ++i)
            alloc.construct(temp + i, this -> m_data[i]);
        
        for (std::size_t i = 0; i < this -> size(); ++i)
            alloc.destroy(this -> m_data + i);

        alloc.deallocate(this -> m_data, 0);

        this -> m_data = temp;
    }
    else
    {
        temp = alloc.allocate(n + 1);
        alloc.construct(temp + n, '\0');

        for (std::size_t i = 0; temp[i]; ++i)
            alloc.construct(temp + i, this -> m_data[i]);

        for (std::size_t i = 0; i < this -> size(); ++i)
            alloc.destroy(this -> m_data + i);

        alloc.deallocate(this -> m_data, 0);

        this -> m_data = temp;
    }
}

std::size_t DS::String::capacity() const
{
    return this -> size();
}

void DS::String::reserve(std::size_t n)
{
    DS::Allocator<char> alloc;

    char* temp = alloc.allocate(n + 1);

    for (std::size_t i = 0; i < this -> size(); ++i)
        alloc.construct(temp + i, this -> m_data[i]);
        
    for (std::size_t i = 0; i < this -> size(); ++i)
        alloc.destroy(this -> m_data + i);

    alloc.deallocate(this -> m_data, 0);

    this -> m_data = temp;
}

void DS::String::clear()
{
    if (!(this -> size()))
        return;

    DS::Allocator<char> alloc;

    for (std::size_t i = 1; i < this -> size(); ++i)
        alloc.destroy(this -> m_data + i);

    alloc.construct(this -> m_data, '\0');
}

bool DS::String::empty() const
{
    return !(this -> m_data);
}

char& DS::String::operator[](std::size_t pos)
{
    return this -> m_data[pos];
}

const char& DS::String::operator[](std::size_t pos) const
{
    return this -> m_data[pos];
}

char& DS::String::at(std::size_t pos)
{
    if (pos < 0 || pos >= this -> size())
        throw std::out_of_range("");

    return this -> m_data[pos];
}

const char& DS::String::at(std::size_t pos) const
{
    if (pos < 0 || pos >= this -> size())
        throw std::out_of_range("");

    return this -> m_data[pos];
}

char& DS::String::back()
{
    if (!(this -> size()))
        throw std::out_of_range("");

    return this -> m_data[this -> size() - 1];
}

const char& DS::String::back() const
{
    if (!(this -> size()))
        throw std::out_of_range("");

    return this -> m_data[this -> size() - 1];
}

char& DS::String::front()
{
    if (!(this -> size()))
        throw std::out_of_range("");

    return this -> m_data[0];
}

const char& DS::String::front() const
{
    if (!(this -> size()))
        throw std::out_of_range("");

    return this -> m_data[0];
}

typename DS::String& DS::String::operator+=(const DS::String& str)
{
    if (str.empty())
        return *this;

    DS::Allocator<char> alloc;

    char* temp = alloc.allocate(str.size() + this -> size() + 1);
    alloc.construct(temp + str.size() + this -> size(), '\0');

    for (std::size_t i = 0; i < this -> size(); ++i)
        alloc.construct(temp + i, this -> m_data[i]);

    std::size_t j = 0;

    for (std::size_t i = this -> size(); i < str.size() + this -> size(); ++i)
        alloc.construct(temp + i, str.m_data[j++]);

    for (std::size_t i = 0; i < this -> size(); ++i)
        alloc.destroy(this -> m_data + i);

    alloc.deallocate(this -> m_data, 0);

    this -> m_data = temp;

    return *this;
}

typename DS::String& DS::String::operator+=(const char* s)
{
    if ((s == nullptr) || !(*s))
        return *this;

    DS::Allocator<char> alloc;
    std::size_t sSize = 0;
    while (s[sSize++]);

    char* temp = alloc.allocate(this -> size() + sSize + 1);
    alloc.construct(temp + this -> size() + sSize, '\0');

    for (std::size_t i = 0; this -> m_data[i]; ++i)
        alloc.construct(temp + i, this -> m_data[i]);

    std::size_t j = 0;

    for (std::size_t i = this -> size(); s[j]; ++i)
        alloc.construct(temp + i, s[j++]);

    for (std::size_t i = 0; i < this -> size(); ++i)
        alloc.destroy(this -> m_data + i);

    alloc.deallocate(this -> m_data, 0);

    this -> m_data = temp;

    return *this;
}

typename DS::String& DS::String::operator+=(char c)
{
    DS::Allocator<char> alloc;

    char* temp = alloc.allocate(this -> size() + 2);
    alloc.construct(temp + this -> size() + 1, '\0');
    alloc.construct(temp + this -> size(), c);

    if (this -> empty())
    {
        this -> m_data = temp;
        return *this;
    }

    for (std::size_t i = 0; this -> m_data[i]; ++i)
        alloc.construct(temp + i, this -> m_data[i]);

    for (std::size_t i = 0; i < this -> size(); ++i)
        alloc.destroy(this -> m_data + i);

    alloc.deallocate(this -> m_data, 0);

    this -> m_data = temp;

    return *this;
}

typename DS::String& DS::String::append(const DS::String& str)
{
    if (str.empty())
        throw std::invalid_argument("");

    return *this += str; 
}

typename DS::String& DS::String::append(const char* s)
{
    if (!s || !(*s))
        throw std::invalid_argument("");

    return *this += s;
}

typename DS::String& DS::String::append(const char* s, std::size_t n)
{
    if (!s || !(*s))
        throw std::invalid_argument("");

    std::size_t i = 0;

    while (s[i++]);

    if (n >= i)
        throw std::invalid_argument("");

    if (!n)
        return *this;

    DS::Allocator<char> alloc;

    char* temp = alloc.allocate(n + 1);
    alloc.construct(temp + n, '\0');

    return *this += temp;
}

typename DS::String& DS::String::append(std::size_t n, char c)
{
    if (!n)
        return *this;

    for (std::size_t i = 0; i < n; ++i)
        *this += c;

    return *this;
}

void DS::String::push_back(char c)
{
    *this += c;
}

typename DS::String& DS::String::assign(const DS::String& str)
{ 
    *this = str;

    return *this;
}

typename DS::String& DS::String::assign(const char* s)
{
    DS::String temp(s);

    *this = temp;

    return  *this;
}

typename DS::String& DS::String::assign(const char* s, std::size_t n)
{
    if (!s || !(*s))
        throw std::invalid_argument("");

    std::size_t i = 0;

    while (s[i++]);

    if (n >= i)
        throw std::invalid_argument("");

    if (!n)
        return *this;

    DS::Allocator<char> alloc;

    char* temp = alloc.allocate(n + 1);
    alloc.construct(temp + n, '\0');

    return *this += temp;
}

typename DS::String& DS::String::assign(std::size_t n, char c)
{
    for (std::size_t i = 0; i < n; ++i)
        *this += c;

    return *this;
}

typename DS::String& DS::String::insert(std::size_t pos, const DS::String& str)
{
    if (pos >= this -> size())
        throw std::out_of_range("");

    if (str.empty() || !(str.size()))
        return *this;

    DS::Allocator<char> alloc;
    char* temp = alloc.allocate(this -> size() + str.size() + 1);
    alloc.construct(temp + this -> size() + str.size() , '\0');

    std::size_t j = 0;

    while (j < pos)
        alloc.construct(temp + j, this -> m_data[j++]);

    std::size_t k = j;

    for (std::size_t i = 0; i < str.size(); ++i)
        alloc.construct(temp + (k++), str.m_data[i]);
    
    while (j < this -> size())
        alloc.construct(temp + (k++), this -> m_data[j++]);

    for (std::size_t i = 0; i < this -> size(); ++i)
        alloc.destroy(this -> m_data + i);

    alloc.deallocate(this -> m_data, 0);

    this -> m_data = temp;

    return *this;
}

typename DS::String& DS::String::insert(std::size_t pos, const char* s)
{

    DS::String str = s;

    this -> insert(pos, str);

    return *this;
}

typename DS::String& DS::String::insert(std::size_t pos, const char* s, std::size_t n)
{
    std::size_t sSize = 0;

    while (s[sSize++]);

    if (n > sSize)
        throw std::invalid_argument("");

    DS::Allocator<char> alloc;

    char* temp = alloc.allocate(sSize + 1);
    alloc.construct(temp + sSize ,'\0');

    for (std::size_t i = 0; i < sSize; ++i)
        alloc.construct(temp + i, s[i]);

    this -> insert(pos, temp);

    return *this;
}

typename DS::String& DS::String::insert(std::size_t pos, std::size_t n, char c)
{
    DS::Allocator<char> alloc;

    char* temp = alloc.allocate(n + 1);
    alloc.construct(temp + n ,'\0');

    for (std::size_t i = 0; i < n; ++i)
        alloc.construct(temp + i ,c);

    this -> insert(pos, temp);

    return *this;
}

typename DS::String& DS::String::erase(std::size_t pos = 0, std::size_t len = npos)
{
    if (pos > this -> size())
        throw std::out_of_range("");

    DS::Allocator<char> alloc;

    char* temp = alloc.allocate(this -> size() - len  + 1);
    alloc.construct(temp + this -> size() - len, '\0');

    std::size_t j = 0;

    while (j < pos)
    {
        alloc.construct(temp + j, this -> m_data[j]);
        ++j;
    }

    for (std::size_t i = pos + len; i < this -> size(); ++i)
    {
        alloc.construct(temp + j, this -> m_data[i]);
        ++j;
    }

    *this = temp;

    return *this;
}

typename DS::String& DS::String::replace(std::size_t pos, std::size_t len, const DS::String& str)
{
    this -> insert(pos, str);

    this -> erase(pos + str.size() - 1, len);

    return *this;
}

typename DS::String& DS::String::replace(std::size_t pos, std::size_t len, const char* s)
{
    this -> insert(pos, s);

    std::size_t i = 0;
    while (s[i++]);

    this -> erase(pos + i - 1, len);

    return *this;
}

typename DS::String& DS::String::replace(std::size_t pos, std::size_t len, const char* s, std::size_t n)
{
    this -> insert(pos, s, n);
    this -> erase(pos + n - 1, len);

    return *this;
}

typename DS::String& DS::String::replace(std::size_t pos, std::size_t len, std::size_t n, char c)
{
    this -> insert(pos, n, c);
    this -> erase(pos + n - 1, len);

    return *this;
}

void DS::String::swap(DS::String& other)
{
    char* ptr = other.m_data;
    other.m_data = this -> m_data;
    this -> m_data = ptr;
}

void DS::String::pop_back()
{
    DS::Allocator<char> alloc;

    char* temp = alloc.allocate(this -> size());
    alloc.construct(temp + (this -> size() - 1), '\0');

    for (std::size_t i = 0; i < this -> size() - 1; ++i)
        alloc.construct(temp + i, this -> m_data[i]);

    *this = temp;
}

const char* DS::String::c_str() const
{
    return this -> m_data;
}

const char* DS::String::data() const
{
    return this -> m_data;
}

typename DS::Allocator<char> DS::String::get_allocator() const
{
    return DS::Allocator<char>();
}

std::size_t DS::String::copy(char* s, std::size_t len, std::size_t pos = 0) const
{
    if (pos > this -> size())
        throw std::out_of_range("");

    if (len >= this -> size())
        len = this -> size();

    DS::Allocator<char> alloc;

    s = alloc.allocate(len - pos + 1);
    alloc.construct(s + (len - pos), '\0');

    std::size_t j = 0;
    for (std::size_t i = pos; i < len; ++i)
        alloc.construct(s + (j++), this -> m_data[i]);

    return len - pos;
}

std::size_t DS::String::find(const DS::String& str, std::size_t pos = 0) const
{
    std::size_t len = this -> size();
    std::size_t strLen = str.size();

    if (pos >= len || strLen == 0)
        return npos;

    std::size_t maxOffset = len - strLen;

    for (std::size_t i = pos; i <= maxOffset; ++i)
    {
        if (this -> m_data[i] == str.m_data[0])
        {
            std::size_t j = 1;

            while (j < strLen && this -> m_data[i + j] == str.m_data[j])
                ++j;
            
            if (j == strLen)
                return i;
        }
    }

    return npos;
}

std::size_t DS::String::find(const char* s, std::size_t pos = 0) const
{

    std::size_t len = 0;

    while (s[len++]);

    return find(s, pos, len);
}

std::size_t DS::String::find(const char* s, std::size_t pos, std::size_t n) const
{
    std::size_t len = this -> size();

    if (n > len)
        return npos;

    std::size_t maxOffset = len - n;

    for (std::size_t i = pos; i <= maxOffset; ++i)
        if (strncmp(this -> m_data + i, s, n) == 0)
            return i;

    return npos;
}

std::size_t DS::String::find(char c, std::size_t pos = 0) const
{
    std::size_t len = this -> size();

    for (std::size_t i = pos; i < len; ++i)
        if (this -> m_data[i] == c)
            return i;

    return npos;
}

std::size_t DS::String::rfind(const DS::String& str, std::size_t pos = npos) const
{
    std::size_t len = this -> size();
    std::size_t strLen = str.size();

    if (strLen == 0)
        return (pos < len) ? pos : len;

    pos = std::min(pos, len - strLen);

    for (std::size_t i = pos; i != npos; --i)
    {
        if (this -> m_data[i] == str.m_data[0])
        {
            std::size_t j = 1;

            while (j < strLen && this -> m_data[i + j] == str.m_data[j])
                ++j;

            if (j == strLen)
                return i;
        }
    }

    return npos;
}

std::size_t DS::String::rfind(const char* s, std::size_t pos = npos) const
{
    std::size_t len = 0;

    while (s[len++]);

    return rfind(s, pos, len);
}

std::size_t DS::String::rfind(const char* s, std::size_t pos, std::size_t n) const
{
    std::size_t len = this -> size();

    if (n > len)
        return npos;

    pos = std::min(pos, len - n);

    for (std::size_t i = pos; i != npos; --i)
        if (strncmp(this -> m_data + i, s, n) == 0)
            return i;

    return npos;
}

std::size_t DS::String::rfind(char c, std::size_t pos = npos) const
{
    std::size_t len = this -> size();

    pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i != npos; --i)
        if (this -> m_data[i] == c)
            return i;

    return npos;
}

std::size_t DS::String::find_first_of(const DS::String& str, std::size_t pos = 0) const
{
    std::size_t len = this -> size();
    std::size_t strLen = str.size();

    if (strLen == 0)
        return npos;

    std::size_t maxOffset = len - 1;

    for (std::size_t i = pos; i < len; ++i)
        if (str.find(this -> m_data[i]) != npos)
            return i;

    return npos;
}

std::size_t DS::String::find_first_of(const char* s, std::size_t pos = 0) const
{
    std::size_t len = this -> size();

    if (!s || *s == '\0')
        return npos;

    pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i < len; ++i)
        if (strchr(s, this -> m_data[i]) != nullptr)
            return i;

    return npos;
}

std::size_t DS::String::find_first_of(const char* s, std::size_t pos, std::size_t n) const
{
    std::size_t len = this -> size();

    if (!s || *s == '\0')
        return npos;

    pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i < len; ++i)
        if (strchr(s, this -> m_data[i]) != nullptr)
            return i;

    return npos;
}

std::size_t DS::String::find_first_of(char c, std::size_t pos = 0) const
{
    std::size_t len = this -> size();

    pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i < len; ++i)
        if (this -> m_data[i] == c)
            return i;

    return npos;
}

std::size_t DS::String::find_last_of(const DS::String& str, std::size_t pos = npos) const
{
    std::size_t len = this -> size();
    std::size_t strLen = str.size();

    if (strLen == 0)
        return npos;

    pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i != npos; --i)
        if (str.find(this -> m_data[i]) != npos)
            return i;

    return npos;
}

std::size_t DS::String::find_last_of(const char* s, std::size_t pos = npos) const
{
    std::size_t len = this -> size();

    if (!s || *s == '\0')
        return npos;

    pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i != npos; --i)
        if (strchr(s, this -> m_data[i]) != nullptr)
            return i;

    return npos;
}

std::size_t DS::String::find_last_of(const char* s, std::size_t pos, std::size_t n) const
{
    std::size_t len = this -> size();

    if (!s || *s == '\0')
        return npos;

    pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i != npos; --i)
        if (strchr(s, this -> m_data[i]) != nullptr)
            return i;

    return npos;
}

std::size_t DS::String::find_last_of(char c, std::size_t pos = npos) const
{
    std::size_t len = this -> size();

    pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i != npos; --i)
        if (this -> m_data[i] == c)
            return i;

    return npos;
}

std::size_t DS::String::find_first_not_of(const DS::String& str, std::size_t pos = 0) const
{
    std::size_t len = this -> size();
    std::size_t strLen = str.size();

    if (strLen == 0)
        return pos;

    pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i < len; ++i)
        if (str.find(this -> m_data[i]) == npos)
            return i;

    return npos;
}

std::size_t DS::String::find_first_not_of(const char* s, std::size_t pos = 0) const
{
    std::size_t len = this -> size();

    if (!s || *s == '\0')
        return pos;

    pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i < len; ++i)
        if (strchr(s, this -> m_data[i]) == nullptr)
            return i;

    return npos;
}

std::size_t DS::String::find_first_not_of(const char* s, std::size_t pos, std::size_t n) const
{
    std::size_t len = this -> size();

    if (!s || *s == '\0')
        return pos;

    pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i < len; ++i)
        if (strncmp(s, &(this -> m_data[i]), n) != 0)
            return i;

    return npos;
}

std::size_t DS::String::find_first_not_of(char c, std::size_t pos = 0) const
{
    std::size_t len = this -> size();

    pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i < len; ++i)
        if (this -> m_data[i] != c)
            return i;

    return npos;
}

std::size_t DS::String::find_last_not_of(const DS::String& str, std::size_t pos = npos) const
{
    std::size_t len = this -> size();

    if (len == 0)
        return npos;

    if (pos == npos)
        pos = len - 1;
    else
        pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i != npos; --i)
        if (str.find(this -> m_data[i]) == npos)
            return i;

    return npos;
}

std::size_t DS::String::find_last_not_of(const char* s, std::size_t pos = npos) const
{
    std::size_t len = this -> size();

    if (len == 0)
        return npos;

    if (!s || *s == '\0')
        return pos;

    if (pos == npos)
        pos = len - 1;
    else
        pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i != npos; --i)
        if (strchr(s, this -> m_data[i]) == nullptr)
            return i;

    return npos;
}

std::size_t DS::String::find_last_not_of(const char* s, std::size_t pos, std::size_t n) const
{
    std::size_t len = this -> size();

    if (len == 0)
        return npos;

    if (!s || *s == '\0')
        return pos;

    if (pos == npos)
        pos = len - 1;
    else
        pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i != npos; --i)
        if (strncmp(s, &(this -> m_data[i]), n) != 0)
            return i;

    return npos;
}

std::size_t DS::String::find_last_not_of(char c, std::size_t pos = npos) const
{
    std::size_t len = this -> size();

    if (len == 0)
        return npos;

    if (pos == npos)
        pos = len - 1;
    else
        pos = std::min(pos, len - 1);

    for (std::size_t i = pos; i != npos; --i)
        if (this -> m_data[i] != c)
            return i;

    return npos;
}

typename DS::String DS::String::substr(std::size_t pos = 0, std::size_t len = npos) const
{
    std::size_t subLength = (len == npos) ? (this -> size() - pos) : std::min(len, this -> size() - pos);

    DS::Allocator<char> alloc;
    DS::String subString;
    subString.m_data = alloc.allocate(subLength + 1);

    memcpy(subString.m_data, this -> m_data + pos, subLength);
    alloc.construct(subString.m_data + subLength, '\0');

    return subString;
}

int DS::String::compare(const DS::String& str) const
{
    return DS::String::compare(0, this -> size(), str);
}

int DS::String::compare(std::size_t pos, std::size_t len, const DS::String& str) const
{
    return DS::String::compare(pos, len, str.m_data);
}

int DS::String::compare(std::size_t pos, std::size_t len, const DS::String& str, std::size_t subpos, std::size_t sublen) const
{
    std::size_t subStrLen = str.size();

    if (subpos >= subStrLen)
        return 1;

    sublen = std::min(sublen, subStrLen - subpos);
    return DS::String::compare(pos, len, str.m_data + subpos, sublen);
}

int DS::String::compare(const char* s) const
{
     return DS::String::compare(0, this -> size(), s);
}

int DS::String::compare(std::size_t pos, std::size_t len, const char* s) const
{
    std::size_t sLen = strlen(s);

    return DS::String::compare(pos, len, s, sLen);
}

int DS::String::compare(std::size_t pos, std::size_t len, const char* s, std::size_t n) const
{
    std::size_t sLen = strlen(s);

    std::size_t subLen = std::min(len, this -> size() - pos);

    int result = strncmp(this -> m_data + pos, s, std::min(subLen, n));

    if (result != 0)
        return result;

    if (subLen < n)
        return -1;

    return (subLen == n) ? 0 : 1;
}

std::ostream& DS::operator<<(std::ostream& os, const typename DS::String& str) 
{
    return os << str.c_str();
}

typename DS::String DS::operator+(const DS::String& lhs, const DS::String& rhs)
{
    DS::String temp = lhs;

    temp += rhs;

    return temp;
}

typename DS::String DS::operator+(const DS::String& lhs, const char* rhs)
{
    DS::String temp = lhs;

    temp += rhs;

    return temp;
}

typename DS::String DS::operator+(const char* lhs, const DS::String& rhs)
{
    DS::String temp = lhs;

    temp += rhs;

    return temp;
}

bool DS::operator==(const DS::String& lhs, const DS::String& rhs)
{
    if (lhs.size() != rhs.size())
        return false;


    for (auto it = lhs.cbegin(), jt = rhs.cbegin(); it != lhs.cend(); ++it, ++jt)
        if (*it != *jt)
            return false;

    return true;
}

bool DS::operator!=(const DS::String& lhs, const DS::String& rhs)
{
    if (lhs.size() != rhs.size())
        return true;

    for (auto it = lhs.cbegin(), jt = rhs.cbegin(); it != lhs.cend(); ++it, ++jt)
        if (*it != *jt)
            return true;

    return false;
}

bool DS::operator<(const DS::String& lhs, const DS::String& rhs)
{
    if (lhs.size() > rhs.size())
        return false;

    for (auto it = lhs.cbegin(), jt = rhs.cbegin(); it != lhs.cend() ;++it, ++jt)
        if (*it >= *jt)
            return false;

    return true;
}

bool DS::operator<=(const DS::String& lhs, const DS::String& rhs)
{
    if (lhs.size() > rhs.size())
        return false;

    for (auto it = lhs.cbegin(), jt = rhs.cbegin(); it != lhs.cend(); ++it, ++jt)
        if (*it > *jt)
            return false;

    return true;
}

bool DS::operator>(const DS::String& lhs, const DS::String& rhs)
{
    if (lhs.size() <= rhs.size())
        return false;

    for (auto it = rhs.cbegin(), jt = lhs.cbegin(); it != rhs.cend(); ++it, ++jt)
        if (*it <= *jt)
            return false;

    return true;
}

bool DS::operator>=(const DS::String& lhs, const DS::String& rhs)
{
    if (lhs.size() < rhs.size())
        return false;

    for (auto it = rhs.cbegin(), jt = lhs.cbegin(); it != rhs.cend(); ++it, ++jt)
        if (*it > *jt)
            return false;

    return true;
}

void DS::swap(DS::String& lhs, DS::String& rhs)
{
    DS::String temp = lhs;
    lhs = rhs;
    rhs = temp;
}