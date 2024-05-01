#ifndef AUTO_PTR_H
#define AUTO_PTR_H

#include <iostream>

namespace DS
{

template <typename T>
class Auto_Ptr
{
private:
    T* ptr = nullptr;
public:
    template <typename X>
    explicit Auto_Ptr(X* = 0) throw();
    Auto_Ptr(Auto_Ptr&) throw();
    template <typename Y>
    Auto_Ptr(Auto_Ptr<Y>&) throw();
    template <typename X>
    Auto_Ptr(Auto_Ptr<X>&) throw();
    ~Auto_ptr() throw();

    Auto_Ptr& operator=(Auto_Ptr&) throw();
    template <typename Y>
    Auto_Ptr& operator=(Auto_Ptr<Y>&) throw();
    Auto_Ptr& operator=(Auto_Ptr<T>&) throw();

    template <typename Y>
    operator Auto_Ptr<Y>&() throw();
    template <typename Y>
    operator Auto_Ptr<Y>() throw();

    T* get() const throw();

    T& operator*() const throw();
    T* operator->() const throw();

    void reset(T* = 0) throw();
    T* release() throw();
};

template <>
class Auto_Ptr<void> {};

}

#include "../../src/smartpointers/autoptr.hpp"

#endif