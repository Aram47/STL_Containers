#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iostream>

namespace DS
{

template <typename T>
class Unique_Ptr
{
public:
    Unique_Ptr(const Unique_Ptr&) = delete;

    template<class U> 
    explicit Unique_Ptr(U p) noexcept;
    constexpr Unique_Ptr() noexcept;
    Unique_Ptr(Unique_Ptr&& u) noexcept;
    explicit Unique_Ptr(T* p) noexcept;
    constexpr Unique_Ptr(std::nullptr_t) noexcept;
    ~Unique_Ptr();

    Unique_Ptr& operator=(const Unique_Ptr&) = delete;
    Unique_Ptr& operator=(Unique_Ptr&& r) noexcept;
    Unique_Ptr& operator=(std::nullptr_t) noexcept;

    T* release() noexcept;

    template<class U>
    void reset(U ptr) noexcept;
    void reset(T* ptr = T()) noexcept;
    void reset(std::nullptr_t = nullptr) noexcept;
    void swap(Unique_Ptr& other) noexcept;
    T* get() const noexcept;

    template <typename D>
    D& get_deleter() noexcept;
    template <typename D>
    const D& get_deleter() const noexcept;

    explicit operator bool() const noexcept;

    T& operator*() const noexcept(noexcept(*std::declval<T*>()));;
    T* operator->() const noexcept;
    T& operator[](std::size_t i) const;
};

template <typename T>
void DS::swap(DS::Unique_Ptr<T>& lhs, DS::Unique_Ptr<T>& rhs) noexcept;
template <typename T1, typename T2>
bool DS::operator==(const DS::Unique_Ptr<T1>& x, const DS::Unique_Ptr<T2>& y);
template <typename T1, typename T2>
bool DS::operator!=(const DS::Unique_Ptr<T1>& x, const DS::Unique_Ptr<T2>& y);
template<typename T1, typename T2>
bool DS::operator<(const DS::Unique_Ptr<T1>& x, const DS::Unique_Ptr<T2>& y);
template<typename T1, typename T2>
bool DS::operator<=(const DS::Unique_Ptr<T1>& x, const DS::Unique_Ptr<T2>& y);
template<typename T1, typename T2>
bool DS::operator>(const DS::Unique_Ptr<T1>& x, const DS::Unique_Ptr<T2>& y);
template<typename T1, typename T2>
bool DS::operator>=( const DS::Unique_Ptr<T1>& x, const DS::Unique_Ptr<T2>& y);
template<typename T>
bool DS::operator==(const DS::Unique_Ptr<T>& x, std::nullptr_t) noexcept;
template<typename T>
bool DS::operator==(std::nullptr_t, const DS::Unique_Ptr<T>& x) noexcept;
template<typename T>
bool DS::operator!=(const DS::Unique_Ptr<T>& x, std::nullptr_t) noexcept;
template<typename T>
bool DS::operator!=(std::nullptr_t, const DS::Unique_Ptr<T>& x) noexcept;
template<typename T>
bool DS::operator<(const DS::Unique_Ptr<T>& x, std::nullptr_t);
template<typename T>
bool DS::operator<(std::nullptr_t, const DS::Unique_Ptr<T>& y);
template<typename T>
bool DS::operator<=(const DS::Unique_Ptr<T>& x, std::nullptr_t);
template<typename T>
bool DS::operator<=(std::nullptr_t, const DS::Unique_Ptr<T>& y);
template<typename T>
bool DS::operator>(const DS::Unique_Ptr<T>& x, std::nullptr_t);
template<typename T>
bool DS::operator>(std::nullptr_t, const DS::Unique_Ptr<T>& y);
template<typename T>
bool DS::operator>=(const DS::Unique_Ptr<T>& x, std::nullptr_t);
template<typename T>
bool DS::operator>=(std::nullptr_t, const DS::Unique_Ptr<T>& y);
template <typename CharT, typename Traits, typename T>
std::basic_ostream<CharT, Traits>& DS::operator<<(std::basic_ostream<CharT, Traits>& os, const DS::Unique_Ptr<T>& p);

}

#include "../../src/smartpointers/uniqueotr.hpp"

#endif