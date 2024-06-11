// #include <iostream>
// #include "../../header/allocator/allocator.h"
// #include "../../header/containers/list.h"

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Node::Node()
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Node::Node(const T&)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Node::Node(const Node& value)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Node::Node(Node&& value)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Node::~Node()
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Base_Iterator::Base_Iterator(T*)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Base_Iterator::~Base_Iterator()
// {

// }

// template <typename T, typename Alloc>
// bool DS::List<T, Alloc>::Base_Iterator::operator<(const DS::List<T, Alloc>::Base_Iterator&) const
// {

// }

// template <typename T, typename Alloc>
// bool DS::List<T, Alloc>::Base_Iterator::operator>(const DS::List<T, Alloc>::Base_Iterator&) const
// {

// }

// template <typename T, typename Alloc>
// bool DS::List<T, Alloc>::Base_Iterator::operator<=(const DS::List<T, Alloc>::Base_Iterator&) const
// {

// }

// template <typename T, typename Alloc>
// bool DS::List<T, Alloc>::Base_Iterator::operator>=(const DS::List<T, Alloc>::Base_Iterator&) const
// {

// }

// template <typename T, typename Alloc>
// bool DS::List<T, Alloc>::Base_Iterator::operator==(const DS::List<T, Alloc>::Base_Iterator&) const
// {

// }

// template <typename T, typename Alloc>
// bool DS::List<T, Alloc>::Base_Iterator::operator!=(const DS::List<T, Alloc>::Base_Iterator&) const
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Base_Iterator& DS::List<T, Alloc>::Base_Iterator::operator=(const DS::List<T, Alloc>::Base_Iterator&)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Base_Iterator& DS::List<T, Alloc>::Base_Iterator::operator=(DS::List<T, Alloc>::Base_Iterator&&)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Const_Iterator::Const_Iterator(T*)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Const_Iterator::Const_Iterator()
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Const_Iterator::Const_Iterator(const DS::List<T, Alloc>::Base_Iterator&)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Const_Iterator::Const_Iterator(DS::List<T, Alloc>::Base_Iterator&&)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Iterator& DS::List<T, Alloc>::Const_Iterator::operator=(const DS::List<T, Alloc>::Base_Iterator&)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Iterator& DS::List<T, Alloc>::Const_Iterator::operator=(DS::List<T, Alloc>::Base_Iterator&&)
// {

// }

// template <typename T, typename Alloc>
// const T& DS::List<T, Alloc>::Const_Iterator::operator*()
// {

// }

// template <typename T, typename Alloc>
// const T* DS::List<T, Alloc>::Const_Iterator::operator->()
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Iterator& DS::List<T, Alloc>::Const_Iterator::operator++()
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Iterator& DS::List<T, Alloc>::Const_Iterator::operator++(int)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Iterator& DS::List<T, Alloc>::Const_Iterator::operator--()
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Iterator& DS::List<T, Alloc>::Const_Iterator::operator--(int)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Const_Iterator DS::List<T, Alloc>::Const_Iterator::operator+(long long int) const
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Const_Iterator DS::List<T, Alloc>::Const_Iterator::operator-(long long int) const
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Iterator& DS::List<T, Alloc>::Const_Iterator::operator+=(long long int)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Iterator& DS::List<T, Alloc>::Const_Iterator::operator-=(long long int)
// {

// }

// template <typename T, typename Alloc>
// const T& DS::List<T, Alloc>::Const_Iterator::operator[](std::size_t) const
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Iterator::Iterator(T*)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Iterator::Iterator()
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Iterator::Iterator(const DS::List<T, Alloc>::Base_Iterator&)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Iterator::Iterator(DS::List<T, Alloc>::Base_Iterator&&)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Iterator& DS::List<T, Alloc>::Iterator::operator=(const Base_Iterator&)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Iterator& DS::List<T, Alloc>::Iterator::operator=(DS::List<T, Alloc>::Base_Iterator&&)
// {

// }

// template <typename T, typename Alloc>
// T& DS::List<T, Alloc>::Iterator::operator*()
// {

// }

