#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <iostream>
#include <stdexcept>
#include <unistd.h>

namespace DS
{

template<typename T>
class Allocator 
{

public:
    Allocator() noexcept {};
    Allocator(const Allocator&) noexcept = default;
    ~Allocator() noexcept = default;

    T* address(T&) const noexcept;
    const T* address(const T&) const noexcept;

    T* allocate(std::size_t);
    void deallocate(T*, std::size_t) noexcept;

    std::size_t max_size() const noexcept;

    void construct(T* p, const T& val);

    void destroy(T*);
};

}

#include "../src/allocator.hpp"

#endif