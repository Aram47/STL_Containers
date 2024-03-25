#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include "../header/allocator.h"


template <typename T>
T* DS::Allocator<T>::address(T& x) const noexcept
{   
    return std::addressof(x);
}

template <typename T>
const T* DS::Allocator<T>::address(const T& x) const noexcept
{
    return std::addressof(x);
}

template <typename T>
T* DS::Allocator<T>::allocate(std::size_t n)
{
    if (n >= DS::Allocator<T>::max_size())
        throw std::bad_alloc();

    return static_cast<T*>(::operator new(n * sizeof(T)));
}

template <typename T>
void DS::Allocator<T>::deallocate(T* p, std::size_t n) noexcept
{
    ::operator delete(p);
}

template <typename T>
std::size_t DS::Allocator<T>::max_size() const noexcept
{
    std::size_t elem_size = sizeof(T);
    std::size_t max_bytes, max_elements;

    max_bytes = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE);
    max_elements = max_bytes / elem_size;

    return max_elements;
}

template <typename T>
void DS::Allocator<T>::construct(T* p, const T& val)
{
    new (p) T{val};
}

template <typename T>
void DS::Allocator<T>::destroy(T* p)
{
    p -> ~T();
}