// template <typename T, typename Alloc>
// T* DS::List<T, Alloc>::Iterator::operator->()
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator& DS::List<T, Alloc>::Iterator::operator++()
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator& DS::List<T, Alloc>::Iterator::operator++(int)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator& DS::List<T, Alloc>::Iterator::operator--()
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator& DS::List<T, Alloc>::Iterator::operator--(int)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator DS::List<T, Alloc>::Iterator::operator+(long long int) const
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator DS::List<T, Alloc>::Iterator::operator-(long long int) const
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator& DS::List<T, Alloc>::Iterator::operator+=(long long int)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator& DS::List<T, Alloc>::Iterator::operator-=(long long int)
// {

// }

// template <typename T, typename Alloc>
// T& DS::List<T, Alloc>::Iterator::operator[](std::size_t)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Const_Reverse_Iterator::Const_Reverse_Iterator(T*)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Const_Reverse_Iterator::Const_Reverse_Iterator()
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Const_Reverse_Iterator::Const_Reverse_Iterator(const DS::List<T, Alloc>::Base_Iterator&)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Const_Reverse_Iterator::Const_Reverse_Iterator(DS::List<T, Alloc>::Base_Iterator&&)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Reverse_Iterator& DS::List<T, Alloc>::Const_Reverse_Iterator::operator=(const DS::List<T, Alloc>::Base_Iterator&)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Reverse_Iterator& DS::List<T, Alloc>::Const_Reverse_Iterator::operator=(DS::List<T, Alloc>::Base_Iterator&&)
// {

// }

// template <typename T, typename Alloc>
// const T& DS::List<T, Alloc>::Const_Reverse_Iterator::operator*()
// {

// }

// template <typename T, typename Alloc>
// const T* DS::List<T, Alloc>::Const_Reverse_Iterator::operator->()
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Reverse_Iterator& DS::List<T, Alloc>::Const_Reverse_Iterator::operator++()
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Reverse_Iterator& DS::List<T, Alloc>::Const_Reverse_Iterator::operator++(int)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Reverse_Iterator& DS::List<T, Alloc>::Const_Reverse_Iterator::operator--()
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Reverse_Iterator& DS::List<T, Alloc>::Const_Reverse_Iterator::operator--(int)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Const_Reverse_Iterator DS::List<T, Alloc>::Const_Reverse_Iterator::operator+(long long int) const
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Const_Reverse_Iterator DS::List<T, Alloc>::Const_Reverse_Iterator::operator-(long long int) const
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Reverse_Iterator& DS::List<T, Alloc>::Const_Reverse_Iterator::operator+=(long long int)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Const_Reverse_Iterator& DS::List<T, Alloc>::Const_Reverse_Iterator::operator-=(long long int)
// {

// }

// template <typename T, typename Alloc>
// const T& DS::List<T, Alloc>::Const_Reverse_Iterator::operator[](std::size_t) const
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Reverse_Iterator::Reverse_Iterator(T*)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Reverse_Iterator::Reverse_Iterator()
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Reverse_Iterator::Reverse_Iterator(const DS::List<T, Alloc>::Base_Iterator&)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::Reverse_Iterator::Reverse_Iterator(DS::List<T, Alloc>::Base_Iterator&&)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Reverse_Iterator& DS::List<T, Alloc>::Reverse_Iterator::operator=(const DS::List<T, Alloc>::Base_Iterator&)
// {

// }

// template <typename T, typename Alloc>
// const typename DS::List<T, Alloc>::Reverse_Iterator& DS::List<T, Alloc>::Reverse_Iterator::operator=(DS::List<T, Alloc>::Base_Iterator&&)
// {

// }

// template <typename T, typename Alloc>
// T& DS::List<T, Alloc>::Reverse_Iterator::operator*()
// {

// }

