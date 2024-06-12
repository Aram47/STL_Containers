#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <stdexcept>
#include <unistd.h> 
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
DS::Forward_List<T, Alloc>::Node::~Node()
{
    (this -> data).~T();

    if (this -> next)
        delete this -> next;

    this -> next = nullptr;
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Base_Iterator::Base_Iterator(Node* ptr)
                : m_node{ptr}
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Base_Iterator::~Base_Iterator()
{
    this -> m_node = nullptr;
}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::Base_Iterator::operator<(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv) const
{
    return (this -> m_node) < (rhv.m_node);
}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::Base_Iterator::operator>(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv) const
{
    return (this -> m_node) > (rhv.m_node);
}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::Base_Iterator::operator<=(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv) const
{
    return (this -> m_node) <= (rhv.m_node);
}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::Base_Iterator::operator>=(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv) const
{
    return (this -> m_node) >= (rhv.m_node);
}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::Base_Iterator::operator==(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv) const
{
    return (this -> m_node) == (rhv.m_node);
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

    this -> m_node = rhv.m_node;
    
    return *this;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Base_Iterator& DS::Forward_List<T, Alloc>::Base_Iterator::operator=(DS::Forward_List<T, Alloc>::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> m_node = rhv.m_node;
    rhv.m_node = nullptr;

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
                        : DS::Forward_List<T, Alloc>::Base_Iterator(rhv.m_node)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Const_Iterator::Const_Iterator(DS::Forward_List<T, Alloc>::Base_Iterator&& rhv)
                        : DS::Forward_List<T, Alloc>::Base_Iterator(rhv.m_node)
{
    rhv.m_node = nullptr;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Const_Iterator& DS::Forward_List<T, Alloc>::Const_Iterator::operator=(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> m_node = rhv.m_node;

    return *this;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Const_Iterator& DS::Forward_List<T, Alloc>::Const_Iterator::operator=(DS::Forward_List<T, Alloc>::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> m_node = rhv.m_node;
    rhv.m_node = nullptr;

    return *this;
}

template <typename T, typename Alloc>
const T& DS::Forward_List<T, Alloc>::Const_Iterator::operator*()
{
    return this -> m_node -> data;
}

template <typename T, typename Alloc>
const T* DS::Forward_List<T, Alloc>::Const_Iterator::operator->()
{
    return &(this -> m_node -> data);
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Const_Iterator& DS::Forward_List<T, Alloc>::Const_Iterator::operator++()
{
    this -> m_node = this -> m_node -> next;

    return *this;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Const_Iterator DS::Forward_List<T, Alloc>::Const_Iterator::operator++(int)
{
    const DS::Forward_List<T, Alloc>::Const_Iterator& temp = *this;
    this -> m_node = this -> m_node -> next;

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
                    : DS::Forward_List<T, Alloc>::Const_Iterator(rhv.m_node)
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Iterator::Iterator(DS::Forward_List<T, Alloc>::Base_Iterator&& rhv)
                    : DS::Forward_List<T, Alloc>::Const_Iterator(rhv.m_node)
{
    rhv.m_node = nullptr;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Iterator& DS::Forward_List<T, Alloc>::Iterator::operator=(const DS::Forward_List<T, Alloc>::Base_Iterator& rhv)
{
    if (this == &rhv)
        return *this;

    this -> m_node = rhv.m_node;

    return *this;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Iterator& DS::Forward_List<T, Alloc>::Iterator::operator=(DS::Forward_List<T, Alloc>::Base_Iterator&& rhv)
{
    if (this == &rhv)
        return *this;

    this -> m_node = rhv.m_node;
    rhv.m_node = nullptr;

    return *this;
}

template <typename T, typename Alloc>
T& DS::Forward_List<T, Alloc>::Iterator::operator*()
{
    return this-> m_node -> data;
}

template <typename T, typename Alloc>
T* DS::Forward_List<T, Alloc>::Iterator::operator->()
{
    return &(this -> m_node -> data);
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator& DS::Forward_List<T, Alloc>::Iterator::operator++()
{
    this -> m_node = this -> m_node -> next;

    return *this;
}

template <typename T, typename Alloc>
const typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::Iterator::operator++(int)
{
    DS::Forward_List<T, Alloc>::Iterator& temp = *this;
    this -> m_node = this -> m_node -> next;

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
                    : m_head {nullptr}
{

}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(const Alloc& alloc)
                    : m_head {nullptr}
{
    
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(std::size_t count, const T& value, const Alloc& alloc)
                : m_head {nullptr}
{
    if (count) {
        this -> m_head = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(this->m_head, value);
        Node* temp = this->m_head;
        --count;
        while (count) {
            temp->next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(temp->next, value);
            temp = temp->next;
            --count;
        }
    }
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(std::size_t count)
    : m_head{nullptr}
{
    if (count) {
        this -> m_head = m_allocator.allocate(sizeof(DS::Forward_List<T>::Node));
        m_allocator.construct(this->m_head, {});
        Node* temp = this->m_head;
        --count;
        while (!count) {
            temp->next = m_allocator.allocate(sizeof(DS::Forward_List<T>::Node));
            m_allocator.construct(temp->next, {});
            temp = temp->next;
            --count;
        }
    }
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(std::size_t count, const Alloc& alloc)
    : m_head {nullptr}
{
    if (count) {
        this -> m_head = m_allocator.allocate(sizeof(DS::Forward_List<T>::Node));
        m_allocator.construct(this->m_head, {});
        Node* temp = this->m_head;
        --count;
        while (!count) {
            temp->next = m_allocator.allocate(sizeof(DS::Forward_List<T>::Node));
            m_allocator.construct(temp->next, {});
            temp = temp->next;
            --count;
        }
    }
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(DS::Forward_List<T, Alloc>::Const_Iterator first, DS::Forward_List<T, Alloc>::Const_Iterator last, const Alloc& alloc)
    : m_head {nullptr}
{   
    if (first != last) {
        this -> m_head = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(this->m_head, *first);
        Node* temp = this->m_head;
        ++first;
        while (first != last) {
            temp->next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(temp->next, *first);
            temp = temp->next;
            ++first;
        }
    }
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(const DS::Forward_List<T, Alloc>& other)
    : m_head {nullptr}
{
    if (other.begin() != other.end())
    {
        this -> m_head = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(this->m_head, *(other.begin()));
        Node* temp = this -> m_head;

        for (auto it = other.begin() + 1; it != other.end(); ++it) {
            temp -> next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(temp -> next, *it);
            temp = temp -> next;
        }
    }
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(const DS::Forward_List<T, Alloc>& other, const Alloc& alloc)
    : m_head {nullptr}
{
    if (other.begin() != other.end())
    {
        this -> m_head = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(this->m_head, *(other.begin()));
        Node* temp = this -> m_head;

        for (auto it = other.begin() + 1; it != other.end(); ++it) {
            temp -> next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(temp -> next, *it);
            temp = temp -> next;
        }
    }
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(DS::Forward_List<T, Alloc>&& other)
    : m_head {other.m_head}
{
    other.m_head = nullptr;
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(DS::Forward_List<T, Alloc>&& other, const Alloc& alloc)
    : m_head {other.m_head}
{
    other.m_head = nullptr;
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::Forward_List(std::initializer_list<T> init, const Alloc& alloc)
    : m_head {nullptr}
{
    if (init.begin() != init.end()) 
    {
        this -> m_head = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(this->m_head, *(init.begin()));
        Node* temp = this -> m_head;

        for (auto it = init.begin() + 1; it != init.end(); ++it) {
            temp -> next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(temp -> next, *it);
            temp = temp -> next;
        }
    }
}

template <typename T, typename Alloc>
DS::Forward_List<T, Alloc>::~Forward_List()
{
    this -> clear();
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>& DS::Forward_List<T, Alloc>::operator=(const DS::Forward_List<T, Alloc>& other)
{
    if (this != &other) 
    {
        this -> clear();
        if (other.begin() != other.end())
        {
            this -> m_head = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(this->m_head, *(other.begin()));
            Node* temp = this -> m_head;

            for (auto it = other.begin() + 1; it != other.end(); ++it) {
                temp -> next = m_allocator.allocate(sizeof(Node));
                m_allocator.construct(temp -> next, *it);
                temp = temp -> next;
            }
        }
    }

    return *this;
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>& DS::Forward_List<T, Alloc>::operator=(DS::Forward_List<T, Alloc>&& other)
{
    if (this != &other) 
    {
        this -> clear();
        this -> m_head = other.m_head;
        other.m_head = nullptr;
    }

    return *this;
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>& DS::Forward_List<T, Alloc>::operator=(std::initializer_list<T> ilist)
{
    this -> clear();

    if (ilist._M_len)
    {
        this -> m_head = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(this->m_head, *(ilist.begin()));
        Node* temp = this -> m_head;

        for (auto it = ilist.begin() + 1; it != ilist.end(); ++it) 
        {
            temp -> next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(temp -> next, *it);
            temp = temp -> next;
        }
    }

    return *this;
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::assign(std::size_t count, const T& value)
{
    this -> clear();

    if (count)
    {
        this -> m_head = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(this->m_head, value);
        Node* temp = this -> m_head;
        --count;

        while (count)
        {
            temp -> next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(temp -> next, value);
            temp = temp -> next;
            --count; 
        }
    }
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::assign(DS::Forward_List<T, Alloc>::Const_Iterator first, DS::Forward_List<T, Alloc>::Const_Iterator last)
{
    this -> clear();
    if (first != last)
    {
        this -> m_head = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(this->m_head, *first);
        Node* temp = this -> m_head;
        ++first;
        while (first != last)
        {
            temp -> next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(temp -> next, *first);
            temp = temp -> next;
            ++first;
        }
    }
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::assign(std::initializer_list<T> ilist)
{
    this -> clear();

    if (ilist._M_len)
    {
        this -> m_head = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(this->m_head, *(ilist.begin()));
        Node* temp = this -> m_head;

        for (auto it = ilist.begin() + 1; it != ilist.end(); ++it)
        {
            temp -> next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(temp -> next, *it);
            temp = temp -> next;
        }

    }

}

template <typename T, typename Alloc>
Alloc DS::Forward_List<T, Alloc>::get_allocator() const noexcept
{
    return this->m_all;
}

template <typename T, typename Alloc>
T& DS::Forward_List<T, Alloc>::front()
{
    if (!(this -> m_head))
        throw std::out_of_range();

    return this->m_head->data;
}

template <typename T, typename Alloc>
const T& DS::Forward_List<T, Alloc>::front() const
{
    if (!(this -> m_head))
        throw std::out_of_range();

    return this->m_head->data;
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::before_begin() const noexcept
{
    Node* temp = const_cast<DS::Forward_List<T>*>(this) -> m_allocator.allocate(sizeof(Node));
    temp -> next = this -> m_head;

    return DS::Forward_List<T, Alloc>::Iterator(temp);
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Const_Iterator DS::Forward_List<T, Alloc>::cbefore_begin() const noexcept
{
    Node* temp = const_cast<DS::Forward_List<T>*>(this) -> m_allocator.allocate(sizeof(Node));
    temp -> next = this -> m_head;
    
    return DS::Forward_List<T, Alloc>::Const_Iterator(temp);
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::begin() const noexcept
{
    return DS::Forward_List<T, Alloc>::Iterator(this->m_head);
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Const_Iterator DS::Forward_List<T, Alloc>::cbegin() const noexcept
{
    return DS::Forward_List<T, Alloc>::Const_Iterator(this->m_head);
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::end() const noexcept
{
    return DS::Forward_List<T, Alloc>::Iterator(nullptr);
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Const_Iterator DS::Forward_List<T, Alloc>::cend() const noexcept
{
    return DS::Forward_List<T, Alloc>::Const_Iterator(nullptr);
}

template <typename T, typename Alloc>
bool DS::Forward_List<T, Alloc>::empty() const noexcept
{
    return !(this->m_head);
}

template <typename T, typename Alloc>
std::size_t DS::Forward_List<T, Alloc>::max_size() const noexcept
{
    std::size_t elem_size = sizeof(Node);
    std::size_t max_bytes, max_elements;

    max_bytes = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE);
    max_elements = max_bytes / elem_size;

    return max_elements;
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::clear() noexcept
{
    while (this->m_head) 
    {
        Node* temp = this -> m_head;
        this -> m_head = this -> m_head -> next;
        m_allocator.deallocate(temp, sizeof(Node));
    }
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::insert_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, const T& value)
{
    Node* temp = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(temp, value);

    temp -> next = (pos.m_node) -> next;
    (pos.m_node) -> next = temp;
    
    return DS::Forward_List<T, Alloc>::Iterator (temp);
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::insert_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, T&& value)
{
    Node* temp = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(temp, value);

    temp -> next = (pos.m_node) -> next;
    (pos.m_node) -> next = temp;

    return DS::Forward_List<T, Alloc>::Iterator (temp);
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::insert_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, std::size_t count, const T& value)
{
    if (count)
    {

        Node* temp = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(temp, value);
        Node* ptr = temp;
        --count;

        while (count)
        {
            ptr->next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(ptr -> next, value);

            if (count - 1 != 0)
                ptr = ptr->next;

            --count;
        }

        ptr -> next = (pos.m_node) -> next;
        (pos.m_node) -> next = temp;

        return DS::Forward_List<T, Alloc>::Iterator (temp);
    }

    return pos;
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::insert_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>::Const_Iterator first, DS::Forward_List<T, Alloc>::Const_Iterator last)
{
    if (first != last)
    {
        Node* temp = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(temp, *first);
        Node* ptr = temp;
        ++first;
        Node* ptr2 = ptr;
        while (first != last)
        {
            ptr->next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(ptr->next, *first);
            ptr2 = ptr;
            ptr = ptr -> next;
            ++first;
        }

        ptr2 -> next = (pos.m_node) -> next;
        (pos.m_node) -> next = temp;

        return DS::Forward_List<T, Alloc>::Iterator (temp);
    }

    return pos;
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::insert_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, std::initializer_list<T> ilist)
{
    if (ilist.size())
    {   

        Node* temp = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(temp, *(ilist.begin()));
        Node* ptr = temp;

        for (auto it = ilist.begin() + 1; it != ilist.end(); ++it) {
            ptr->next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(ptr->next, *it);
            ptr = ptr->next;
        }

        ptr->next = (pos.m_node)->next;
        (pos.m_node)->next = temp;

        return DS::Forward_List<T, Alloc>::Iterator (temp);
    }

    return pos;
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::erase_after(DS::Forward_List<T, Alloc>::Const_Iterator pos)
{
    if ((pos) != (this->cend()))
    {
        if (!((pos.m_node)-> next -> next)) {
            m_allocator.deallocate((pos.m_node)-> next, sizeof(Node));
            (pos.m_node)-> next = nullptr;
        } else {
            Node* temp = (pos.m_node)-> next -> next;
            m_allocator.deallocate((pos.m_node)-> next, sizeof(Node));
            (pos.m_node)->next = temp;
        }
    }
    return pos;
}

template <typename T, typename Alloc>
typename DS::Forward_List<T, Alloc>::Iterator DS::Forward_List<T, Alloc>::erase_after(DS::Forward_List<T, Alloc>::Const_Iterator first, DS::Forward_List<T, Alloc>::Const_Iterator last)
{
    
    if (first != last) // 1,2,3,4,5,6,7,8 if inpit is begin() and end() ignor 1 and 8
    {
        Node* temp = first.m_node; // temp 1
        Node* secTemp = (first.m_node)->next; // secTemp 2
        Node* goToLine = (first.m_node)->next;

        if (goToLine && goToLine-> next)
        {
            while (goToLine-> next -> next)
                goToLine = goToLine->next;

            (first.m_node)->next = goToLine->next;
        }


        if ((first.m_node)->next)
        {
            while (secTemp != goToLine) {
                Node* deleter = secTemp;
                secTemp = secTemp->next;
                m_allocator.deallocate(deleter, sizeof(Node));
            }
        }
    }
    ++first;
    return first;
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::push_front(const T& value)
{
    if (!this->m_head) 
    {
        this->m_head = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(this->m_head, value);
    } 
    else 
    {
        Node* temp = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(temp, value);
        temp->next = this->m_head;
        this->m_head = temp;
    }
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::push_front(T&& value)
{
    this->push_front(value);
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::pop_front()
{
    if (this->m_head) {
        Node* temp = this->m_head;
        this->m_head = this->m_head->next;
        m_allocator.deallocate(temp, sizeof(Node));
    }
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::resize(std::size_t count)
{
    if (count)
    {
        if (!(this->m_head))
        {
            this->m_head = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(this->m_head, {});
            --count;
        }

        Node* temp = this->m_head;
        --count;
        while (count && temp->next)
        {
            temp = temp->next;
            --count;
        }

        if (count == 0 && temp) { // when count == 0 and temp != nullptr
            if (temp->next) {
                Node* secTmp = temp;
                temp = temp->next;
                secTmp->next = nullptr;
            }

            while (temp->next) {
                Node* secTmp = temp;
                temp = temp->next;
                m_allocator.deallocate(secTmp, sizeof(Node));
            }
        } else if (count != 0 && !temp->next) { // when count != 0 and temp == nullptr
            while (count)
            {
                temp->next = m_allocator.allocate(sizeof(Node));
                m_allocator.construct(temp->next, {});
                temp = temp->next;
                --count;
            }
        }

    } else {
        this ->clear();
    }
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::resize(std::size_t count, const T& value)
{
     if (count)
    {
        if (!(this->m_head))
        {
            this->m_head = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(this->m_head, value);
            --count;
        }

        Node* temp = this->m_head;
        --count;
        while (count && temp->next)
        {
            temp = temp->next;
            --count;
        }
        
        if (count == 0 && temp) { // when count == 0 and temp != nullptr
            if (temp->next) {
                Node* secTmp = temp;
                temp = temp->next;
                secTmp->next = nullptr;
            }

            while (temp->next) {
                Node* secTmp = temp;
                temp = temp->next;
                m_allocator.deallocate(secTmp, sizeof(Node));
            }
        } else if (count != 0 && !temp->next) { // when count != 0 and temp == nullptr
            while (count)
            {
                temp->next = m_allocator.allocate(sizeof(Node));
                m_allocator.construct(temp->next, value);
                temp = temp->next;
                --count;
            }
        }

    } else {
        this ->clear();
    }
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::swap(DS::Forward_List<T, Alloc>& other)
{
    Node* temp = this->m_head;
    this->m_head = other.m_head;
    other.m_head = temp;
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::merge(DS::Forward_List<T, Alloc>& other)
{
    if (!(this->m_head)) {
        this->m_head = other.m_head;
    } else {
        Node* temp = this->m_head;
        while (temp->next) 
            temp = temp->next;
        
        Node* secTemp = other.m_head;

        while (secTemp) {
            temp->next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(temp->next, *((T*)(secTemp)));
            secTemp = secTemp->next;
            temp = temp->next;
        }

    }
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::merge(DS::Forward_List<T, Alloc>&& other)
{
    this->merge(other);
    other.clear();
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::splice_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>& other)
{
    if (this == &other) {
        this->clear();
    } else {
        Node* tempPos = pos.m_node;
        Node* temp = (pos.m_node)->next;

        for (auto it = other.begin(); it != other.end(); ++it) {
            tempPos->next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(tempPos->next, *it);
            tempPos = tempPos->next;
        }
        tempPos->next = temp;
    }
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::splice_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>&& other)
{
    this->splice_after(pos, other);
    other.clear();
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::splice_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>& other, DS::Forward_List<T, Alloc>::Const_Iterator it)
{
    if (this == &other) {
        this->clear();
    } else {
        Node* tempPos = pos.m_node;
        Node* temp = (pos.m_node)->next;

        for (auto jt = it; jt != other.end(); ++jt) {
            tempPos->next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(tempPos->next, *jt);
            tempPos = tempPos->next;
        }
        tempPos->next = temp;
    }
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::splice_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>&& other, DS::Forward_List<T, Alloc>::Const_Iterator it)
{
    this->splice_after(pos, other, it);
    other.clear();
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::splice_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>& other, DS::Forward_List<T, Alloc>::Const_Iterator first, DS::Forward_List<T, Alloc>::Const_Iterator last)
{
    if (this == &other) {
        this->clear();
    } else {
        Node* tempPos = pos.m_node;
        Node* temp = (pos.m_node)->next;

        for (auto it = first; it != last; ++it) {
            tempPos->next = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(tempPos->next, *it);
            tempPos = tempPos->next;
        }
        tempPos->next = temp;
    }
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::splice_after(DS::Forward_List<T, Alloc>::Const_Iterator pos, DS::Forward_List<T, Alloc>&& other, DS::Forward_List<T, Alloc>::Const_Iterator first, DS::Forward_List<T, Alloc>::Const_Iterator last)
{
    this->splice_after(pos, other, first, last);
    other.clear();
}

template <typename T, typename Alloc>
std::size_t DS::Forward_List<T, Alloc>::remove(const T& value)
{   
    std::size_t cnt = 0;
    if (this->m_head) {
        auto prev = this->begin();
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if ((*it == value) && ((it.m_node)->next == nullptr)) {
                m_allocator.deallocate((prev.m_node)->next, sizeof(Node));
                (prev.m_node)->next = nullptr;
                ++cnt;
                break;
            } else if ((*it == value)) {
                auto i = it;
                ++i;
                std::swap(*it, *i);
                Node* temp = (it.m_node)-> next -> next;
                m_allocator.deallocate((it.m_node)->next, sizeof(Node));
                (it.m_node)->next = temp;
                it = prev;
                ++cnt;
            }
            prev = it;
        }
        if (this->m_head) { // no variant but nafsyaki :)
            if (*(this->begin()) == value) {
                Node* temp = this->m_head->next;
                m_allocator.deallocate(this->m_head, sizeof(Node));
                this->m_head = temp;
                ++cnt;
            }
        }
    }
    return cnt;
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::reverse() noexcept
{
    std::vector<T> vec;

    for (auto it = this->begin(); it != this->end(); ++it)
        vec.push_back(*it);

    auto vBeg = vec.begin();
    auto vEnd = vec.end() - 1;

    for (std::size_t i = 0; i < vec.size() / 2; ++i) {
        std::swap(*vBeg, *vEnd);
        ++vBeg;
        --vEnd;
    }

    std::size_t i = 0;
    for (auto it = this->begin(); it != this->end(); ++it)
    {
        *it = vec[i];
        ++i;
    }
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::unique()
{
    if (this->m_head) {
        auto prev = this->begin();
        auto next = prev;
        ++next;

        while ((next) != (this->end())) {
            if ((*prev) == (*next)) {
                Node* temp = next.m_node;
                (prev.m_node)->next = (prev.m_node)-> next ->next;
                m_allocator.deallocate(temp, sizeof(Node));
                next.m_node = (prev.m_node)->next;
            } else {
                ++prev;
                ++next;
            }
        }
    }
}

template <typename T, typename Alloc>
void DS::Forward_List<T, Alloc>::sort()
{
    std::vector<T> vec;
    for (auto it = this->begin(); it != this->end(); ++it)
        vec.push_back(*it);

    std::sort(vec.begin(), vec.end());
    std::size_t i = 0;

    for (auto it = this->begin(); it != this->end(); ++it)
    {
        *it = vec[i];
        ++i;
    }
}

// ---------------global ---------------

template <typename T, typename Alloc>
bool DS::operator==(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs)
{
    auto i = lhs.begin();
    auto j = rhs.begin();

    while ((i != lhs.end()) && (j != rhs.end())) {
        if (*i != *j) {
            return false;
        }
        ++i;
        ++j;
    }

    if ((i == lhs.end()) && (j == rhs.end())) {
        return true;
    }

    return false;
}

template <typename T, typename Alloc>
bool DS::operator!=(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs)
{
    return !(lhs == rhs);
}

template <typename T, typename Alloc>
bool DS::operator<(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs)
{
    auto i = lhs.begin();
    auto j = rhs.begin();

    while ((i != lhs.end()) && (j != rhs.end())) {
        if (*i >= *j) {
            return false;
        }
        ++i;
        ++j;
    }

    if ((i == lhs.end()) && (j != rhs.end()))
        return true;

    return false;
}

template <typename T, typename Alloc>
bool DS::operator<=(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs)
{
    return !(lhs > rhs);
}

template <typename T, typename Alloc>
bool DS::operator>(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs)
{
    return (lhs < rhs) && (lhs != rhs);
}

template <typename T, typename Alloc>
bool DS::operator>=( const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs)
{
    return !(lhs < rhs);
}

template <typename T, typename Alloc>
void DS::swap(DS::Forward_List<T, Alloc>& lhs, DS::Forward_List<T, Alloc>& rhs)
{
    if (&lhs != &rhs)
    {
        DS::Forward_List<T> tmp;
        tmp.m_head = lhs.m_head;
        lhs.m_head = rhs.m_head;
        rhs.m_head = tmp.m_head;
    }
}