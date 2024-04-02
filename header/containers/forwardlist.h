#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>
#include "../allocator/allocator.h"

namespace DS
{

template <typename T, typename Alloc = DS::Allocator<T>> class Forward_List;

template <typename T, typename Alloc>
class Forward_List
{
private:

    struct Node {
        T data;
        Node* next;

        Node();
        Node(const T&);
        Node(const Node&);
        Node(Node&&);
        ~Node();
    };

private:

    class Base_Iterator
    {
        friend class Forward_List<T, Alloc>;
    private:
        Node* m_ptr = nullptr;
    public:
        ~Base_Iterator();
        bool operator<(const Base_Iterator&) const;
        bool operator>(const Base_Iterator&) const;
        bool operator<=(const Base_Iterator&) const;
        bool operator>=(const Base_Iterator&) const;
        bool operator==(const Base_Iterator&) const;
        bool operator!=(const Base_Iterator&) const;

        const Base_Iterator& operator=(const Base_Iterator&);
        const Base_Iterator& operator=(Base_Iterator&&);

    protected:
        explicit Base_Iterator(Node*);
    };

public:

    class Const_Iterator : public Base_Iterator
    {
        friend class Forward_List<T, Alloc>;
  
    protected:
        explicit Const_Iterator(Node*);
    public:
        Const_Iterator();
        Const_Iterator(const Base_Iterator&);
        Const_Iterator(Base_Iterator&&);

        const Const_Iterator& operator=(const Base_Iterator&);
        const Const_Iterator& operator=(Base_Iterator&&);

        const T& operator*();
        const T* operator->();
        const Const_Iterator& operator++();
        const Const_Iterator& operator++(int);
        Const_Iterator operator+(long long int) const;
        const Const_Iterator& operator+=(long long int);
        const T& operator[](std::size_t) const;
    };

    class Iterator : public Const_Iterator
    {
        friend class Forward_List<T, Alloc>;
    public:
        Iterator();
        Iterator(const Base_Iterator&);
        Iterator(Base_Iterator&&);

        const Iterator& operator=(const Base_Iterator&);
        const Iterator& operator=(Base_Iterator&&);

        T& operator*();
        T* operator->();

        Iterator& operator++();
        Iterator& operator++(int);
        Iterator operator+(long long int) const;
        Iterator& operator+=(long long int);

        T& operator[](std::size_t);
    protected:
        explicit Iterator(Node*);
    };

public:
    Forward_List();
    explicit Forward_List(const Alloc& alloc);
    Forward_List(std::size_t count, const T& value, const Alloc& alloc = Alloc());
    explicit Forward_List(std::size_t count);
    explicit Forward_List(std::size_t count, const Alloc& alloc = Alloc());
    Forward_List(Const_Iterator first, Const_Iterator last, const Alloc& alloc = Alloc());
    Forward_List(const Forward_List& other);
    Forward_List(const Forward_List& other, const Alloc& alloc);
    Forward_List(Forward_List&& other);
    Forward_List(Forward_List&& other, const Alloc& alloc);
    Forward_List(std::initializer_list<T> init, const Alloc& alloc = Alloc());
    ~Forward_List();

    Forward_List& operator=(const Forward_List& other);
    Forward_List& operator=(Forward_List&& other);
    Forward_List& operator=(std::initializer_list<T> ilist);

    void assign(std::size_t count, const T& value);
    void assign(Const_Iterator first, Const_Iterator last);
    void assign(std::initializer_list<T> ilist);

    Alloc get_allocator() const noexcept;

    T& front();
    const T& front() const;

    Iterator before_begin() noexcept;
    Const_Iterator before_begin() const noexcept;
    Const_Iterator cbefore_begin() const noexcept;

    Iterator begin() noexcept;
    Const_Iterator begin() const noexcept;
    Const_Iterator cbegin() const noexcept;

    Iterator end() noexcept;
    Const_Iterator end() const noexcept;
    Const_Iterator cend() const noexcept;

    bool empty() const noexcept;
    std::size_t max_size() const noexcept;
    void clear() noexcept;

    Iterator insert_after(Const_Iterator pos, const T& value);
    Iterator insert_after(Const_Iterator pos, T&& value);
    Iterator insert_after(Const_Iterator pos, std::size_t count, const T& value);
    Iterator insert_after(Const_Iterator pos, Const_Iterator first, Const_Iterator last);
    Iterator insert_after(Const_Iterator pos, std::initializer_list<T> ilist);

    template <typename... Args>
    Iterator emplace_after(Const_Iterator pos, Args&&... args);
    Iterator erase_after(Const_Iterator pos);
    Iterator erase_after(Const_Iterator first, Const_Iterator last);

    void push_front(const T& value);
    void push_front(T&& value);

    template <typename... Args>
    void emplace_front(Args&&... args);
    template <typename... Args>
    T& emplace_front(Args&&... args);

    void pop_front();
    void resize(std::size_t count);
    void resize(std::size_t count, const T& value);
    void swap(Forward_List& other);

    void merge(Forward_List& other);
    void merge(Forward_List&& other);

    void splice_after(Const_Iterator pos, Forward_List& other);
    void splice_after(Const_Iterator pos, Forward_List&& other);
    void splice_after(Const_Iterator pos, Forward_List& other, Const_Iterator it);
    void splice_after(Const_Iterator pos, Forward_List&& other, Const_Iterator it);
    void splice_after(Const_Iterator pos, Forward_List& other, Const_Iterator first, Const_Iterator last);
    void splice_after(Const_Iterator pos, Forward_List&& other, Const_Iterator first, Const_Iterator last);

    std::size_t remove(const T& value);
    void reverse() noexcept;
    std::size_t unique();
    void sort();

private:
    Node* m_head;
    Alloc m_allocator;
};

template <typename T, typename Alloc>
bool operator==(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs);
template <typename T, typename Alloc>
bool operator!=(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs);
template <typename T, typename Alloc>
bool operator<(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs);
template <typename T, typename Alloc>
bool operator<=(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs);
template <typename T, typename Alloc>
bool operator>(const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs);
template <typename T, typename Alloc>
bool operator>=( const DS::Forward_List<T, Alloc>& lhs, const DS::Forward_List<T, Alloc>& rhs);

template <typename T, typename Alloc>
void swap(DS::Forward_List<T, Alloc>& lhs, DS::Forward_List<T, Alloc>& rhs);

template< class T, class Alloc, class U >
std::size_t erase(DS::Forward_List<T, Alloc>& c, const U& value);
}

#include "../../src/containers/forwardlist.hpp"

#endif