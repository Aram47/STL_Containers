#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <unistd.h>
#include "./allocator.h"

namespace DS
{

class String {
public:
    // Member types
    using traits_type       = std::char_traits<char>;
private:
    class Base_Iterator
    {
        friend class String;
    private:
        char* ptr = nullptr;
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
        explicit Base_Iterator(char*);
    };

public:

    class Const_Iterator : public Base_Iterator
    {
        friend class String;
    protected:
        explicit Const_Iterator(char*);
    public:
        Const_Iterator();
        Const_Iterator(const Base_Iterator&);
        Const_Iterator(Base_Iterator&&);

        const Const_Iterator& operator=(const Base_Iterator&);
        const Const_Iterator& operator=(Base_Iterator&&);

        const char& operator*();
        const char* operator->();
        const Const_Iterator& operator++();
        const Const_Iterator& operator++(int);
        const Const_Iterator& operator--();
        const Const_Iterator& operator--(int);
        const Const_Iterator operator+(long long int) const;
        const Const_Iterator operator-(long long int) const;
        const Const_Iterator& operator+=(long long int);
        const Const_Iterator& operator-=(long long int);
        const char& operator[](std::size_t) const;
    };

    class Iterator : public Const_Iterator
    {
        friend class String;
    public:
        Iterator();
        Iterator(const Base_Iterator&);
        Iterator(Base_Iterator&&);

        const Iterator& operator=(const Base_Iterator&);
        const Iterator& operator=(Base_Iterator&&);

        char& operator*();
        char* operator->();

        Iterator& operator++();
        Iterator& operator++(int);
        Iterator& operator--();
        Iterator& operator--(int);
        Iterator operator+(long long int) const;
        Iterator operator-(long long int) const;
        Iterator& operator+=(long long int);
        Iterator& operator-=(long long int);

        char& operator[](std::size_t);
    protected:
        explicit Iterator(char*);
    };

    class Const_Reverse_Iterator : public Base_Iterator
    {
        friend class String;
  
    protected:
        explicit Const_Reverse_Iterator(char*);
    public:
        Const_Reverse_Iterator();
        Const_Reverse_Iterator(const Base_Iterator&);
        Const_Reverse_Iterator(Base_Iterator&&);

        const Const_Reverse_Iterator& operator=(const Base_Iterator&);
        const Const_Reverse_Iterator& operator=(Base_Iterator&&);

        const char& operator*();
        const char* operator->();

        const Const_Reverse_Iterator& operator++();
        const Const_Reverse_Iterator& operator++(int);
        const Const_Reverse_Iterator& operator--();
        const Const_Reverse_Iterator& operator--(int);
        const Const_Reverse_Iterator operator+(long long int) const;
        const Const_Reverse_Iterator operator-(long long int) const;
        const Const_Reverse_Iterator& operator+=(long long int);
        const Const_Reverse_Iterator& operator-=(long long int);
        const char& operator[](std::size_t) const;
    };

    class Reverse_Iterator : public Const_Reverse_Iterator
    {
        friend class String;
    public:
        Reverse_Iterator();
        Reverse_Iterator(const Base_Iterator&);
        Reverse_Iterator(Base_Iterator&&);

        const Reverse_Iterator& operator=(const Base_Iterator&);
        const Reverse_Iterator& operator=(Base_Iterator&&);

        char& operator*();
        char* operator->();

        Reverse_Iterator& operator++();
        Reverse_Iterator& operator++(int);
        Reverse_Iterator& operator--();
        Reverse_Iterator& operator--(int);
        Reverse_Iterator operator+(long long int) const;
        Reverse_Iterator operator-(long long int) const;
        Reverse_Iterator& operator+=(long long int);
        Reverse_Iterator& operator-=(long long int);

        char& operator[](std::size_t);
    protected:
        explicit Reverse_Iterator(char*);
    };

    // Member functions
    String();
    explicit String(const char*);
    explicit String(const String&);
    explicit String(String&&);
    String(std::initializer_list<char>);
    ~String();

    String& operator=(const String&);
    String& operator=(String&&);
    String& operator=(std::initializer_list<char>);

