#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace DS {

template<typename T>
class Vector {
private:
  T* m_array;
  std::size_t m_size;
  std::size_t m_capacity;

public:

  class Const_Iterator
  {
    friend class Vector;
  private:
    T* ptr;
  protected:
    explicit Const_Iterator(T* p) : ptr(p) {};
  public:
    Const_Iterator() : ptr(nullptr) {};
    Const_Iterator(const Const_Iterator& other);
    Const_Iterator(Const_Iterator&& other);

    const Const_Iterator& operator=(const Const_Iterator&);
    const Const_Iterator& operator=(const Const_Iterator&);

    const T& operator*();
    const T* operator->();
  };

  class Iterator : public Const_Iterator
  {

  };

  class Const_Reverse_Iterator 
  {

  };

  class Reverse_Iterator : public Const_Reverse_Iterator
  {

  };

  // Constructors
  Vector();
  Vector(const Vector& other);
  Vector(Vector&& other) noexcept;
  explicit Vector(int count);
  explicit Vector(int count, const T& value);
  // Destructor
  ~Vector();

  // Assignment operators
  Vector& operator=(const Vector& other);
  constexpr Vector& operator=( const Vector& other);
  Vector& operator=(Vector&& other) noexcept;
  Vector& operator=(Vector&& other) noexcept;
  Vector& operator=(std::initializer_list<T> list);
  constexpr Vector& operator=( std::initializer_list<T> list);

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
  T& operator[](int pos);
  const T& operator[](int pos) const;
  T& at(int pos);
  const T& at(size_type pos) const;
  T& front();
  const T& front() const;
  T& back();
  const T& back() const;
  T* data() noexcept;
  const T* data() const noexcept;

  // Iterators
  Iterator begin() noexcept;
  Const_Iterator begin() const noexcept;
  Const_Iterator cbegin() const noexcept;
  Iterator end() noexcept;
  Const_Iterator end() const noexcept;
  Const_Iterator cend() const noexcept;
  Reverse_Iterator rbegin() noexcept;
  Const_Reverse_Iterator rbegin() const noexcept;
  Const_Reverse_Iterator crbegin() const noexcept;
  Reverse_Iterator rend() noexcept;
  Const_Reverse_Iterator rend() const noexcept;
  Const_Reverse_Iterator crend() const noexcept;

  // Capacity
  bool empty() const noexcept;
  std::size_t size() const noexcept;
  std::size_t max_size() const noexcept;
  void reserve(int new_cap);
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
  void resize(int count);
  void resize(int count, const T& value);
  void swap(Vector& other);
};

}

#include "../src/vector.tcc"


#endif // VECTOR_HPP

