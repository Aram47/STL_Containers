#include <iostream>
#include "../header/allocator.h"


template <typename T>
DS::Allocator<T>::Allocator() noexcept
{

}

template <typename T>
DS::Allocator<T>::Allocator(const DS::Allocator<T>& other) noexcept
{

}

template <typename T>
template<class U>
DS::Allocator<T>::Allocator(const DS::Allocator<U>& other) noexcept
{

}

template <typename T>
DS::Allocator<T>::Allocator(DS::Allocator<T>&&)
{

}

template <typename T>
DS::Allocator<T>::~Allocator() noexcept
{

}

template <typename T>
T* DS::Allocator<T>::address(T& x) const noexcept
{

}

template <typename T>
const T* DS::Allocator<T>::address(const T& x) const noexcept
{

}

template <typename T>
T* DS::Allocator<T>::allocate(std::size_t n, const void* hint = 0)
{

}

template <typename T>
T* DS::Allocator<T>::allocate(std::size_t n )
{

}

template <typename T>
void DS::Allocator<T>::deallocate(T* p, std::size_t n) noexcept
{

}

template <typename T>
std::size_t DS::Allocator<T>::max_size() const noexcept
{
    
}

template <typename T>
template<typename U, typename... Args>
void DS::Allocator<T>::construct(U* p, Args&&... args)
{

}

template <typename T>
template<typename U>
void DS::Allocator<T>::destroy(U* p)
{

}

template<typename T, typename U>
inline bool DS::operator==(const DS::Allocator<T>&, const DS::Allocator<U>&) noexcept
{
    
}

template<typename T, typename U>
inline bool DS::operator!=(const DS::Allocator<T>&, const DS::Allocator<U>&) noexcept
{

}