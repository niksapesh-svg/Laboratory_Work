#include "DynamicArray.h"

#include <iostream>

int main() {
    std::cout << "=== Задание 1: конструктор, деструктор, set/get, print ===\n";
    DynamicArray a(5);
    for (int i = 0; i < a.getSize(); ++i) {
        a.set(i, i * 3);
    }
    std::cout << "Массив a: ";
    a.print();

    a.set(10, 5);
    a.set(1, 200);
    std::cout << "a.get(2) = " << a.get(2) << "\n";
    std::cout << "a.get(-1) = " << a.get(-1) << "\n\n";

    std::cout << "=== Задание 2: конструктор копирования ===\n";
    DynamicArray b = a;
    std::cout << "Копия b: ";
    b.print();
    b.set(0, 42);
    std::cout << "b после изменения: ";
    b.print();
    std::cout << "a не изменился:   ";
    a.print();
    std::cout << "\n";

    std::cout << "=== Задание 3: добавление элемента в конец ===\n";
    std::cout << "a до добавления: ";
    a.print();
    a.addElement(7);
    a.addElement(99);
    a.addElement(500);
    std::cout << "a после добавления: ";
    a.print();
    std::cout << "\n";

    std::cout << "=== Задание 4: сложение и вычитание массивов ===\n";
    DynamicArray x(4);
    DynamicArray y(2);
    for (int i = 0; i < x.getSize(); ++i) {
        x.set(i, i + 1);
    }
    y.set(0, 10);
    y.set(1, 20);
    std::cout << "x = ";
    x.print();
    std::cout << "y = ";
    y.print();
    x.add(y);
    std::cout << "x.add(y) = ";
    x.print();
    x.subtract(y);
    std::cout << "x.subtract(y) = ";
    x.print();

    return 0;
}
