# Тема 01 — Basics

## Hello World и первая программа на C++

### Что такое `main`

Каждая программа на C++ начинается с функции `main`.  
Её сигнатура: `int main()` или `int main(int argc, char* argv[])`.  
Возвращаемое значение: `0` — успех, ненулевое — ошибка.

### `#include <iostream>`

`<iostream>` — стандартный заголовочный файл для ввода/вывода.  
Предоставляет объекты `std::cin`, `std::cout`, `std::cerr`, `std::endl`.

### `std::cout`

```cpp
std::cout << "Hello, world!\n";
```

- `std::cout` — поток стандартного вывода (консоль).
- `<<` — оператор вставки (insertion operator).
- `"\n"` лучше `std::endl` — не сбрасывает буфер лишний раз.

### Компиляция и запуск (Windows, Developer PowerShell)

```powershell
# Собрать весь проект:
cmake -S . -B build -G "Visual Studio 18 2026" -A x64
cmake --build build --config Debug

# Запустить задание:
.\build\Debug\lesson_01_task01_hello.exe
```

### Задания

| Файл | Описание |
|------|----------|
| `src/task01_hello.cpp` | Вывести «Hello, world!» |
