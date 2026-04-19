// Задание 01: Шаблоны — функции, классы, специализация
// Тема: Templates
//
// TODO:
//   1. Шаблонная функция clamp<T>(T value, T lo, T hi)
//      Ограничивает value диапазоном [lo, hi].
//      Работает для любого типа, у которого есть operator<.
//
//   2. Шаблонный класс TypedPair<T, U>
//      Хранит два значения разных типов.
//      Методы:
//        - TypedPair(T first, U second) — конструктор
//        - T first() const
//        - U second() const
//        - void swap()  — меняет значения местами (TypedPair<U,T> вернуть нельзя,
//                         поэтому просто своп полей, если T == U, иначе — static_assert)
//
//   3. Полная специализация шаблонной функции:
//      template<> bool clamp<bool>(bool value, bool lo, bool hi)
//      — всегда возвращает value без изменений (bool не имеет смысла "ограничивать")
//
//   4. Шаблонная функция print_type_info<T>(T val)
//      Используй <type_traits> и if constexpr, чтобы вывести:
//        "int: 42", "float: 3.14", "string: hello", "other" — для остальных.
//
//   5. В main():
//      - Проверь clamp для int, double, char
//      - Проверь специализацию clamp<bool>
//      - Создай TypedPair<int, std::string> и TypedPair<double, double>
//      - Вызови print_type_info для int, float, std::string, и какого-нибудь своего типа

#include <iostream>
#include <string>
#include <type_traits>

// ... твой код здесь

int main() {
    // ... твой код здесь
}
