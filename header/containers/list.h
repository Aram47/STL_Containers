// #ifndef LIST_H
// #define LIST_H

// #include <iostream>
// #include "../allocator/allocator.h"

// template <typename T, typename Alloc = DS::Allocator<T>> class list;

// namespace DS
// {

// template <typename T, typename Alloc>
// class List
// {
// private:
//     struct Node {
//         T data;
//         Node* next;
//         Node* prev;

//         Node();
//         Node(const T&);
//         Node(const Node& value);
//         Node(Node&& value);
//         ~Node();
//     };

//     Node* m_head;
//     Node* m_tail;

// private:
//     class Base_Iterator
//     {
//         friend class List<T, Alloc>;
//     private:
//         T* ptr = nullptr;
//     public:
//         ~Base_Iterator();
//         bool operator<(const Base_Iterator&) const;
//         bool operator>(const Base_Iterator&) const;
//         bool operator<=(const Base_Iterator&) const;
//         bool operator>=(const Base_Iterator&) const;
//         bool operator==(const Base_Iterator&) const;
//         bool operator!=(const Base_Iterator&) const;

//         const Base_Iterator& operator=(const Base_Iterator&);
//         const Base_Iterator& operator=(Base_Iterator&&);

//     protected:
//         explicit Base_Iterator(T*);
//     };

// public:

//     class Const_Iterator : public Base_Iterator
//     {
//         friend class List<T, Alloc>;
  
//     protected:
//         explicit Const_Iterator(T*);
//     public:
//         Const_Iterator();
//         Const_Iterator(const Base_Iterator&);
//         Const_Iterator(Base_Iterator&&);

//         const Const_Iterator& operator=(const Base_Iterator&);
//         const Const_Iterator& operator=(Base_Iterator&&);

//         const T& operator*();
//         const T* operator->();
//         const Const_Iterator& operator++();
//         const Const_Iterator& operator++(int);
//         const Const_Iterator& operator--();
//         const Const_Iterator& operator--(int);
//         Const_Iterator operator+(long long int) const;
//         Const_Iterator operator-(long long int) const;
//         const Const_Iterator& operator+=(long long int);
//         const Const_Iterator& operator-=(long long int);
//         const T& operator[](std::size_t) const;
//     };

//     class Iterator : public Const_Iterator
//     {
//         friend class List<T, Alloc>;
//     public:
//         Iterator();
//         Iterator(const Base_Iterator&);
//         Iterator(Base_Iterator&&);

//         const Iterator& operator=(const Base_Iterator&);
//         const Iterator& operator=(Base_Iterator&&);

//         T& operator*();
//         T* operator->();

//         Iterator& operator++();
//         Iterator& operator++(int);
//         Iterator& operator--();
//         Iterator& operator--(int);
//         Iterator operator+(long long int) const;
//         Iterator operator-(long long int) const;
//         Iterator& operator+=(long long int);
//         Iterator& operator-=(long long int);

//         T& operator[](std::size_t);
//     protected:
//         explicit Iterator(T*);
//     };

//     class Const_Reverse_Iterator : public Base_Iterator
//     {
//         friend class List<T, Alloc>;
  
//     protected:
//         explicit Const_Reverse_Iterator(T*);
//     public:
//         Const_Reverse_Iterator();
//         Const_Reverse_Iterator(const Base_Iterator&);
//         Const_Reverse_Iterator(Base_Iterator&&);

//         const Const_Reverse_Iterator& operator=(const Base_Iterator&);
//         const Const_Reverse_Iterator& operator=(Base_Iterator&&);

//         const T& operator*();
//         const T* operator->();

//         const Const_Reverse_Iterator& operator++();
//         const Const_Reverse_Iterator& operator++(int);
//         const Const_Reverse_Iterator& operator--();
//         const Const_Reverse_Iterator& operator--(int);
//         Const_Reverse_Iterator operator+(long long int) const;
//         Const_Reverse_Iterator operator-(long long int) const;
//         const Const_Reverse_Iterator& operator+=(long long int);
//         const Const_Reverse_Iterator& operator-=(long long int);
//         const T& operator[](std::size_t) const;
//     };

//     class Reverse_Iterator : public Const_Reverse_Iterator
//     {
//         friend class List<T, Alloc>;
//     public:
//         Reverse_Iterator();
//         Reverse_Iterator(const Base_Iterator&);
//         Reverse_Iterator(Base_Iterator&&);

//         const Reverse_Iterator& operator=(const Base_Iterator&);
//         const Reverse_Iterator& operator=(Base_Iterator&&);

//         T& operator*();
//         T* operator->();

