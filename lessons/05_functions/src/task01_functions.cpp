// Задание 01: Функции — объявление, перегрузка, параметры по умолчанию
// Тема: Functions
//
// TODO:
//   1. Напиши функцию `power(base, exp)`, которая возвращает base^exp (целые числа).
//      Используй цикл, не стандартную библиотеку.
//
//   2. Перегрузи `power` для типа double: `power(double base, int exp)`.
//
//   3. Напиши функцию `printLine(char ch, int count = 20)`, которая печатает
//      строку из `count` символов `ch`. Параметр count имеет значение по умолчанию 20.
//
//   4. В main() вызови:
//      - power(2, 10)          → должно вывести 1024
//      - power(1.5, 4)         → должно вывести 5.0625
//      - printLine('=')        → 20 символов '='
//      - printLine('-', 10)    → 10 символов '-'

#include <iostream>
#include <string>

int power(int base, int exponent) {
    int result = 1;

    for (int x=0; x < exponent; x++) {
        result = result * base;
    }

    return result;
}

double power(double base, int exponent) {
    double result = 1.0;

    for (int x = 0; x < exponent; x++) {
        result = result * base;
    }

    return result;
}

void printLine(char ch, int num=20) {
    std::string result = "";
    for (int x=0; x < num; x++) {
        result += ch;
    }
    std::cout << result << std::endl;
}

int main() {
    std::cout << power(2, 10) << std::endl;
    std::cout << power(1.5, 4) << std::endl;
    printLine('=');
    printLine('-', 10);
}
