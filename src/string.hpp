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

        alloc.deallocate(this -> m_data, this -> size());

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

        alloc.deallocate(this -> m_data, this -> size());

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

    alloc.deallocate(this -> m_data, this -> size());

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
    return !(this -> size());
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
    
}

typename DS::String& DS::String::operator+=(const char* s)
{

}

typename DS::String& DS::String::operator+=(char c)
{

}

typename DS::String& DS::String::append(const DS::String& str)
{

}

typename DS::String& DS::String::append(const char* s)
{

}

typename DS::String& DS::String::append(const char* s, std::size_t n)
{

}

typename DS::String& DS::String::append(std::size_t n, char c)
{

}

void DS::String::push_back(char c)
{

}

typename DS::String& DS::String::assign(const DS::String& str)
{

}

typename DS::String& DS::String::assign(const char* s)
{

}

typename DS::String& DS::String::assign(const char* s, std::size_t n)
{

}

typename DS::String& DS::String::assign(std::size_t n, char c)
{

}

typename DS::String& DS::String::insert(std::size_t pos, const DS::String& str)
{

}

typename DS::String& DS::String::insert(std::size_t pos, const char* s)
{

}

typename DS::String& DS::String::insert(std::size_t pos, const char* s, std::size_t n)
{

}

typename DS::String& DS::String::insert(std::size_t pos, std::size_t n, char c)
{

}

typename DS::String& DS::String::erase(std::size_t pos = 0, std::size_t len = npos)
{

}

typename DS::String& DS::String::replace(std::size_t pos, std::size_t len, const DS::String& str)
{

}

typename DS::String& DS::String::replace(std::size_t pos, std::size_t len, const char* s)
{

}

typename DS::String& DS::String::replace(std::size_t pos, std::size_t len, const char* s, std::size_t n)
{

}

typename DS::String& DS::String::replace(std::size_t pos, std::size_t len, std::size_t n, char c)
{

}

void DS::String::swap(DS::String& other)
{

}

void DS::String::pop_back()
{

}

const char* DS::String::c_str() const
{

}

const char* DS::String::data() const
{

}

typename DS::Allocator<char> DS::String::get_allocator() const
{

}

std::size_t DS::String::copy(char* s, std::size_t len, std::size_t pos = 0) const
{

}

std::size_t DS::String::find(const DS::String& str, std::size_t pos = 0) const
{

}

std::size_t DS::String::find(const char* s, std::size_t pos = 0) const
{

}

std::size_t DS::String::find(const char* s, std::size_t pos, std::size_t n) const
{

}

std::size_t DS::String::find(char c, std::size_t pos = 0) const
{

}

std::size_t DS::String::rfind(const DS::String& str, std::size_t pos = npos) const
{

}

std::size_t DS::String::rfind(const char* s, std::size_t pos = npos) const
{

}

std::size_t DS::String::rfind(const char* s, std::size_t pos, std::size_t n) const
{

}

std::size_t DS::String::rfind(char c, std::size_t pos = npos) const
{

}

std::size_t DS::String::find_first_of(const DS::String& str, std::size_t pos = 0) const
{

}

std::size_t DS::String::find_first_of(const char* s, std::size_t pos = 0) const
{

}

std::size_t DS::String::find_first_of(const char* s, std::size_t pos, std::size_t n) const
{

}

std::size_t DS::String::find_first_of(char c, std::size_t pos = 0) const
{

}

std::size_t DS::String::find_last_of(const DS::String& str, std::size_t pos = npos) const
{

}

std::size_t DS::String::find_last_of(const char* s, std::size_t pos = npos) const
{

}

std::size_t DS::String::find_last_of(const char* s, std::size_t pos, std::size_t n) const
{

}

std::size_t DS::String::find_last_of(char c, std::size_t pos = npos) const
{

}

std::size_t DS::String::find_first_not_of(const DS::String& str, std::size_t pos = 0) const
{

}

std::size_t DS::String::find_first_not_of(const char* s, std::size_t pos = 0) const
{

}

std::size_t DS::String::find_first_not_of(const char* s, std::size_t pos, std::size_t n) const
{

}

std::size_t DS::String::find_first_not_of(char c, std::size_t pos = 0) const
{

}

std::size_t DS::String::find_last_not_of(const DS::String& str, std::size_t pos = npos) const
{

}

std::size_t DS::String::find_last_not_of(const char* s, std::size_t pos = npos) const
{

}

std::size_t DS::String::find_last_not_of(const char* s, std::size_t pos, std::size_t n) const
{

}

std::size_t DS::String::find_last_not_of(char c, std::size_t pos = npos) const
{

}

typename DS::String DS::String::substr(std::size_t pos = 0, std::size_t len = npos) const
{

}

int DS::String::compare(const DS::String& str) const
{

}

int DS::String::compare(std::size_t pos, std::size_t len, const DS::String& str) const
{

}

int DS::String::compare(std::size_t pos, std::size_t len, const DS::String& str, std::size_t subpos, std::size_t sublen) const
{

}

int DS::String::compare(const char* s) const
{

}

int DS::String::compare(std::size_t pos, std::size_t len, const char* s) const
{

}

int DS::String::compare(std::size_t pos, std::size_t len, const char* s, std::size_t n) const
{

}

// ---------- global ---------

typename DS::String operator+(const DS::String& lhs, const DS::String& rhs)
{

}

typename DS::String operator+(const DS::String& lhs, const char* rhs)
{

}

typename DS::String operator+(const char* lhs, const DS::String& rhs)
{

}

bool DS::operator==(const DS::String& lhs, const DS::String& rhs)
{

}

bool DS::operator!=(const DS::String& lhs, const DS::String& rhs)
{

}

bool DS::operator<(const DS::String& lhs, const DS::String& rhs)
{

}

bool DS::operator<=(const DS::String& lhs, const DS::String& rhs)
{

}

bool DS::operator>(const DS::String& lhs, const DS::String& rhs)
{

}

bool DS::operator>=(const DS::String& lhs, const DS::String& rhs)
{

}

void DS::swap(DS::String& lhs, DS::String& rhs)
{

}