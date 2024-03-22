#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstddef> // For size_t
#include <iterator> // For iterators

namespace DS
{


class String {
public:
    // Member types
    using value_type        = char;
    using traits_type       = std::char_traits<char>;
    using allocator_type    = std::allocator<char>;
    using reference         = char&;
    using const_reference   = const char&;
    using pointer           = char*;
    using const_pointer     = const char*;
    using iterator          = char*;
    using const_iterator    = const char*;
    using reverse_iterator  = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    using difference_type   = std::ptrdiff_t;
    using size_type         = std::size_t;

    // Member functions
    String();
    explicit String(const char* s);
    explicit String(const std::string& str);
    String(const String& other);
    String(String&& other);
    ~String();

    String& operator=(const String& other);

    // Iterators
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_iterator cbegin() const;
    const_iterator cend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;

    // Capacity
    size_type size() const;
    size_type length() const;
    size_type max_size() const;
    void resize(size_type n);
    size_type capacity() const;
    void reserve(size_type n);
    void clear();
    bool empty() const;
    void shrink_to_fit();

    // Element access
    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;
    reference at(size_type pos);
    const_reference at(size_type pos) const;
    reference back();
    const_reference back() const;
    reference front();
    const_reference front() const;

    // Modifiers
    String& operator+=(const String& str);
    String& operator+=(const char* s);
    String& operator+=(char c);
    String& append(const String& str);
    String& append(const char* s);
    String& append(const char* s, size_type n);
    String& append(size_type n, char c);
    void push_back(char c);
    String& assign(const String& str);
    String& assign(const char* s);
    String& assign(const char* s, size_type n);
    String& assign(size_type n, char c);
    String& insert(size_type pos, const String& str);
    String& insert(size_type pos, const char* s);
    String& insert(size_type pos, const char* s, size_type n);
    String& insert(size_type pos, size_type n, char c);
    String& erase(size_type pos = 0, size_type len = npos);
    String& replace(size_type pos, size_type len, const String& str);
    String& replace(size_type pos, size_type len, const char* s);
    String& replace(size_type pos, size_type len, const char* s, size_type n);
    String& replace(size_type pos, size_type len, size_type n, char c);
    void swap(String& other);
    void pop_back();

    // String operations
    const char* c_str() const;
    const char* data() const;
    allocator_type get_allocator() const;
    size_type copy(char* s, size_type len, size_type pos = 0) const;
    size_type find(const String& str, size_type pos = 0) const;
    size_type find(const char* s, size_type pos = 0) const;
    size_type find(const char* s, size_type pos, size_type n) const;
    size_type find(char c, size_type pos = 0) const;
    size_type rfind(const String& str, size_type pos = npos) const;
    size_type rfind(const char* s, size_type pos = npos) const;
    size_type rfind(const char* s, size_type pos, size_type n) const;
    size_type rfind(char c, size_type pos = npos) const;
    size_type find_first_of(const String& str, size_type pos = 0) const;
    size_type find_first_of(const char* s, size_type pos = 0) const;
    size_type find_first_of(const char* s, size_type pos, size_type n) const;
    size_type find_first_of(char c, size_type pos = 0) const;
    size_type find_last_of(const String& str, size_type pos = npos) const;
    size_type find_last_of(const char* s, size_type pos = npos) const;
    size_type find_last_of(const char* s, size_type pos, size_type n) const;
    size_type find_last_of(char c, size_type pos = npos) const;
    size_type find_first_not_of(const String& str, size_type pos = 0) const;
    size_type find_first_not_of(const char* s, size_type pos = 0) const;
    size_type find_first_not_of(const char* s, size_type pos, size_type n) const;
    size_type find_first_not_of(char c, size_type pos = 0) const;
    size_type find_last_not_of(const String& str, size_type pos = npos) const;
    size_type find_last_not_of(const char* s, size_type pos = npos) const;
    size_type find_last_not_of(const char* s, size_type pos, size_type n) const;
    size_type find_last_not_of(char c, size_type pos = npos) const;
    String substr(size_type pos = 0, size_type len = npos) const;
    int compare(const String& str) const;
    int compare(size_type pos, size_type len, const String& str) const;
    int compare(size_type pos, size_type len, const String& str, size_type subpos, size_type sublen) const;
    int compare(const char* s) const;
    int compare(size_type pos, size_type len, const char* s) const;
    int compare(size_type pos, size_type len, const char* s, size_type n) const;

    // Member constants
    static const size_type npos = static_cast<size_type>(-1);

private:
    std::string m_data;
};

// Non-member function overloads
String operator+(const String& lhs, const String& rhs);
String operator+(const String& lhs, const char* rhs);
String operator+(const char* lhs, const String& rhs);
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);
void swap(String& lhs, String& rhs);


}

#include "../src/string.hpp"

#endif