// template <typename T, typename Alloc>
// T* DS::List<T, Alloc>::Reverse_Iterator::operator->()
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Reverse_Iterator& DS::List<T, Alloc>::Reverse_Iterator::operator++()
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Reverse_Iterator& DS::List<T, Alloc>::Reverse_Iterator::operator++(int)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Reverse_Iterator& DS::List<T, Alloc>::Reverse_Iterator::operator--()
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Reverse_Iterator& DS::List<T, Alloc>::Reverse_Iterator::operator--(int)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Reverse_Iterator DS::List<T, Alloc>::Reverse_Iterator::operator+(long long int) const
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Reverse_Iterator DS::List<T, Alloc>::Reverse_Iterator::operator-(long long int) const
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Reverse_Iterator& DS::List<T, Alloc>::Reverse_Iterator::operator+=(long long int)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Reverse_Iterator& DS::List<T, Alloc>::Reverse_Iterator::operator-=(long long int)
// {

// }

// template <typename T, typename Alloc>
// T& DS::List<T, Alloc>::Reverse_Iterator::operator[](std::size_t)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::List()
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::List(const Alloc& alloc)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::List(std::size_t count, const T& value = T(), const Alloc& alloc = Alloc())
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::List(std::size_t count, const T& value, const Alloc& alloc = Alloc())
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::List(std::size_t count)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::List(std::size_t count, const Alloc& alloc = Alloc())
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::List(DS::List<T, Alloc>::Iterator first, DS::List<T, Alloc>::Iterator last, const Alloc& alloc = Alloc())
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::List(const DS::List<T, Alloc>& other)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::List(const DS::List<T, Alloc>& other, const Alloc& alloc)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::List(DS::List<T, Alloc>&& other)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::List(DS::List<T, Alloc>&& other, const Alloc& alloc)
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::List(std::initializer_list<T> init, const Alloc& alloc = Alloc())
// {

// }

// template <typename T, typename Alloc>
// DS::List<T, Alloc>::~List()
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>& DS::List<T, Alloc>::operator=(const DS::List<T, Alloc>& other)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>& DS::List<T, Alloc>::operator=(DS::List<T, Alloc>&& other)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>& DS::List<T, Alloc>::operator=(std::initializer_list<T> ilist)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::assign(std::size_t count, const T& value)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::assign(DS::List<T, Alloc>::Iterator first, DS::List<T, Alloc>::Iterator last)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::assign(std::initializer_list<T> ilist)
// {

// }

// template <typename T, typename Alloc>
// Alloc DS::List<T, Alloc>::get_allocator() const noexcept
// {

// }

// template <typename T, typename Alloc>
// T& DS::List<T, Alloc>::front()
// {

// }

// template <typename T, typename Alloc>
// const T& DS::List<T, Alloc>::front() const
// {

// }

// template <typename T, typename Alloc>
// T& DS::List<T, Alloc>::back()
// {

// }

// template <typename T, typename Alloc>
// const T& DS::List<T, Alloc>::back() const
// {

// }

// template <typename T, typename Alloc>
// bool DS::List<T, Alloc>::empty() const noexcept
// {

// }

// template <typename T, typename Alloc>
// std::size_t DS::List<T, Alloc>::size() const noexcept
// {

// }

// template <typename T, typename Alloc>
// std::size_t DS::List<T, Alloc>::max_size() const noexcept
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::clear() noexcept
// {
    
// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator DS::List<T, Alloc>::begin() noexcept
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Const_Iterator DS::List<T, Alloc>::cbegin() const noexcept
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator DS::List<T, Alloc>::end() noexcept
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Const_Iterator DS::List<T, Alloc>::cend() const noexcept
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Reverse_Iterator DS::List<T, Alloc>::rbegin() noexcept
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Const_Reverse_Iterator DS::List<T, Alloc>::crbegin() const noexcept
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Reverse_Iterator DS::List<T, Alloc>::rend() noexcept
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Const_Reverse_Iterator DS::List<T, Alloc>::crend() const noexcept
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator DS::List<T, Alloc>::insert(DS::List<T, Alloc>::Const_Iterator pos, const T& value)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator DS::List<T, Alloc>::insert(DS::List<T, Alloc>::Const_Iterator pos, T&& value)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator DS::List<T, Alloc>::insert(DS::List<T, Alloc>::Const_Iterator pos, std::size_t count, const T& value)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator DS::List<T, Alloc>::insert(DS::List<T, Alloc>::Const_Iterator pos, DS::List<T, Alloc>::Iterator first, DS::List<T, Alloc>::Iterator last)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator DS::List<T, Alloc>::insert(DS::List<T, Alloc>::Const_Iterator pos, std::initializer_list<T> ilist)
// {

