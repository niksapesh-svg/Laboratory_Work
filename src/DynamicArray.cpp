#include "DynamicArray.h"

#include <iostream>


//Задание 1.Конструктор
DynamicArray::DynamicArray(int size) : data(nullptr), size(0) {//nullptr=нулевой указатель
    if (size < 0) {
        throw std::invalid_argument("Размер массива не может быть отрицательным");
    }

    data = new int[size];   //если не хватит памяти сам бросит std::bad_alloc
    this->size = size;

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
        throw std::out_of_range("Индекс " + std::to_string(index) +" вне границ массива");
    }
    if (!isValidValue(value)) {
        throw std::invalid_argument("Значение " + std::to_string(value) +" вне диапазона -100..100");
    }
    data[index] = value;
}

//1 Задание.Геттер
int DynamicArray::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс " + std::to_string(index) +" вне границ массива");
    }
    return data[index];
}

//Задание 2.Конструктор копирования
DynamicArray::DynamicArray(const DynamicArray& other): data(nullptr), size(other.size) {
    data = new int[other.size];   //при нехватке памяти — std::bad_alloc
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

//3 Задание.Добавление элемента в конец с расшир.размера
void DynamicArray::addElement(int value) {
    if (!isValidValue(value)) {
        throw std::invalid_argument("Значение " + std::to_string(value) +" вне диапазона -100..100");
    }

    int* newData = new int[size + 1];   //при нехватке памяти std::bad_alloc
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
    if (other.size > size) {
        throw std::out_of_range("Размер второго массива больше размера исходного");
    }
    for (int i = 0; i < size; ++i) {
        int otherValue = (i < other.size) ? other.data[i] : 0;
        data[i] += otherValue;
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    if (other.size > size) {
        throw std::out_of_range("Размер второго массива больше размера исходного");
    }
    for (int i = 0; i < size; ++i) {
        int otherValue = (i < other.size) ? other.data[i] : 0;
        data[i] -= otherValue;
    }
}
