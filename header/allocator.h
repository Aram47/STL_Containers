#ifndef ALLOCATOR_H
#define ALLOCATOR_H

namespace DS
{

template<typename T>
class Allocator 
{

public:
    Allocator() noexcept;
    Allocator(const Allocator&) noexcept;
    template<class U>
    Allocator(const Allocator<U>&) noexcept;
    Allocator(Allocator&&);
    ~Allocator() noexcept;

    T* address(T&) const noexcept;
    const T* address(const T&) const noexcept;

    T* allocate(std::size_t, const void* = 0);
    T* allocate(std::size_t);
    void deallocate(T*, std::size_t) noexcept;

    std::size_t max_size() const noexcept;

    template<typename T>
    void construct(T* p, const T& val);

    template<typename U>
    void destroy(U*);
};

template<typename T, typename U>
inline bool operator==(const Allocator<T>&, const Allocator<U>&) noexcept;

template<typename T, typename U>
inline bool operator!=(const Allocator<T>&, const Allocator<U>&) noexcept;

} 

#include "../src/allocator.hpp"

#endif