// }

// template <typename T, typename Alloc>
// template <typename... Args>
// typename DS::List<T, Alloc>::Iterator DS::List<T, Alloc>::emplace(Const_Iterator pos, Args&&... args)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator DS::List<T, Alloc>::erase(DS::List<T, Alloc>::Const_Iterator pos)
// {

// }

// template <typename T, typename Alloc>
// typename DS::List<T, Alloc>::Iterator DS::List<T, Alloc>::erase(DS::List<T, Alloc>::Const_Iterator first, DS::List<T, Alloc>::Const_Iterator last)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::push_back(const T& value)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::push_back(T&& value)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::pop_back()
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::push_front(const T& value)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::push_front(T&& value)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::pop_front()
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::resize(std::size_t count)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::resize(std::size_t count, const T& value)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::swap(DS::List<T, Alloc>& other)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::merge(DS::List<T, Alloc>& other)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::merge(DS::List<T, Alloc>&& other)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::splice(DS::List<T, Alloc>::Const_Iterator pos, DS::List<T, Alloc>& other)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::splice(DS::List<T, Alloc>::Const_Iterator pos, DS::List<T, Alloc>&& other)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::splice(DS::List<T, Alloc>::Const_Iterator pos, DS::List<T, Alloc>& other, DS::List<T, Alloc>::Const_Iterator it)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::splice(DS::List<T, Alloc>::Const_Iterator pos, DS::List<T, Alloc>&& other, DS::List<T, Alloc>::Const_Iterator it)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::splice(DS::List<T, Alloc>::Const_Iterator pos, DS::List<T, Alloc>& other, DS::List<T, Alloc>::Const_Iterator first, DS::List<T, Alloc>::Const_Iterator last)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::splice(DS::List<T, Alloc>::Const_Iterator pos, DS::List<T, Alloc>&& other, DS::List<T, Alloc>::Const_Iterator first, DS::List<T, Alloc>::Const_Iterator last)
// {

// }

// template <typename T, typename Alloc>
// std::size_t DS::List<T, Alloc>::remove(const T& value)
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::reverse() noexcept
// {

// }

// template <typename T, typename Alloc>
// std::size_t DS::List<T, Alloc>::unique()
// {

// }

// template <typename T, typename Alloc>
// void DS::List<T, Alloc>::sort()
// {

// }

// template <typename T, typename Alloc>
// bool DS::operator==(const DS::List<T, Alloc>& lhs, const DS::List<T, Alloc>& rhs)
// {

// }

// template <typename T, typename Alloc>
// bool DS::operator!=( const DS::List<T, Alloc>& lhs, const DS::List<T, Alloc>& rhs)
// {

// }

// template <typename T, typename Alloc>
// bool DS::operator<(const DS::List<T, Alloc>& lhs, const DS::List<T, Alloc>& rhs)
// {

// }

// template <typename T, typename Alloc>
// bool DS::operator<=(const DS::List<T, Alloc>& lhs, const DS::List<T, Alloc>& rhs)
// {

// }

// template <typename T, typename Alloc>
// bool DS::operator>(const DS::List<T, Alloc>& lhs, const DS::List<T, Alloc>& rhs)
// {

// }

// template <typename T, typename Alloc>
// bool DS::operator>=(const DS::List<T, Alloc>& lhs, const DS::List<T, Alloc>& rhs)
// {

// }


// template <typename T, typename Alloc>
// void DS::swap(DS::List<T, Alloc>& lhs, DS::List<T, Alloc>& rhs) noexcept(lhs.swap(rhs))
// {

// }

// template <typename T, typename Alloc, typename U>
// std::size_t DS::erase(DS::List<T, Alloc>& c, const U& value)
// {

// }