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
    explicit Auto_Ptr(X* p = 0) throw();
    Auto_Ptr(Auto_Ptr& r) throw();
    template <typename Y>
    Auto_Ptr(Auto_Ptr<Y>& r) throw();
    template <typename X>
    Auto_Ptr(Auto_Ptr<X>& m) throw();
    ~Auto_ptr() throw();

    Auto_Ptr& operator=(Auto_Ptr& r) throw();
    template <typename Y>
    Auto_Ptr& operator=(Auto_Ptr<Y>& r) throw();
    Auto_Ptr& operator=(Auto_Ptr<T>& m) throw();

    template <typename Y>
    operator Auto_Ptr<Y>&() throw();
    template <typename Y>
    operator Auto_Ptr<Y>() throw();

    T* get() const throw();

    T& operator*() const throw();
    T* operator->() const throw();

    void reset(T* p = 0) throw();
    T* release() throw();
};
}

#include "../../src/smartpointers/autoptr.hpp"

#endif