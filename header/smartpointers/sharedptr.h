#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <iostream>
#include <atomic>
#include "./weakptr.h"
#include "./autoptr.h"
#include "./uniqueptr.h"

template <typename T>
struct std::atomic<DS::Shared_Ptr<T>>;
template< class T >
struct std::hash<DS::Shared_Ptr<T>>;

namespace DS
{

template <typename T>
class Shared_Ptr
{
private:
    T* ptr = nullptr;
public:
    constexpr Shared_Ptr() noexcept;
    constexpr Shared_Ptr(std::nullptr_t) noexcept;
    template <typename Y>
    explicit Shared_Ptr(Y* ptr);
    template <typename Y, typename Deleter>
    Shared_Ptr(Y* ptr, Deleter d);
    template <typename Deleter>
    Shared_Ptr(std::nullptr_t ptr, Deleter d);
    template <typename Y, typename Deleter, typename Alloc>
    Shared_Ptr(Y* ptr, Deleter d, Alloc alloc);
    template <typename Deleter, typename Alloc>
    Shared_Ptr(std::nullptr_t ptr, Deleter d, Alloc alloc);
    template <typename Y>
    Shared_Ptr(const Shared_Ptr<Y>& r, T* ptr) noexcept;
    template <typename Y>
    Shared_Ptr(Shared_Ptr<Y>&& r, T* ptr) noexcept;
    Shared_Ptr(const Shared_Ptr& r) noexcept;
    template <typename Y>
    Shared_Ptr(const Shared_Ptr<Y>& r) noexcept;
    shared_ptr(Shared_Ptr&& r) noexcept;	
    template<typename Y>
    Shared_Ptr(Shared_Ptr<Y>&& r) noexcept;	
    template <typename Y>
    explicit Shared_Ptr(const DS::Weak_Ptr<Y>& r);	
    template <typename Y>
    Shared_Ptr(DS::Auto_Ptr<Y>&& r);
    // template <typename Y, typename Deleter>
    // Shared_Ptr(DS::Unique_Ptr<Y, Deleter>&& r);
    ~Shared_Ptr();

    Shared_Ptr& operator=(const Shared_Ptr& r) noexcept;
    template <typename Y >
    Shared_Ptr& operator=(const Shared_Ptr<Y>& r) noexcept;
    Shared_Ptr& operator=(Shared_Ptr&& r) noexcept;
    template <typename Y >
    Shared_Ptr& operator=(Shared_Ptr<Y>&& r) noexcept;
    template <typename Y>
    Shared_Ptr& operator=(DS::Auto_Ptr<Y>&& r);
    template <typename Y, typename Deleter>
    Shared_Ptr& operator=(DS::Unique_Ptr<Y, Deleter>&& r);

    void reset() noexcept;
    template <typename Y>
    void reset(Y* ptr);
    template <typename Y, typename Deleter>
    void reset(Y* ptr, Deleter d);
    template <typename Y, typename Deleter, typename Alloc>
    void reset(Y* ptr, Deleter d, Alloc alloc);

    void swap(Shared_Ptr& r) noexcept;
    T* get() const noexcept;

    T& operator*() const noexcept;
    T* operator->() const noexcept;

    T& operator[](std::ptrdiff_t idx) const;
    long use_count() const noexcept;
    bool unique() const noexcept;

    explicit operator bool() const noexcept;

    template <typename Y>
    bool owner_before(const Shared_Ptr<Y>& other) const noexcept;
    template <typename Y>
    bool owner_before(const Ds::Weak_Ptr<Y>& other) const noexcept;
    std::size_t owner_hash() const noexcept;

