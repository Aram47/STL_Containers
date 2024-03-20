#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>

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
    bool operator<(const Base_Iterator& rhv) const;
    bool operator>(const Base_Iterator& rhv) const;
    bool operator<=(const Base_Iterator& rhv) const;
    bool operator>=(const Base_Iterator& rhv) const;
    bool operator==(const Base_Iterator& rhv) const;
    bool operator!=(const Base_Iterator& rhv) const;

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

    const T& operator*(); // return *ptr
    const T* operator->(); // return ptr
    Const_Iterator& operator++();
    Const_Iterator& operator++(int); // return temp
    Const_Iterator& operator--();
    Const_Iterator& operator--(int);
    const Const_Iterator operator+(long long int) const;
    const Const_Iterator operator-(long long int) const;
    Const_Iterator& operator+=(long long int);
    Const_Iterator& operator-=(long long int);
    const T& operator[](std::size_t) const;
  };

  class Iterator : public Const_Iterator
  {
    friend class Vector<T>;
  public:
    Iterator();
    Iterator(const Base_Iterator& rhv);
    Iterator(Base_Iterator&& rhv);

    const Iterator& operator=(const Base_Iterator&);
    const Iterator& operator=(Base_Iterator&&);

    T& operator*();
    T* operator->();
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

    const T& operator*(); // return *ptr
    const T* operator->(); // return ptr

    Const_Reverse_Iterator& operator++();
    Const_Reverse_Iterator& operator++(int); // return temp
    Const_Reverse_Iterator& operator--();
    Const_Reverse_Iterator& operator--(int);
    const Const_Reverse_Iterator operator+(long long int) const;
    const Const_Reverse_Iterator operator-(long long int) const;
    Const_Reverse_Iterator& operator+=(long long int);
    Const_Reverse_Iterator& operator-=(long long int);
    const T& operator[](std::size_t) const;
  };

  class Reverse_Iterator : public Const_Reverse_Iterator
  {
    friend class Vector<T>;
  public:
    Reverse_Iterator();
    Reverse_Iterator(const Base_Iterator& rhv);
    Reverse_Iterator(Base_Iterator&& rhv);

    const Reverse_Iterator& operator=(const Base_Iterator&);
    const Reverse_Iterator& operator=(Base_Iterator&&);

    T& operator*();
    T* operator->();
    T& operator[](std::size_t);
  protected:
    explicit Reverse_Iterator(T* ptr);
  };

  // Constructors
  Vector();
  Vector(const Vector& other);
  Vector(Vector&& other) noexcept;
  Vector(std::initializer_list<T> list);
  explicit Vector(int count);
  explicit Vector(int count, const T& value);
  // Destructor
  ~Vector();

  // Assignment operators
  Vector& operator=(const Vector& other);
  Vector& operator=(Vector&& other) noexcept;
  Vector& operator=(std::initializer_list<T> list);

  // Element access
  Const_Iterator operator[](int index);
  Const_Iterator operator[](int index) const;

  // Comparison operators
  bool operator==(const Vector<T>& other) const;
  bool operator!=(const Vector<T>& other) const;
  bool operator<(const Vector<T>& other) const;
  bool operator<=(const Vector<T>& other) const;
  bool operator>(const Vector<T>& other) const;
  bool operator>=(const Vector<T>& other) const;

  // Element access
  T& operator[](std::size_t pos);
  const T& operator[](std::size_t pos) const;
  T& at(int pos);
  const T& at(int pos) const;
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
  void reserve(std::size_t new_cap);
  std::size_t capacity() const noexcept;
  void shrink_to_fit() noexcept;

  // Modifiers
  void clear() noexcept;
  Iterator insert(Const_Iterator pos, const T& value);
  Iterator insert(Const_Iterator pos, int count, const T& value);
  Iterator insert(Const_Iterator pos, int first, int last);
  Iterator insert(Const_Iterator pos, std::initializer_list<T> list);
  template<typename... Args>
  Iterator emplace(Const_Iterator pos, Args&&... args);
  Iterator erase(Const_Iterator pos);
  Iterator erase(Const_Iterator first, Const_Iterator last);
  void push_back(const T& value);
  void push_back(T&& value);
  template<typename... Args>
  T& emplace_back(Args&&... args);
  void pop_back();
  void resize(std::size_t count);
  void resize(std::size_t count, const T& value);
  void swap(Vector& other);
};

}

#include "../src/vector.hpp"


#endif // VECTOR_HPP