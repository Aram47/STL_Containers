#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <unistd.h> 

namespace DS {

template<typename T>
class Vector {
private:
  std::size_t m_size;
  std::size_t m_capacity;
  T* m_array;

private:

  class Base_Iterator
  {
    friend class Vector<T>;
  private:
    T* ptr = nullptr;
  public:
    ~Base_Iterator();
    bool operator<(const Base_Iterator&) const;
    bool operator>(const Base_Iterator&) const;
    bool operator<=(const Base_Iterator&) const;
    bool operator>=(const Base_Iterator&) const;
    bool operator==(const Base_Iterator&) const;
    bool operator!=(const Base_Iterator&) const;

    const Base_Iterator& operator=(const Base_Iterator&);
    const Base_Iterator& operator=(Base_Iterator&&);

  protected:
    explicit Base_Iterator(T*);
  };

public:

  class Const_Iterator : public Base_Iterator
  {
    friend class Vector<T>;
  
  protected:
    explicit Const_Iterator(T*);
  public:
    Const_Iterator();
    Const_Iterator(const Base_Iterator&);
    Const_Iterator(Base_Iterator&&);

    const Const_Iterator& operator=(const Base_Iterator&);
    const Const_Iterator& operator=(Base_Iterator&&);

    const T& operator*();
    const T* operator->();
    const Const_Iterator& operator++();
    const Const_Iterator& operator++(int);
    const Const_Iterator& operator--();
    const Const_Iterator& operator--(int);
    const Const_Iterator operator+(long long int) const;
    const Const_Iterator operator-(long long int) const;
    const Const_Iterator& operator+=(long long int);
    const Const_Iterator& operator-=(long long int);
    const T& operator[](std::size_t) const;
  };

  class Iterator : public Const_Iterator
  {
    friend class Vector<T>;
  public:
    Iterator();
    Iterator(const Base_Iterator&);
    Iterator(Base_Iterator&&);

    const Iterator& operator=(const Base_Iterator&);
    const Iterator& operator=(Base_Iterator&&);

    T& operator*();
    T* operator->();

    Iterator& operator++();
    Iterator& operator++(int);
    Iterator& operator--();
    Iterator& operator--(int);
    Iterator operator+(long long int) const;
    Iterator operator-(long long int) const;
    Iterator& operator+=(long long int);
    Iterator& operator-=(long long int);

    T& operator[](std::size_t);
  protected:
    explicit Iterator(T*);
  };

  class Const_Reverse_Iterator : public Base_Iterator
  {
    friend class Vector<T>;
  
  protected:
    explicit Const_Reverse_Iterator(T*);
  public:
    Const_Reverse_Iterator();
    Const_Reverse_Iterator(const Base_Iterator&);
    Const_Reverse_Iterator(Base_Iterator&&);

    const Const_Reverse_Iterator& operator=(const Base_Iterator&);
    const Const_Reverse_Iterator& operator=(Base_Iterator&&);

    const T& operator*();
    const T* operator->();

    const Const_Reverse_Iterator& operator++();
    const Const_Reverse_Iterator& operator++(int);
    const Const_Reverse_Iterator& operator--();
    const Const_Reverse_Iterator& operator--(int);
    const Const_Reverse_Iterator operator+(long long int) const;
    const Const_Reverse_Iterator operator-(long long int) const;
    const Const_Reverse_Iterator& operator+=(long long int);
    const Const_Reverse_Iterator& operator-=(long long int);
    const T& operator[](std::size_t) const;
  };

  class Reverse_Iterator : public Const_Reverse_Iterator
  {
    friend class Vector<T>;
  public:
    Reverse_Iterator();
    Reverse_Iterator(const Base_Iterator&);
    Reverse_Iterator(Base_Iterator&&);

    const Reverse_Iterator& operator=(const Base_Iterator&);
    const Reverse_Iterator& operator=(Base_Iterator&&);

    T& operator*();
    T* operator->();

    Reverse_Iterator& operator++();
    Reverse_Iterator& operator++(int);
    Reverse_Iterator& operator--();
    Reverse_Iterator& operator--(int);
    Reverse_Iterator operator+(long long int) const;
    Reverse_Iterator operator-(long long int) const;
    Reverse_Iterator& operator+=(long long int);
    Reverse_Iterator& operator-=(long long int);

    T& operator[](std::size_t);
  protected:
    explicit Reverse_Iterator(T*);
  };

  // Constructors
  Vector();
  Vector(const Vector&);
  Vector(Vector&&) noexcept;
  Vector(std::initializer_list<T>);
  explicit Vector(std::size_t);
  explicit Vector(int, const T&);

  // Destructor
  ~Vector();

  // Assignment operators
  Vector& operator=(const Vector&);
  Vector& operator=(Vector&&) noexcept;
  Vector& operator=(std::initializer_list<T>);

  // Comparison operators
  bool operator==(const Vector<T>&) const;
  bool operator!=(const Vector<T>&) const;
  bool operator<(const Vector<T>&) const;
  bool operator<=(const Vector<T>&) const;
  bool operator>(const Vector<T>&) const;
  bool operator>=(const Vector<T>&) const;

  // Element access
  T& operator[](std::size_t);
  const T& operator[](std::size_t) const;
  T& at(int);
  const T& at(int) const;
  T& front();
  const T& front() const;
  T& back();
  const T& back() const;
  T* data() noexcept;
  const T* data() const noexcept;

  // Iterators
  Iterator begin() noexcept;
  Const_Iterator cbegin() const noexcept;
  Iterator end() noexcept;
  Const_Iterator cend() const noexcept;
  Reverse_Iterator rbegin() noexcept;
  Const_Reverse_Iterator crbegin() const noexcept;
  Reverse_Iterator rend() noexcept;
  Const_Reverse_Iterator crend() const noexcept;

  // Capacity
  bool empty() const noexcept;
  std::size_t size() const noexcept;
  std::size_t max_size() const noexcept;
  void reserve(std::size_t);
  std::size_t capacity() const noexcept;
  void shrink_to_fit() noexcept;

  // Modifiers
  void clear() noexcept;
  Iterator insert(const Base_Iterator&, const T&);
  Iterator insert(const Base_Iterator&, int, const T&);
  Iterator insert(const Base_Iterator&, const Base_Iterator&, const Base_Iterator&);
  Iterator insert(const Base_Iterator&, std::initializer_list<T>);
  Iterator erase(const Base_Iterator&);
  Iterator erase(const Base_Iterator&, const Base_Iterator&);
  void push_back(const T&);
  void push_back(T&&);
  void pop_back();
  void resize(std::size_t);
  void resize(std::size_t, const T&);
  void swap(Vector&);
};

}

#include "../src/vector.hpp"


#endif // VECTOR_HPP