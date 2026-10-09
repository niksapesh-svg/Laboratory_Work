# Практическое задание: динамический массив (C++)

Репозиторий с пятью последовательными частями задания по классу динамического массива.

| Часть | Тема | Ветка |
|-------|------|-------|
| 1 | Класс динамического массива | `part1-dynamic-array` |
| 2 | Исключения | `part2-exceptions` |
| 3 | Шаблоны | `part3-templates` |
| 4 | Операторы и перегрузки | `part4-operators` |
| 5 | Правило трёх/пяти | `part5-rule-of-five` |

## Структура

```
.
├── include/            # заголовки
├── src/                # реализация и демонстрационные программы
├── CMakeLists.txt
└── README.md
```

## Сборка

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/DynamicArray.cpp src/main.cpp -o main
./main
```

или через CMake:

```bash
cmake -S . -B build
cmake --build build
```
