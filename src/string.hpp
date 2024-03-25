#include <iostream>
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