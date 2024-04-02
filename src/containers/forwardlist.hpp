#include <iostream>
#include "../../header/allocator/allocator.h"
#include "../../header/containers/forwardlist.h"

template <typename T, typename Alloc = DS::Allocator<T>> class Forward_List;

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Node::Node()
                : data{}
                , next{nullptr}
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Node::Node(const T& value)
                : data{value}
                , next{nullptr}
{
    
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Node::Node(const DS::Forward_List<T, Alloc>::Node& other)
                : data{other.data}
                , next{other.next}
{
    
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Node::Node(DS::Forward_List<T, Alloc>::Node&& other)
                : data{other.data}
                , next{other.next}
{
    other.data.~T();
    other.next = nullptr;
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Node::~Node()
{
    (this -> data).~T();

    if (this -> next)
        delete this -> next;

    this -> next = nullptr;
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Base_Iterator::Base_Iterator(Node* ptr)
                : m_ptr{ptr}
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Base_Iterator::~Base_Iterator()
{
    this -> m_ptr = nullptr;
}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::Base_Iterator::operator<(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv) const
{
    return (this -> m_ptr) < (rhv.m_ptr);
}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::Base_Iterator::operator>(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv) const
{
    return (this -> m_ptr) > (rhv.m_ptr);
}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::Base_Iterator::operator<=(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv) const
{
    return (this -> m_ptr) <= (rhv.m_ptr);
}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::Base_Iterator::operator>=(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv) const
{
    return (this -> m_ptr) >= (rhv.m_ptr);
}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::Base_Iterator::operator==(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv) const
{
    return (this -> m_ptr) == (rhv.m_ptr);
}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::Base_Iterator::operator!=(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv) const
{
    return !(*this == rhv);
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Base_Iterator& DS::Forward_List<T, Alloc>::Base_Iterator::operator=(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> m_ptr = rhv.m_ptr;
    
    return *this;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Base_Iterator& DS::Forward_List<T, Alloc>::Base_Iterator::operator=(DS::Forward_List<T, Alloc>::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> m_ptr = rhv.m_ptr;
    rhv.m_ptr = nullptr;

    return *this;
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Const_Iterator::Const_Iterator(Node* p)
                        : DS::Forward_List<T, Alloc>::Base_Iterator(p)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Const_Iterator::Const_Iterator()
                        : DS::Forward_List<T, Alloc>::Base_Iterator(nullptr)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Const_Iterator::Const_Iterator(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv)
                        : DS::Forward_List<T, Alloc>::Base_Iterator(rhv.m_ptr)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Const_Iterator::Const_Iterator(DS::Forward_List<T, Alloc>::Base_Iterator&& rhv)
                        : DS::Forward_List<T, Alloc>::Base_Iterator(rhv.m_ptr)
{
    rhv.m_ptr = nullptr;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Const_Iterator& DS::Forward_List<T, Alloc>::Const_Iterator::operator=(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> m_ptr = rhv.m_ptr;

    return *this;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Const_Iterator& DS::Forward_List<T, Alloc>::Const_Iterator::operator=(DS::Forward_List<T, Alloc>::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> m_ptr = rhv.m_ptr;
    rhv.m_ptr = nullptr;

    return *this;
}

template <typename T, typename Alloc>
const T& DS::Forward_List<T, Alloc>::Const_Iterator::operator*()
{
    return this -> m_ptr -> data;
}

template <typename T, typename Alloc>
const T* DS::Forward_List<T, Alloc>::Const_Iterator::operator->()
{
    return &(this -> m_ptr -> data);
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Const_Iterator& DS::Forward_List<T, Alloc>::Const_Iterator::operator++()
{
    this -> m_ptr = this -> m_ptr -> next;

    return *this;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Const_Iterator& DS::Forward_List<T, Alloc>::Const_Iterator::operator++(int)
{
    const DS::Forward_List<T, Alloc>::Const_Iterator& temp = *this;
    this -> m_ptr = this -> m_ptr -> next;

    return temp;
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Const_Iterator DS::Forward_List<T, Alloc>::Const_Iterator::operator+(long long int arg) const
{
    if (arg < 0)
        throw std::invalid_argument("");

    DS::Forward_List<T, Alloc>::Const_Iterator temp = *this;

    std::size_t i = 0;

    while (i < arg)
        ++temp;

    return temp;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Const_Iterator& DS::Forward_List<T, Alloc>::Const_Iterator::operator+=(long long int arg)
{
    if (arg < 0)
        throw std::invalid_argument("");

    std::size_t i = 0;

    while (i < arg)
        ++this;

    return *this;
}

template <typename T, typename Alloc>
const T& DS::Forward_List<T, Alloc>::Const_Iterator::operator[](std::size_t index) const
{
    DS::Forward_List<T, Alloc>::Const_Iterator temp = *this;

    std::size_t i = 0;

    while (i < index)
        ++temp;

    return *temp;
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Iterator::Iterator(Node* p)
                    : DS::Forward_List<T, Alloc>::Const_Iterator(p)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Iterator::Iterator()
                    : DS::Forward_List<T, Alloc>::Const_Iterator(nullptr)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Iterator::Iterator(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv)
                    : DS::Forward_List<T, Alloc>::Const_Iterator(rhv.m_ptr)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Iterator::Iterator(DS::Forward_List<T, Alloc>::Base_Iterator&& rhv)
                    : DS::Forward_List<T, Alloc>::Const_Iterator(rhv.m_ptr)
{
    rhv.m_ptr = nullptr;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Iterator& DS::Forward_List<T, Alloc>::Iterator::operator=(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> m_ptr = rhv.m_ptr;

    return *this;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Iterator& DS::Forward_List<T, Alloc>::Iterator::operator=(DS::Forward_List<T, Alloc>::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> m_ptr = rhv.m_ptr;
    rhv.m_ptr = nullptr;

    return *this;
}

template <typename T, typename Alloc>
T& DS::Forward_List<T, Alloc>::Iterator::operator*()
{
    return this -> m_ptr -> data;
}

template <typename T, typename Alloc>
T* DS::Forward_List<T, Alloc>::Iterator::operator->()
{
    return &(this -> m_ptr -> data);
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator& DS::Forward_List<T, Alloc>::Iterator::operator++()
{
    this -> m_ptr = this -> m_ptr -> next;

    return *this;
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator& DS::Forward_List<T, Alloc>::Iterator::operator++(int)
{
    DS::Forward_List<T, Alloc>::Iterator& temp = *this;
    this -> m_ptr = this -> m_ptr -> next;

    return temp;
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::Iterator::operator+(long long int arg) const
{
    if (arg < 0)
        throw std::invalid_argument("");

    DS::Forward_List<T, Alloc>::Iterator temp = *this;

    std::size_t i = 0;

    while (i < arg)
        ++temp;

    return temp;
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator& DS::Forward_List<T, Alloc>::Iterator::operator+=(long long int arg)
{
    if (arg < 0)
        throw std::invalid_argument("");

    std::size_t i = 0;

    while (i < arg)
        ++this;

    return *this;
}

template <typename T, typename Alloc>
T& DS::Forward_List<T, Alloc>::Iterator::operator[](std::size_t index)
{
    DS::Forward_List<T, Alloc>::Iterator temp = *this;

    std::size_t i = 0;

    while (i < index)
        ++temp;

    return *temp;
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List()
                    : m_head(nullptr)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(const Alloc& alloc)
                    : m_head(nullptr)
                    , m_allocator(alloc)
{
    
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(std::size_t count, const T& value, const Alloc& alloc)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(std::size_t count)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(std::size_t count, const Alloc& alloc)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(DS::Forward_List<T, Alloc>::Const_Iterator first, DS::Forward_List<T, Alloc>::Const_Iterator last, const Alloc& alloc)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(const DS::Forward_List<T, Alloc>& other)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(const DS::Forward_List<T, Alloc>& other, const Alloc& alloc)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(DS::Forward_List<T, Alloc>&& other)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(DS::Forward_List<T, Alloc>&& other, const Alloc& alloc)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(std::initializer_list<T> init, const Alloc& alloc)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::~Forward_List()
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>& DS::Forward_List<T, Alloc>::operator=(const DS::Forward_List<T, Alloc>& other)
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>& DS::Forward_List<T, Alloc>::operator=(DS::Forward_List<T, Alloc>&& other)
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>& DS::Forward_List<T, Alloc>::operator=(std::initializer_list<T> ilist)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::assign(std::size_t count, const T& value)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::assign(DS::Forward_List<T, Alloc>::Const_Iterator first, DS::Forward_List<T, Alloc>::Const_Iterator last)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::assign(std::initializer_list<T> ilist)
{

}

template <typename T, typename Alloc>
Alloc DS::Forward_List<T, Alloc>::get_allocator() const noexcept
{

}

template <typename T, typename Alloc>
T& DS::Forward_List<T, Alloc>::front()
{

}

template <typename T, typename Alloc>
const T& DS::Forward_List<T, Alloc>::front() const
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::before_begin() noexcept
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Const_Iterator DS::Forward_List<T, Alloc>::before_begin() const noexcept
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Const_Iterator DS::Forward_List<T, Alloc>::cbefore_begin() const noexcept
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::begin() noexcept
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Const_Iterator DS::Forward_List<T, Alloc>::begin() const noexcept
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Const_Iterator DS::Forward_List<T, Alloc>::cbegin() const noexcept
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::end() noexcept
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Const_Iterator DS::Forward_List<T, Alloc>::end() const noexcept
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Const_Iterator DS::Forward_List<T, Alloc>::cend() const noexcept
{

}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::empty() const noexcept
{

}

template <typename T, typename Alloc>
std::size_t DS::Forward_List<T, Alloc>::max_size() const noexcept
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::clear() noexcept
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::insert_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, const T& value)
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::insert_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, T&& value)
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::insert_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, std::size_t count, const T& value)
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::insert_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>::Const_Iterator first, DS::Forward_List<T, Alloc>::Const_Iterator last)
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::insert_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, std::initializer_list<T> ilist)
{

}

template <typename T, typename Alloc>
template <typename... Args>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::emplace_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, Args&&... args)
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::erase_after(DS::Forward_List<T, Alloc>::Const_Iterator pos)
{

}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::erase_after(DS::Forward_List<T, Alloc>::Const_Iterator first, DS::Forward_List<T, Alloc>::Const_Iterator last)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::push_front(const T& value)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::push_front(T&& value)
{

}

template <typename T, typename Alloc>
template <typename... Args>
void DS::Forward_List<T, Alloc>::emplace_front(Args&&... args)
{

}

template <typename T, typename Alloc>
template <typename... Args>
T& DS::Forward_List<T, Alloc>::emplace_front(Args&&... args)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::pop_front()
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::resize(std::size_t count)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::resize(std::size_t count, const T& value)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::swap(DS::Forward_List<T, Alloc>& other)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::merge(DS::Forward_List<T, Alloc>& other)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::merge(DS::Forward_List<T, Alloc>&& other)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::splice_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>& other)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::splice_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>&& other)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::splice_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>& other, DS::Forward_List<T, Alloc>::Const_Iterator it)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::splice_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>&& other, DS::Forward_List<T, Alloc>::Const_Iterator it)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::splice_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>& other, DS::Forward_List<T, Alloc>::Const_Iterator first, DS::Forward_List<T, Alloc>::Const_Iterator last)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::splice_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>&& other, DS::Forward_List<T, Alloc>::Const_Iterator first, DS::Forward_List<T, Alloc>::Const_Iterator last)
{

}

template <typename T, typename Alloc>
std::size_t DS::Forward_List<T, Alloc>::remove(const T& value)
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::reverse() noexcept
{

}

template <typename T, typename Alloc>
std::size_t DS::Forward_List<T, Alloc>::unique()
{

}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::sort()
{

}

// ---------------global ---------------

template <typename T, typename Alloc>
bool DS::operator==(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs)
{

}

template <typename T, typename Alloc>
bool DS::operator!=(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs)
{

}
template <typename T, typename Alloc>
bool DS::operator<(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs)
{

}
template <typename T, typename Alloc>
bool DS::operator<=(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs)
{

}
template <typename T, typename Alloc>
bool DS::operator>(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs)
{

}
template <typename T, typename Alloc>
bool DS::operator>=( const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs)
{

}

template <typename T, typename Alloc>
void DS::swap(DS::Forward_List<T, Alloc>& lhs, DS::Forward_List<T, Alloc>& rhs)
{

}

template< class T, class Alloc, class U >
std::size_t DS::erase(DS::Forward_List<T, Alloc>& c, const U& value)
{

}