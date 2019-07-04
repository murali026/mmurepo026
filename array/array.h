#include<iostream>
using namespace std;

template <class T, const unsigned int Size>
class Array {
public:
    typedef const T* const_iterator;
    typedef const T* const_pointer;
    typedef const T& const_reference;
    typedef T* iterator;
    typedef T* pointer;
    typedef T& reference;
    typedef int difference_type;
    typedef unsigned int size_type;
    typedef T value_type;

    bool empty() const;
    size_type size() const;
    const_iterator begin() const;
    const_iterator end() const;
    const_reference front() const;
    const_reference back() const;
    const_reference operator[](size_type index) const;

    iterator begin();
    iterator end();
    iterator front();
    iterator back();
    reference operator[](size_type index);
private:
    T _a[Size];
};

#include "array_memberfunctions.h"