    // Iterators
    Iterator begin();
    Iterator end();
    Reverse_Iterator rbegin();
    Reverse_Iterator rend();
    Const_Iterator cbegin() const;
    Const_Iterator cend() const;
    Const_Reverse_Iterator crbegin() const;
    Const_Reverse_Iterator crend() const;

    // Capacity
    std::size_t size() const;
    std::size_t length() const;
    std::size_t max_size() const;
    void resize(std::size_t);
    std::size_t capacity() const;
    void reserve(std::size_t);
    void clear();
    bool empty() const;

    // Element access
    char& operator[](std::size_t);
    const char& operator[](std::size_t) const;
    char& at(std::size_t);
    const char& at(std::size_t) const;
    char& back();
    const char& back() const;
    char& front();
    const char& front() const;

    // Modifiers
    String& operator+=(const String&);
    String& operator+=(const char*);
    String& operator+=(char);
    String& append(const String&);
    String& append(const char*);
    String& append(const char*, std::size_t);
    String& append(std::size_t, char);
    void push_back(char);
    String& assign(const String&);
    String& assign(const char*);
    String& assign(const char*, std::size_t);
    String& assign(std::size_t, char);
    String& insert(std::size_t, const String&);
    String& insert(std::size_t, const char*);
    String& insert(std::size_t, const char*, std::size_t);
    String& insert(std::size_t, std::size_t, char);
    String& erase(std::size_t = 0, std::size_t = npos);
    String& replace(std::size_t, std::size_t, const String&);
    String& replace(std::size_t, std::size_t, const char*);
    String& replace(std::size_t, std::size_t, const char*, std::size_t);
    String& replace(std::size_t, std::size_t, std::size_t, char);
    void swap(String&);
    void pop_back();

    // String operations
    const char* c_str() const;
    const char* data() const;
    DS::Allocator<char> get_allocator() const;
    std::size_t copy(char*, std::size_t, std::size_t = 0) const;
    std::size_t find(const String&, std::size_t = 0) const;
    std::size_t find(const char*, std::size_t = 0) const;
    std::size_t find(const char*, std::size_t, std::size_t) const;
    std::size_t find(char, std::size_t = 0) const;
    std::size_t rfind(const String&, std::size_t = npos) const;
    std::size_t rfind(const char*, std::size_t = npos) const;
    std::size_t rfind(const char*, std::size_t, std::size_t) const;
    std::size_t rfind(char, std::size_t = npos) const;
    std::size_t find_first_of(const String&, std::size_t = 0) const;
    std::size_t find_first_of(const char*, std::size_t = 0) const;
    std::size_t find_first_of(const char*, std::size_t, std::size_t) const;
    std::size_t find_first_of(char, std::size_t = 0) const;
    std::size_t find_last_of(const String&, std::size_t = npos) const;
    std::size_t find_last_of(const char*, std::size_t = npos) const;
    std::size_t find_last_of(const char*, std::size_t, std::size_t) const;
    std::size_t find_last_of(char, std::size_t = npos) const;
    std::size_t find_first_not_of(const String&, std::size_t = 0) const;
    std::size_t find_first_not_of(const char*, std::size_t = 0) const;
    std::size_t find_first_not_of(const char*, std::size_t, std::size_t) const;
    std::size_t find_first_not_of(char, std::size_t = 0) const;
    std::size_t find_last_not_of(const String&, std::size_t = npos) const;
    std::size_t find_last_not_of(const char*, std::size_t = npos) const;
    std::size_t find_last_not_of(const char*, std::size_t, std::size_t) const;
    std::size_t find_last_not_of(char, std::size_t = npos) const;
    String substr(std::size_t = 0, std::size_t = npos) const;
    int compare(const String&) const;
    int compare(std::size_t, std::size_t, const String&) const;
    int compare(std::size_t, std::size_t, const String&, std::size_t, std::size_t) const;
    int compare(const char*) const;
    int compare(std::size_t, std::size_t, const char*) const;
    int compare(std::size_t, std::size_t, const char*, std::size_t) const;

    // Member constants
    static const std::size_t npos = static_cast<std::size_t>(-1);

private:
    char* m_data;
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