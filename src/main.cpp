#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>
#include <new>

int main()
{
    std::cout << "Задание 1: вывод значений,конструктор, деструктор, set/get \n";
    DynamicArray a(5);
    for (int i = 0; i < a.getSize(); ++i)
    {
        a.set(i, i * 3);
    }
    std::cout << "Массив a: ";
    a.print();

    // std::out_of_range: индекс вне границ
    try
    {
        a.set(10, 5);
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Поймано std::out_of_range (set): " << e.what() << "\n";
    }

    // std::invalid_argument: значение вне диапазона −100…100
    try
    {
        a.set(1, 200);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Поймано std::invalid_argument (set): " << e.what() << "\n";
    }

    std::cout << "a.get(2) = " << a.get(2) << "\n"; // вывод верного числа

    // std::out_of_range: проверка границ в геттере
    try
    {
        std::cout << "a.get(-1) = " << a.get(-1) << "\n\n";
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Поймано std::out_of_range (get): " << e.what() << "\n\n";
    }

    std::cout << "Задание 2: конструктор копирования \n";
    DynamicArray b = a;
    std::cout << "Копия b: ";
    b.print();
    b.set(0, 42);
    std::cout << "b после изменения: ";
    b.print();
    std::cout << "a не изменился:   "; // доказываю независимость двух массивов
    a.print();
    std::cout << "\n";

    std::cout << "Задание 3: добавление элемента в конец \n";
    std::cout << "a до добавления: ";
    a.print();
    a.addElement(7);
    a.addElement(99);

    // std::invalid_argument: число вне диапазона
    try
    {
        a.addElement(500);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Поймано std::invalid_argument (addElement): " << e.what() << "\n";
    }

    std::cout << "a после добавления: ";
    a.print();
    std::cout << "\n";

    std::cout << "Задание 4: сложение и вычитание массивов \n";
    DynamicArray x(4);
    DynamicArray y(2);
    for (int i = 0; i < x.getSize(); ++i)
    {
        x.set(i, i + 1);
    }
    y.set(0, 10);
    y.set(1, 20);
    std::cout << "x = ";
    x.print();
    std::cout << "y = ";
    y.print();
    x.add(y);
    std::cout << "x.add(y) = "; // Конец y не участвует,тк его длина меньше x
    x.print();
    x.subtract(y);
    std::cout << "x.subtract(y) = "; // Должны получить исх.x
    x.print();

    // std::out_of_range в add: other длиннее исходного
    std::cout << "\nПроверка std::out_of_range в add \n";
    DynamicArray small(2);
    DynamicArray big(5);
    try
    {
        small.add(big);
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Поймано std::out_of_range (add): " << e.what() << "\n";
    }

    // std::bad_alloc огромный размер
    std::cout << "\nПроверка std::bad_alloc \n";
    try
    {
        while (true)
        {
            new int[100000000]; // Каждый раз выделяем по немного памяти(прим 400мб)
        }
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << e.what() << "\n";
    }
}