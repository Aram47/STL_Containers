#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <iterator>

namespace DS {

template<typename T, typename Allocator = std::allocator<T>>
class Vector {
private:
    T* m_array;
    std::size_t m_size;
    std::size_t m_capacity;

public:
    // Type aliases
    using value_type = typename std::vector<T, Allocator>::value_type;
    using allocator_type = typename std::vector<T, Allocator>::allocator_type;
    using size_type = typename std::vector<T, Allocator>::size_type;
    using difference_type = typename std::vector<T, Allocator>::difference_type;
    using reference = typename std::vector<T, Allocator>::reference;
    using const_reference = typename std::vector<T, Allocator>::const_reference;
    using pointer = typename std::vector<T, Allocator>::pointer;
    using const_pointer = typename std::vector<T, Allocator>::const_pointer;
    using iterator = typename std::vector<T, Allocator>::iterator;
    using const_iterator = typename std::vector<T, Allocator>::const_iterator;
    using reverse_iterator = typename std::vector<T, Allocator>::reverse_iterator;
    using const_reverse_iterator = typename std::vector<T, Allocator>::const_reverse_iterator;

    // Constructors
    Vector();
    explicit Vector(size_type count);
    explicit Vector(size_type count, const T& value);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;

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
    reference operator[](int index);
    const_reference operator[](int index) const;

    // Comparison operators
    bool operator==(const Vector<T>& other) const;
    bool operator!=(const Vector<T>& other) const;
    bool operator<(const Vector<T>& other) const;
    bool operator<=(const Vector<T>& other) const;
    bool operator>(const Vector<T>& other) const;
    bool operator>=(const Vector<T>& other) const;

    // Element access
    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;
    reference at(size_type pos);
    const_reference at(size_type pos) const;
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    T* data() noexcept;
    const T* data() const noexcept;

    // Iterators
    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;
    const_reverse_iterator crend() const noexcept;

    // Capacity
    bool empty() const noexcept;
    size_type size() const noexcept;
    size_type max_size() const noexcept;
    void reserve(size_type new_cap);
    size_type capacity() const noexcept;
    void shrink_to_fit() noexcept;

    // Modifiers
    void clear() noexcept;
    iterator insert(const_iterator pos, const T& value);
    iterator insert(const_iterator pos, size_type count, const T& value);
    template<typename InputIt>
    iterator insert(const_iterator pos, InputIt first, InputIt last);
    iterator insert(const_iterator pos, std::initializer_list<T> list);
    template<typename... Args>
    iterator emplace(const_iterator pos, Args&&... args);
    iterator erase(const_iterator pos);
    iterator erase(const_iterator first, const_iterator last);
    void push_back(const T& value);
    void push_back(T&& value);
    template<typename... Args>
    reference emplace_back(Args&&... args);
    void pop_back();
    void resize(size_type count);
    void resize(size_type count, const value_type& value);
    void swap(Vector& other);
};

}

#include "../src/vector.tcc"


#endif // VECTOR_HPP