    template <typename Y>
    bool owner_equal(const DS::Shared_Ptr<Y>& other) const noexcept;
    template <typename Y>
    bool owner_equal(const DS::Weak_Ptr<Y>& other) const noexcept;
};

template <typename T, typename... Args>
Shared_Ptr<T> DS::make_shared(Args&&... args);
template <typename T>
Shared_Ptr<T> DS::make_shared(std::size_t N);
template <typename T>
Shared_Ptr<T> DS::make_shared();
template <typename T>
Shared_Ptr<T> DS::make_shared(std::size_t N, const std::remove_extent_t<T>& u);
template <typename T>
Shared_Ptr<T> make_shared(const std::remove_extent_t<T>& u);
template <typename T>
Shared_Ptr<T> make_shared_for_overwrite();
template <typename T>
Shared_Ptr<T> make_shared_for_overwrite(std::size_t N);
template <typename T, typename Alloc, typename... Args>
Shared_Ptr<T> allocate_shared(const Alloc& alloc, Args&&... args);
template <typename T, typename Alloc>
Shared_Ptr<T> allocate_shared(const Alloc& alloc, std::size_t N);
template <typename T, typename Alloc>
Shared_Ptr<T> allocate_shared(const Alloc& alloc);
template <typename T, typename Alloc>
Shared_Ptr<T> allocate_shared(const Alloc& alloc, std::size_t N, const std::remove_extent_t<T>& u);
template <typename T, typename Alloc>
Shared_Ptr<T> allocate_shared( const Alloc& alloc, const std::remove_extent_t<T>& u);
template <typename T, typename Alloc>
Shared_Ptr<T> allocate_shared_for_overwrite(const Alloc& alloc);
template <typename T, typename Alloc>
Shared_Ptr<T> allocate_shared_for_overwrite(const Alloc& alloc, std::size_t N);
template <typename T, typename U>
Shared_Ptr<T> static_pointer_cast(const Shared_Ptr<U>& r) noexcept;
template <typename T, typename U>
Shared_Ptr<T> static_pointer_cast(Shared_Ptr<U>&& r) noexcept;
template <typename T, typename U>
Shared_Ptr<T> dynamic_pointer_cast(const Shared_Ptr<U>& r) noexcept;
template <typename T, typename U>
Shared_Ptr<T> dynamic_pointer_cast(Shared_Ptr<U>&& r) noexcept;
template <typename T, typename U>
Shared_Ptr<T> const_pointer_cast(const Shared_Ptr<U>& r) noexcept;
template <typename T, typename U>
Shared_Ptr<T> const_pointer_cast(Shared_Ptr<U>&& r) noexcept;
template <typename T, typename U>
Shared_Ptr<T> reinterpret_pointer_cast(const Shared_Ptr<U>& r) noexcept;
template <typename T, typename U>
Shared_Ptr<T> reinterpret_pointer_cast(Shared_Ptr<U>&& r) noexcept;
template <typename Deleter, typename T>
Deleter* get_deleter(const Shared_Ptr<T>& p) noexcept;
template <typename T, typename U>
bool operator==(const Shared_Ptr<T>& lhs, const Shared_Ptr<U>& rhs) noexcept;
template <typename T, typename U>
bool operator!=( const Shared_Ptr<T>& lhs, const Shared_Ptr<U>& rhs) noexcept;
template <typename T, typename U>
bool operator<(const Shared_Ptr<T>& lhs, const Shared_Ptr<U>& rhs) noexcept;
template <typename T, typename U>
bool operator>(const Shared_Ptr<T>& lhs, const Shared_Ptr<U>& rhs) noexcept;
template <typename T, typename U>
bool operator<=(const Shared_Ptr<T>& lhs, const Shared_Ptr<U>& rhs ) noexcept;
template <typename T, typename U>
bool operator>=( const Shared_Ptr<T>& lhs, const Shared_Ptr<U>& rhs) noexcept;
template <typename T>
bool operator==(const Shared_Ptr<T>& lhs, std::nullptr_t) noexcept;
template <typename T>
bool operator==(std::nullptr_t, const Shared_Ptr<T>& rhs) noexcept;
template <typename T>
bool operator!=(const Shared_Ptr<T>& lhs, std::nullptr_t) noexcept;
template <typename T>
bool operator!=(std::nullptr_t, const Shared_Ptr<T>& rhs) noexcept;
template <typename T>
bool operator<(const Shared_Ptr<T>& lhs, std::nullptr_t) noexcept;
template <typename T>
bool operator<(std::nullptr_t, const Shared_Ptr<T>& rhs) noexcept;
template <typename T>
bool operator>(const Shared_Ptr<T>& lhs, std::nullptr_t) noexcept;
template <typename T>
bool operator>(std::nullptr_t, const Shared_Ptr<T>& rhs) noexcept;
template <typename T>
bool operator<=(const Shared_Ptr<T>& lhs, std::nullptr_t) noexcept;
template <typename T>
bool operator<=(std::nullptr_t, const Shared_Ptr<T>& rhs) noexcept;
template <typename T>
bool operator>=(const Shared_Ptr<T>& lhs, std::nullptr_t) noexcept;
template <typename T>
bool operator>=(std::nullptr_t, const Shared_Ptr<T>& rhs) noexcept;
template <typename T, typename U, typename V>
std::basic_ostream<U, V>& operator<<( std::basic_ostream<U, V>& os, const Shared_Ptr<T>& ptr);
template <typename T>
void swap(Shared_Ptr<T>& lhs, Shared_Ptr<T>& rhs) noexcept;
template <typename T>
bool atomic_is_lock_free(const Shared_Ptr<T>* p);
template <typename T>
Shared_Ptr<T> atomic_load(const Shared_Ptr<T>* p);
template <typename T>
Shared_Ptr<T> atomic_load_explicit(const Shared_Ptr<T>* p, std::memory_order mo);
template <typename T>
void atomic_store(Shared_Ptr<T>* p, Shared_Ptr<T> r);
template <typename T>
void atomic_store_explicit(Shared_Ptr<T>* p, Shared_Ptr<T> r, std::memory_order mo );
template <typename T>
Shared_Ptr<T> atomic_exchange(Shared_Ptr<T>* p, Shared_Ptr<T> r);
template <typename T>
Shared_Ptr<T> atomic_exchange_explicit(Shared_Ptr<T>* p, Shared_Ptr<T> r, std::memory_order mo);
template <typename T>
bool atomic_compare_exchange_weak(Shared_Ptr<T>* p, Shared_Ptr<T>* expected, Shared_Ptr<T> desired);
template <typename T>
bool atomic_compare_exchange_strong(Shared_Ptr<T>* p, Shared_Ptr<T>* expected, Shared_Ptr<T> desired);
template <typename T>
bool atomic_compare_exchange_strong_explicit(Shared_Ptr<T>* p, Shared_Ptr<T>* expected, Shared_Ptr<T> desired, std::memory_order success, std::memory_order failure);
template <typename T>
bool atomic_compare_exchange_weak_explicit(Shared_Ptr<T>* p, Shared_Ptr<T>* expected, Shared_Ptr<T> desired, std::memory_order success, std::memory_order failure);


};

#include "../../src/smartpointers/sharedptr.hpp"

#endif