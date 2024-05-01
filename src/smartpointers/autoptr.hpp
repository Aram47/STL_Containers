#include <iostream>
#include "../../header/smartpointers/autoptr.h"

template <typename T, typename X>
DS::Auto_Ptr<T>::Auto_Ptr(X* p) throw() 
{
    
}

template <typename T>
DS::Auto_Ptr<T>::Auto_Ptr(DS::Auto_Ptr<T>& r) throw()
{

}

template <typename T, typename Y>
DS::Auto_Ptr<T>::Auto_Ptr(DS::Auto_Ptr<Y>& r) throw()
{

}

template <typename T, typename X>
DS::Auto_Ptr<T>::Auto_Ptr(DS::Auto_Ptr<X>& m) throw()
{

}

template <typename T>
DS::Auto_Ptr<T>::~Auto_ptr() throw()
{

}

template <typename T>
typename DS::Auto_Ptr<T>& DS::Auto_Ptr<T>::operator=(DS::Auto_Ptr<T>& r) throw()
{

}

template <typename T, typename Y>
typename DS::Auto_Ptr<T>& DS::Auto_Ptr<T>::operator=(DS::Auto_Ptr<Y>& r) throw()
{

}

template <typename T>
typename DS::Auto_Ptr<T>& DS::Auto_Ptr<T>::operator=(DS::Auto_Ptr<T>& m) throw()
{

}

template <typename T, typename Y>
DS::Auto_Ptr<T>::operator DS::Auto_Ptr<Y>&() throw()
{

}

template <typename T, typename Y>
DS::Auto_Ptr<T>::operator DS::Auto_Ptr<Y>() throw()
{

}

template <typename T>
T* DS::Auto_Ptr<T>::get() const throw()
{

}

template <typename T>
T& DS::Auto_Ptr<T>::operator*() const throw()
{

}

template <typename T>
T* DS::Auto_Ptr<T>::operator->() const throw()
{

}

template <typename T>
void DS::Auto_Ptr<T>::reset(T* p) throw()
{

}

template <typename T>
T* DS::Auto_Ptr<T>::release() throw()
{

}