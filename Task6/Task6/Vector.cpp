#include "Vector.h"
#include <algorithm>
#include <iostream>

// Changes the size of the internal array to the new capacity.
void Vector::resize(size_t new_capacity) {
    int* new_data = new int[new_capacity];
    std::copy(data, data + size, new_data);
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

// Default constructor.
Vector::Vector() : size(0), capacity(10) {
    data = new int[capacity];
}

// Constructor with the initial size.
Vector::Vector(size_t initial_size) : size(initial_size), capacity(initial_size * 2) {
    data = new int[capacity];
    std::fill(data, data + size, 0);
}

// Copy constructor.
Vector::Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
    data = new int[capacity];
    std::copy(other.data, other.data + size, data);
}

// The destructor.
Vector::~Vector() {
    delete[] data;
}

// Adds an element to the end of the vector.
void Vector::push_back(int val) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    data[size++] = val;
}

// Adds an element to the beginning of the vector.
void Vector::push_front(int val) {
    insert(0, val);
}

// Inserts the element in the specified position.
void Vector::insert(size_t pos, int val) {
    if (pos > size) {
        pos = size;
    }
    if (size >= capacity) {
        resize(capacity * 2);
    }
    std::copy_backward(data + pos, data + size, data + size + 1);
    data[pos] = val;
    ++size;
}

// Deletes the element at the specified position.
void Vector::erase(size_t pos) {
    if (pos >= size) return;
    std::copy(data + pos + 1, data + size, data + pos);
    --size;
}

// Gets the current size of the vector.
size_t Vector::get_size() const {
    return size;
}

// Access to the element by index (constant version).
const int& Vector::operator[](size_t index) const {
    return data[index];
}

// Access to the element by index.
int& Vector::operator[](size_t index) {
    return data[index];
}

// Compares two vectors for equality.
bool Vector::operator==(const Vector& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

// Performs the element-wise addition of two vectors.
Vector Vector::operator+(const Vector& other) const {
    if (size != other.size) {
        std::cerr << "Vectors must be same size for addition." << std::endl;
        return Vector();
    }

    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = data[i] + other[i];
    }
    return result;
}

// Performs element-wise multiplication of two vectors.
Vector Vector::operator*(const Vector& other) const {
    if (size != other.size) {
        std::cerr << "Vectors must be same size for multiplication." << std::endl;
        return Vector();
    }
    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = data[i] * other[i];
    }
    return result;
}

// A friendly function for outputting a vector to a stream.
std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "[";
    for (size_t i = 0; i < v.size; ++i) {
        os << v.data[i];
        if (i < v.size - 1) os << ", ";
    }
    os << "]";
    return os;
}