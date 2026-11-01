#include "DynamicArray.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <new>

//вместо print везде работает operator
int main() {
    std::cout << "Числовой тип\n";
    DynamicArray<int> a(5);
    for (int i = 0; i < a.getSize(); ++i) {
        a.set(i, i * 3);
    }
    std::cout << "a = " << a << "\n";

    // диапазон −100..100
    try {
        a.set(1, 200);
    } catch (const std::invalid_argument& e) {
        std::cout << "Поймано: " << e.what() << "\n";
    }

    // выход за границы
    try {
        a.get(10);
    } catch (const std::out_of_range& e) {
        std::cout << "Поймано: " << e.what() << "\n";
    }

    // копирование
    DynamicArray<int> b = a;
    b.set(0, 42);
    std::cout << "b = " << b << "\n";
    std::cout << "a = " << a << " (не изменился)\n";

    // addElement
    a.addElement(7);
    a.addElement(99);
    std::cout << "a после addElement = " << a << "\n";

    //add,subtract
    DynamicArray<int> x(4);
    DynamicArray<int> y(2);
    for (int i = 0; i < x.getSize(); ++i) x.set(i, i + 1);
    y.set(0, 10); y.set(1, 20);
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n";
    x.add(y);
    std::cout << "x.add(y) = " << x << "\n";
    x.subtract(y);
    std::cout << "x.subtract(y) = " << x << "\n";

    //Задание 3.Расстояние
    DynamicArray<int> p(2), q(2);
    p.set(0, 0); p.set(1, 0);
    q.set(0, 3); q.set(1, 4);
    std::cout << "dist(p, q) = " << distance(p, q) << " (ожидается 5)\n";

    //Разные размеры массивов
    DynamicArray<int> r(3);
    try {
        distance(p, r);
    } catch (const std::invalid_argument& e) {
        std::cout << "Поймано: " << e.what() << "\n";
    }

    std::cout << "\nНечисловой тип\n";
    DynamicArray<std::string> s(3);
    s.set(0, "hello");
    s.set(1, "world");
    s.set(2, "!");
    std::cout << "s = " << s << "\n";

    // Диапазон не проверяется
    s.set(0, "any string works");
    std::cout << "s после set = " << s << "\n";

    //distance для string 
    DynamicArray<std::string> s2(3);
    try {
        distance(s, s2);
    } catch (const std::bad_typeid& e) {
        std::cout << "Поймано " << e.what() << "\n";
    }

    return 0;
}