// #ifndef WEAK_PTR_H
// #define WEAK_PTR_H

// #include <iostream>
// #include <atomic>
// #include "./sharedptr.h"

// template <typename T> 
// struct std::atomic<DS::Weak_Ptr<T>>;

// namespace DS
// {
// template <typename T>
// class Weak_Ptr
// {
// private:
//     T* ptr = nullptr;
// public:
//     constexpr Weak_Ptr() noexcept;
//     Weak_Ptr(const Weak_Ptr& r) noexcept;
//     template <typename Y>
//     Weak_Ptr(const Weak_Ptr<Y>& r) noexcept;
//     template <typename Y>
//     Weak_Ptr(const DS::Shared_Ptr<Y>& r) noexcept;
//     Weak_Ptr(Weak_Ptr&& r) noexcept;
//     template <typename Y>
//     Weak_Ptr(Weak_Ptr<Y>&& r) noexcept;
//     ~Weak_ptr();

//     Weak_Ptr& operator=(const Weak_Ptr& r) noexcept;
//     template <typename Y>
//     Weak_Ptr& operator=(const Weak_Ptr<Y>& r) noexcept;
//     template <typename Y>
//     Weak_Ptr& operator=(const DS::Shared_Ptr<Y>& r) noexcept;
//     Weak_Ptr& operator=(Weak_Ptr&& r) noexcept;
//     template <typename Y>
//     Weak_Ptr& operator=(Weak_Ptr<Y>&& r ) noexcept;

//     void reset() noexcept;
//     void swap(Weak_Ptr& r) noexcept;
//     long use_count() const noexcept;
//     bool expired() const noexcept;
//     DS::Shared_Ptr<T> lock() const noexcept;

//     template <typename Y>
//     bool owner_before(const Weak_Ptr<Y>& other) const noexcept;
//     template <template Y>
//     bool owner_before(const DS::Shared_Ptr<Y>& other) const noexcept;

//     std::size_t owner_hash() const noexcept;
//     template <typename Y>
//     bool owner_equal(const Weak_Ptr<Y>& other) const noexcept;
//     template <typename Y>
//     bool owner_equal(const DS::Shared_Ptr<Y>& other) const noexcept;
// };


// };

// template<typename T>
// void swap(DS::Weak_Ptr<T>& lhs, DS::Weak_Ptr<T>& rhs) noexcept;

// #include "../../src/smartpointers/weakptr.hpp"

// #endif