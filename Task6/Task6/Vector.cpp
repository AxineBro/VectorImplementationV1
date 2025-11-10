#include "Vector.h"
#include <algorithm>
#include <iostream>

// Изменяет размер внутреннего массива на новую ёмкость.
void Vector::resize(size_t new_capacity) {
    int* new_data = new int[new_capacity];
    std::copy(data, data + size, new_data);
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

// Конструктор по умолчанию.
Vector::Vector() : size(0), capacity(10) {
    data = new int[capacity];
}

// Конструктор с начальным размером.
Vector::Vector(size_t initial_size) : size(initial_size), capacity(initial_size * 2) {
    data = new int[capacity];
    std::fill(data, data + size, 0);
}

// Конструктор копирования.
Vector::Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
    data = new int[capacity];
    std::copy(other.data, other.data + size, data);
}

// Деструктор.
Vector::~Vector() {
    delete[] data;
}

// Добавляет элемент в конец вектора.
void Vector::push_back(int val) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    data[size++] = val;
}

// Добавляет элемент в начало вектора.
void Vector::push_front(int val) {
    insert(0, val);
}

// Вставляет элемент в указанную позицию.
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

// Удаляет элемент в указанной позиции.
void Vector::erase(size_t pos) {
    if (pos >= size) return;
    std::copy(data + pos + 1, data + size, data + pos);
    --size;
}

// Получает текущий размер вектора.
size_t Vector::get_size() const {
    return size;
}

// Доступ к элементу по индексу (константная версия).
const int& Vector::operator[](size_t index) const {
    return data[index];
}

// Доступ к элементу по индексу.
int& Vector::operator[](size_t index) {
    return data[index];
}

// Сравнивает два вектора на равенство.
bool Vector::operator==(const Vector& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

// Выполняет поэлементное сложение двух векторов.
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

// Выполняет поэлементное умножение двух векторов.
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

// Дружественная функция для вывода вектора в поток.
std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "[";
    for (size_t i = 0; i < v.size; ++i) {
        os << v.data[i];
        if (i < v.size - 1) os << ", ";
    }
    os << "]";
    return os;
}