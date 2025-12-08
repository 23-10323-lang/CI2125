///
/// Array.h
///

#pragma once

template <typename T>
class Array {
public:
    Array();
    Array(size_t n);
    Array(const Array<T>& other);
    ~Array();

    Array& operator=(const Array<T>& other);
private:
    T *data_;
    size_t size_;
    size_t capacity_;
};
