#include "DynamicArray.h"
#include <iostream>

int main() {
    std::cout << "Задание 1: вывод значений,конструктор, деструктор, set/get \n";
    DynamicArray a(5);
    for (int i = 0; i < a.getSize(); ++i) {
        a.set(i, i * 3);
    }
    std::cout << "Массив a: ";
    a.print();


    a.set(10, 5);//ошибка о выходе индекса за границы
    a.set(1, 200);//ошибка о значении вне диапазона −100…100
    std::cout << "a.get(2) = " << a.get(2) << "\n";//вывод верного числа
    std::cout << "a.get(-1)" << a.get(-1) << "\n\n";//проверка границ в геттере,ошибка

    std::cout << "Задание 2: конструктор копирования \n";
    DynamicArray b = a;
    std::cout << "Копия b: ";
    b.print();
    b.set(0, 42);
    std::cout << "b после изменения: ";
    b.print();
    std::cout << "a не изменился:   ";//доказываю независимость двух массивов
    a.print();
    std::cout << "\n";

    std::cout << "Задание 3: добавление элемента в конец \n";
    std::cout << "a до добавления: ";
    a.print();
    a.addElement(7);
    a.addElement(99);
    a.addElement(500);//число вне диапазона,ошибка
    std::cout << "a после добавления: ";
    a.print();
    std::cout << "\n";

    std::cout << "Задание 4: сложение и вычитание массивов \n";
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
    std::cout << "x.add(y) = ";//Конец y не участвует,тк его длина меньше x
    x.print();
    x.subtract(y);
    std::cout << "x.subtract(y) = ";//Должны получить исх.x
    x.print();

    return 0;
}
