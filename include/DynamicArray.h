//Защита от повт.включения заголовка
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>   // std::out_of_range, std::invalid_argument
#include <new>         // std::bad_alloc

class DynamicArray {
private://1 зад.Указатель на данные и размер массива;
    int* data;
    int size;

    bool isValidValue(int value) const;//Подходит ли значение под диапазон -100 ... 100?

public:
    explicit DynamicArray(int size);//1 зад.Конструктор с размером массива
    ~DynamicArray();//1 зад.Деструктор
    DynamicArray(const DynamicArray& other);// 2 зад.Конструктор копирования

    //Для тестов
    int getSize() const;
    void print() const;//все знач массива

    //1 зад.Геттер,сеттер
    void set(int index, int value);
    int get(int index) const;

    //3 зад.Добавление в конец
    void addElement(int value);

    //4 зад.Сложение,вычит
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
};

#endif
