# ROADMAP — план тем

Статусы:

- ✅ — пройдено
- 🔄 — в работе
- ⬜ — запланировано

## Основной путь

| # | Тема | Что нужно понять и закрепить | Статус |
|---|------|-------------------------------|--------|
| 00 | **Setup** | установка окружения, Visual Studio / VS Code, CMake, первая сборка | ✅ |
| 01 | **Basics** | `main`, `#include`, `iostream`, `std::cout`, структура простой программы | ✅ |
| 02 | **Types and Variables** | `int`, `double`, `bool`, `char`, `std::string`, литералы, инициализация, `auto` | ⬜ |
| 03 | **Input and Expressions** | `std::cin`, арифметика, сравнения, логические операторы, приоритет операций | ⬜ |
| 04 | **Control Flow** | `if/else`, `switch`, `for`, `while`, `do-while`, `break`, `continue` | ✅ |
| 05 | **Functions** | объявление, определение, перегрузка, параметры по умолчанию, `inline` | ✅ |
| 06 | **References and const** | передача по значению, ссылки, `const`, `const&`, область видимости, lifetime basics | ⬜ |
| 07 | **Arrays and Strings** | C-style массивы, `std::array`, основы `std::vector`, `std::string` как контейнер символов | ⬜ |
| 08 | **Structs and enum** | `struct`, `enum class`, простые пользовательские типы, группировка данных | ⬜ |
| 09 | **OOP Basics** | классы, `public/private`, инкапсуляция, методы, `this`, `const`-методы | ✅ |
| 10 | **Constructors and RAII** | конструкторы, деструкторы, список инициализации, инварианты объекта, RAII | ⬜ |
| 11 | **OOP Advanced** | композиция, наследование, `virtual`, полиморфизм, `override`, базовый деструктор | ⬜ |
| 12 | **Error Handling** | проверка ввода, `assert`, исключения, `try/catch`, проектирование ошибок | ⬜ |
| 13 | **Templates Basics** | шаблоны функций, шаблоны классов, вывод типов, специализация | 🔄 |
| 14 | **Templates Advanced** | `if constexpr`, `<type_traits>`, SFINAE, variadic templates, основы concepts | ⬜ |
| 15 | **STL Containers** | `vector`, `string`, `array`, `map`, `set`, `unordered_map`, выбор контейнера | ⬜ |
| 16 | **Iterators and Algorithms** | итераторы, `<algorithm>`, `<numeric>`, предикаты, компараторы, C++20 ranges | ⬜ |
| 17 | **Lambdas** | синтаксис lambda, захваты, использование с алгоритмами, маленькие function objects | ⬜ |
| 18 | **Memory** | стек/куча, указатели, `new/delete`, ownership, `nullptr`, утечки памяти | ⬜ |
| 19 | **Smart Pointers** | `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`, `make_unique`, `make_shared` | ⬜ |
| 20 | **Files and Streams** | `fstream`, чтение/запись файлов, обработка ошибок ввода-вывода | ⬜ |
| 21 | **Project Structure** | `.hpp/.cpp`, include guards / `#pragma once`, библиотеки, несколько targets в CMake | ⬜ |
| 22 | **Testing and Debugging** | unit-тесты, отладчик, sanitizer basics, CI, воспроизводимые проверки | ⬜ |
| 23 | **Final Project** | небольшой законченный консольный проект с CMake, тестами и несколькими модулями | ⬜ |

## Практические мини-проекты

Эти задания можно делать после соответствующих тем, чтобы не ограничиваться одиночными `task01`.

| После темы | Мини-проект | Что тренирует |
|------------|-------------|---------------|
| 04 | **Number Guessing Game v2** | ввод, циклы, проверка ошибок, случайные числа |
| 05 | **Calculator** | функции, разбиение логики, обработка операций |
| 08 | **Student Gradebook** | `struct`, `vector`, строки, простая статистика |
| 11 | **Shape Hierarchy** | наследование, виртуальные методы, полиморфизм |
| 16 | **Text Analyzer** | контейнеры, алгоритмы, сортировка, частотный словарь |
| 20 | **Todo CLI** | файлы, сериализация простого состояния, команды пользователя |
| 23 | **Library / Bank / Inventory App** | модули, классы, STL, тесты, CMake, CI |

## Технический долг роудмапа

- Привести нумерацию папок `lessons/NN_<name>/` к этому плану.
- Добавить недостающую тему `02_types_and_variables`.
- Разбить текущий широкий OOP-блок на базовый ООП, RAII и продвинутый ООП.
- Разделить templates на базовую и продвинутую часть.
- Добавить отдельные задания для STL, алгоритмов, памяти, файлов и тестирования.
- Обновить `README.md`, когда структура уроков будет приведена к новому плану.

---

> Каждая тема живёт в своей папке `lessons/NN_<name>/`.
> Заметки — в `notes.md`, задания — в `src/`.
