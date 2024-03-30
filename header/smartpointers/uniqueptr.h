#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iostream>
#include <memory>
#include "./autoptr.h"

template <typename T, typename Deleter = std::default_delete<T>> 
class Unique_Ptr;

template <typename T, typename Deleter> 
class Unique_Ptr<T[], Deleter>;

namespace DS
{

template <typename T, typename Deleter>
class Unique_Ptr
{
private:
    T* ptr = nullptr;
public:
    Unique_Ptr(const Unique_Ptr&) = delete;
    constexpr Unique_Ptr() noexcept;
    constexpr Unique_Ptr(std::nullptr_t) noexcept;
    explicit Unique_Ptr(T* p) noexcept;
    Unique_Ptr(T* p, const Deleter& d1) noexcept;
    Unique_Ptr(T* p, Deleter&& d2 ) noexcept;
    Unique_Ptr(Unique_Ptr&& u) noexcept;
    template <typename U, typename E>
    Unique_Ptr(Unique_Ptr<U, E>&& u) noexcept;
    template <typename U>
    Unique_Ptr(DS::Auto_Ptr<U>&& u) noexcept;
    ~Unique_Ptr();

    Unique_Ptr& operator=(const Unique_Ptr&) = delete;
    Unique_Ptr& operator=(Unique_Ptr&& r) noexcept;
    template <typename U, typename E>
    Unique_Ptr& operator=(Unique_Ptr<U, E>&& r) noexcept;
    Unique_Ptr& operator=(std::nullptr_t) noexcept;

    T* release() noexcept;
    void reset(T* ptr = T()) noexcept;
    template <typename U>
    void DS::Unique_Ptr<T[],Deleter>::reset(U ptr) noexcept;
    void DS::Unique_Ptr<T[],Deleter>::reset(std::nullptr_t = nullptr) noexcept;
    void swap(Unique_Ptr& other) noexcept;
    T* get() const noexcept;
    Deleter& get_deleter() noexcept;
    const Deleter& get_deleter() const noexcept;
    explicit operator bool() const noexcept;

    typename std::add_lvalue_reference<T>::type operator*() const noexcept(noexcept(*std::declval<T*>()));
    T* operator->() const noexcept;
    T& operator[](std::size_t i) const;
};

// template <typename T,typename... Args>
// constexpr Unique_Ptr<T, Args...> make_unique(Args&&... args); // only for non array types
template <typename T, typename Deleter>
constexpr Unique_Ptr<T, Deleter> make_unique(std::size_t size);
// template <typename T, typename... Args>
// Unique_Ptr<T, Args...> make_unique(Args&&... args) = delete; // only for array types
template <typename T, typename Deleter>
constexpr Unique_Ptr<T, Deleter> make_unique_for_overwrite();
template <typename T, typename Deleter>
constexpr Unique_Ptr<T, Deleter> make_unique_for_overwrite(std::size_t size);
// template <typename T, typename... Args >
// Unique_Ptr<T, Args...> make_unique_for_overwrite(Args&&... args) = delete;

template <typename T1, typename D1, typename T2, typename D2 >
bool operator==(const Unique_Ptr<T1, D1>& x, const Unique_Ptr<T2, D2>& y);
template <typename T1, typename D1, typename T2, typename D2>
bool operator!=(const Unique_Ptr<T1, D1>& x, const Unique_Ptr<T2, D2>& y);
template <typename T1, typename D1, typename T2, typename D2>
bool operator<(const Unique_Ptr<T1, D1>& x, const Unique_Ptr<T2, D2>& y);
template <typename T1, typename D1, typename T2, typename D2 >
bool operator<=(const Unique_Ptr<T1, D1>& x, const Unique_Ptr<T2, D2>& y);
template <typename T1, typename D1, typename T2, typename D2>
bool operator>(const Unique_Ptr<T1, D1>& x, const Unique_Ptr<T2, D2>& y);
template <typename T1, typename D1, typename T2, typename D2>
bool operator>=(const DS::Unique_Ptr<T1, D1>& x, const Unique_Ptr<T2, D2>& y);
template <typename T, typename D>
bool operator==(const Unique_Ptr<T, D>& x, std::nullptr_t) noexcept;
template <typename T, typename D>
bool operator==(std::nullptr_t, const Unique_Ptr<T, D>& x) noexcept;
template <typename T, typename D>
bool operator!=(const Unique_Ptr<T, D>& x, std::nullptr_t) noexcept;
template <typename T, typename D>
bool operator!=(std::nullptr_t, const Unique_Ptr<T, D>& x) noexcept;
template <typename T, typename D>
bool operator<(const Unique_Ptr<T, D>& x, std::nullptr_t);
template <typename T, typename D>
bool operator<(std::nullptr_t, const Unique_Ptr<T, D>& y);
template <typename T, typename D>
bool operator<=(const Unique_Ptr<T, D>& x, std::nullptr_t);
template <typename T, typename D>
bool operator<=(std::nullptr_t, const Unique_Ptr<T, D>& y);
template <typename T, typename D>
bool operator>(const Unique_Ptr<T, D>& x, std::nullptr_t);
template <typename T, typename D>
bool operator>(std::nullptr_t, const Unique_Ptr<T, D>& y);
template <typename T, typename D>
bool operator>=(const Unique_Ptr<T, D>& x, std::nullptr_t);
template <typename T, typename D>
bool operator>=(std::nullptr_t, const Unique_Ptr<T, D>& y);

}

#include "../../src/smartpointers/uniqueotr.hpp"

#endif