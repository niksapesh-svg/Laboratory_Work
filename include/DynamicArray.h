#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
private://1 зад.Свойства
    int* data;
    int size;

    bool isValidValue(int value) const;//1 зад.подходит ли значение под диапазон -100 ... 100?

public:
    explicit DynamicArray(int size);//1 зад.Конструктор с размером
    DynamicArray(const DynamicArray& other);// 2 зад.Конструктор копирования
    ~DynamicArray();//1 зад.Деструктор

    int getSize() const;
    void print() const;

    void set(int index, int value);//1 зад.Сеттер
    int get(int index) const;//1 зад.Геттер

    void addElement(int value);

    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
};

#endif
