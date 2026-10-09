#include "DynamicArray.h"

#include <iostream>


//Задание 1
DynamicArray::DynamicArray(int size) : data(new int[size]), size(size) {
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

//Задание 2
DynamicArray::DynamicArray(const DynamicArray& other) : data(new int[other.size]), size(other.size) {
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

//Деструктор
DynamicArray::~DynamicArray() {
    delete[] data;
}

//Проверка значения(диапазон)
bool DynamicArray::isValidValue(int value) const {
    return value >= -100 && value <= 100;
}

//Размер
int DynamicArray::getSize() const {
    return size;
}

//Печать массива
void DynamicArray::print() const {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i + 1 < size) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

//Задание 1
void DynamicArray::set(int index, int value) {
    if (index < 0 || index >= size) {
        std::cout << "Ошибка: индекс " << index << " вне границ массива\n";
        return;
    }

    if (!isValidValue(value)) {
        std::cout << "Ошибка: значение " << value << " вне диапазона -100, 100\n";
        return;
    }

    data[index] = value;
}

//1 Задание
int DynamicArray::get(int index) const {
    if (index < 0 || index >= size) {
        std::cout << "Ошибка: индекс " << index << " вне границ массива\n";
        return 0;
    }

    return data[index];
}

//3 Задание 
void DynamicArray::addElement(int value) {
    if (!isValidValue(value)) {
        std::cout << "Ошибка: значение " << value << " вне диапазона -100, 100\n";
        return;
    }

    int* newData = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = value;

    delete[] data;
    data = newData;
    ++size;
}

//4 Задание(Сложение+вычит)
void DynamicArray::add(const DynamicArray& other) {
    for (int i = 0; i < size; ++i) {
        int otherValue = (i < other.size) ? other.data[i] : 0;
        data[i] += otherValue;
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    for (int i = 0; i < size; ++i) {
        int otherValue = (i < other.size) ? other.data[i] : 0;
        data[i] -= otherValue;
    }
}
