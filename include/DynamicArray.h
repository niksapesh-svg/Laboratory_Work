#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>     // std::out_of_range, std::invalid_argument, std::bad_typeid
#include <new>           // std::bad_alloc
#include <iostream>      // std::ostream (для operator<<)
#include <type_traits>   // std::is_integral_v, std::is_arithmetic_v
#include <cmath>         // std::sqrt

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;

    //Задание 1.Проверка целочисленных
    void checkValue(const T& value) const {
        if constexpr (std::is_integral_v<T>) {
            if (value > 100 || value < -100) {
                throw std::invalid_argument("Значение вне диапазона -100..100");
            }
        }
    }

public:
    explicit DynamicArray(int size);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    int getSize() const;

    void set(int index, const T& value);
    T get(int index) const;

    void addElement(const T& value);
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);

    //Задание 2.Вывод вместо print
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray<U>& arr);//friend = разрешение на доступ к приватным полям класса
};

//Задание 3.Расстояние между массивами
template <typename T>
double distance(const DynamicArray<T>& a, const DynamicArray<T>& b) {

    if constexpr (!std::is_arithmetic_v<T>) {
        throw std::bad_typeid();
    } else {
        if (a.getSize() != b.getSize()) {
            throw std::invalid_argument("Размеры массивов должны совпадать");
        }
        double sum = 0.0;
        for (int i = 0; i < a.getSize(); ++i) {
            double d = static_cast<double>(a.get(i)) - static_cast<double>(b.get(i));//Приведение к double решит проблему большого числа,если не помещается в тип Int
            sum += d * d;
        }
        return std::sqrt(sum);
    }
}

//Реализация методов шаблона

template <typename T>
DynamicArray<T>::DynamicArray(int size) : data(nullptr), size(0) {
    if (size < 0) {
        throw std::invalid_argument("Размер массива не может быть отрицательным");
    }
    data = new T[size];
    this->size = size;
    for (int i = 0; i < size; ++i) {
        data[i] = T();
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other): data(nullptr), size(other.size) {
    data = new T[other.size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
int DynamicArray<T>::getSize() const {
    return size;
}

template <typename T>
void DynamicArray<T>::set(int index, const T& value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс " + std::to_string(index) + " вне границ массива");
    }
    checkValue(value);
    data[index] = value;
}

template <typename T>
T DynamicArray<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс " + std::to_string(index) + " вне границ массива");
    }
    return data[index];
}

template <typename T>
void DynamicArray<T>::addElement(const T& value) {
    checkValue(value);
    T* newData = new T[size + 1];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = value;
    delete[] data;
    data = newData;
    ++size;
}

template <typename T>
void DynamicArray<T>::add(const DynamicArray& other) {
    if (other.size > size) {
        throw std::out_of_range("Размер второго массива больше размера исходного");
    }
    for (int i = 0; i < size; ++i) {
        T otherValue = (i < other.size) ? other.data[i] : T();
        data[i] += otherValue;
    }
}

template <typename T>
void DynamicArray<T>::subtract(const DynamicArray& other) {
    if (other.size > size) {
        throw std::out_of_range("Размер второго массива больше размера исходного");
    }
    for (int i = 0; i < size; ++i) {
        T otherValue = (i < other.size) ? other.data[i] : T();
        data[i] -= otherValue;
    }
}

//Задание 2.Реализация Operator
template <typename U>
std::ostream& operator<<(std::ostream& os, const DynamicArray<U>& arr) {
    os << "[";
    for (int i = 0; i < arr.size; ++i) {
        os << arr.data[i];
        if (i + 1 < arr.size) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

#endif