#include "DynamicArray.h"

#include <iostream>


//Задание 1.Конструктор
DynamicArray::DynamicArray(int size) : data(new int[size]), size(size) {
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

//Задание 1.Деструктор
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

//1 Задание.Функция вывода всех значений массива;
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

//Задание 1.Сеттер
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

//1 Задание.Геттер
int DynamicArray::get(int index) const {
    if (index < 0 || index >= size) {
        std::cout << "Ошибка: индекс " << index << " вне границ массива,поэтому результат равен\n";
        return 0;
    }

    return data[index];
}

//Задание 2.Конструктор копирования
DynamicArray::DynamicArray(const DynamicArray& other) : data(new int[other.size]), size(other.size) {
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

//3 Задание.Добавление элемента в конец с расшир.размера
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

//4 Задание.Сложение+вычит
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