//         Reverse_Iterator& operator++();
//         Reverse_Iterator& operator++(int);
//         Reverse_Iterator& operator--();
//         Reverse_Iterator& operator--(int);
//         Reverse_Iterator operator+(long long int) const;
//         Reverse_Iterator operator-(long long int) const;
//         Reverse_Iterator& operator+=(long long int);
//         Reverse_Iterator& operator-=(long long int);

//         T& operator[](std::size_t);
//     protected:
//         explicit Reverse_Iterator(T*);
//     };

// public:

//     List();
//     explicit List(const Alloc& alloc);
//     explicit List(std::size_t count, const T& value = T(), const Alloc& alloc = Alloc());
//     List(std::size_t count, const T& value, const Alloc& alloc = Alloc());
//     explicit List(std::size_t count);
//     explicit List(std::size_t count, const Alloc& alloc = Alloc());
//     List(Iterator first, Iterator last, const Alloc& alloc = Alloc() );
//     List(const List& other);
//     List(const List& other, const Alloc& alloc);
//     List(List&& other);
//     List(List&& other, const Alloc& alloc);
//     List(std::initializer_list<T> init, const Alloc& alloc = Alloc());
//     ~List();

//     List& operator=(const List& other);
//     List& operator=(List&& other);
//     List& operator=(std::initializer_list<T> ilist);

//     void assign(std::size_t count, const T& value);	
//     void assign(Iterator first, Iterator last);
//     void assign(std::initializer_list<T> ilist);

//     Alloc get_allocator() const noexcept;

//     T& front();
//     const T& front() const;
//     T& back();
//     const T& back() const;
//     bool empty() const noexcept;
//     std::size_t size() const noexcept;
//     std::size_t max_size() const noexcept;
//     void clear() noexcept;

//     Iterator begin() noexcept;
//     Const_Iterator cbegin() const noexcept;
//     Iterator end() noexcept;
//     Const_Iterator cend() const noexcept;
//     Reverse_Iterator rbegin() noexcept;
//     Const_Reverse_Iterator crbegin() const noexcept;
//     Reverse_Iterator rend() noexcept;
//     Const_Reverse_Iterator crend() const noexcept;

//     Iterator insert(Const_Iterator pos, const T& value);
//     Iterator insert(Const_Iterator pos, T&& value);
//     Iterator insert(Const_Iterator pos, std::size_t count, const T& value);
//     Iterator insert(Const_Iterator pos, Iterator first, Iterator last);
//     Iterator insert(Const_Iterator pos, std::initializer_list<T> ilist);
//     template <typename... Args>
//     Iterator emplace(Const_Iterator pos, Args&&... args);
//     Iterator erase(Const_Iterator pos);
//     Iterator erase(Const_Iterator first, Const_Iterator last);

//     void push_back(const T& value);
//     void push_back(T&& value);
//     void pop_back();
//     void push_front(const T& value);
//     void push_front(T&& value);
//     void pop_front();
//     void resize(std::size_t count);
//     void resize(std::size_t count, const T& value);
//     void swap(List& other);

//     void merge(List& other);
//     void merge(List&& other);

//     void splice(Const_Iterator pos, List& other);
//     void splice(Const_Iterator pos, List&& other);
//     void splice(Const_Iterator pos, List& other, Const_Iterator it);
//     void splice(Const_Iterator pos, List&& other, Const_Iterator it);
//     void splice(Const_Iterator pos, List& other, Const_Iterator first, Const_Iterator last);
//     void splice(Const_Iterator pos, List&& other, Const_Iterator first, Const_Iterator last);

//     std::size_t remove(const T& value);
//     void reverse() noexcept;
//     std::size_t unique();
//     void sort();

// };

// template <typename T, typename Alloc>
// bool operator==(const DS::List<T, Alloc>& lhs, const DS::List<T, Alloc>& rhs);
// template <typename T, typename Alloc>
// bool operator!=( const DS::List<T, Alloc>& lhs, const DS::List<T, Alloc>& rhs);
// template <typename T, typename Alloc>
// bool operator<(const DS::List<T, Alloc>& lhs, const DS::List<T, Alloc>& rhs);
// template <typename T, typename Alloc>
// bool operator<=(const DS::List<T, Alloc>& lhs, const DS::List<T, Alloc>& rhs);
// template <typename T, typename Alloc>
// bool operator>(const DS::List<T, Alloc>& lhs, const DS::List<T, Alloc>& rhs);
// template <typename T, typename Alloc>
// bool operator>=(const DS::List<T, Alloc>& lhs, const DS::List<T, Alloc>& rhs);

// template <typename T, typename Alloc>
// void swap(DS::List<T, Alloc>& lhs, DS::List<T, Alloc>& rhs) noexcept(lhs.swap(rhs));
// template <typename T, typename Alloc, typename U>
// std::size_t erase(DS::List<T, Alloc>& c, const U& value);
// }

// #include "../../src/containers/list.hpp"

// #endif