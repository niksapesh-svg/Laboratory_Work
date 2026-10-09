#include "DynamicArray.h"

#include <iostream>

DynamicArray::DynamicArray(int size) : data(nullptr), size(0) {
    if (size <= 0) {
        std::cout << "Ошибка: размер массива должен быть положительным.\n";
        return;
    }

    this->size = size;
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) : data(nullptr), size(other.size) {
    if (size <= 0) {
        return;
    }

    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

bool DynamicArray::isValidValue(int value) const {
    return value >= -100 && value <= 100;
}

int DynamicArray::getSize() const {
    return size;
}

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

void DynamicArray::set(int index, int value) {
    if (index < 0 || index >= size) {
        std::cout << "Ошибка: индекс " << index << " вне границ массива.\n";
        return;
    }

    if (!isValidValue(value)) {
        std::cout << "Ошибка: значение " << value << " вне диапазона [-100, 100].\n";
        return;
    }

    data[index] = value;
}

int DynamicArray::get(int index) const {
    if (index < 0 || index >= size) {
        std::cout << "Ошибка: индекс " << index << " вне границ массива.\n";
        return 0;
    }

    return data[index];
}

void DynamicArray::addElement(int value) {
    if (!isValidValue(value)) {
        std::cout << "Ошибка: значение " << value << " вне диапазона [-100, 100].\n";
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
