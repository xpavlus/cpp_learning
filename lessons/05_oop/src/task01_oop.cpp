// Задание 01: Классы и объекты — инкапсуляция, конструктор, методы
// Тема: OOP
//
// TODO:
//   Реализуй класс BankAccount (банковский счёт):
//
//   Поля (private):
//     - std::string owner   — имя владельца
//     - double balance      — текущий баланс
//
//   Методы (public):
//     - Конструктор BankAccount(std::string name, double initialBalance)
//       Инициализирует owner и balance через список инициализации.
//
//     - void deposit(double amount)
//       Пополняет баланс на amount. Если amount <= 0 — ничего не делает.
//
//     - bool withdraw(double amount)
//       Снимает amount со счёта. Если средств недостаточно или amount <= 0 — возвращает false.
//       Иначе уменьшает баланс и возвращает true.
//
//     - double getBalance() const
//       Возвращает текущий баланс (метод не меняет объект — используй const).
//
//     - void printInfo() const
//       Выводит: "Account[Alice]: 1500.50"
//
//   В main():
//     1. Создай счёт для "Alice" с балансом 1000.0
//     2. Пополни на 500.5
//     3. Попробуй снять 200.0 — выведи результат (успех/неудача)
//     4. Попробуй снять 2000.0 — выведи результат
//     5. Вызови printInfo()

#include <iostream>
#include <string>

// TODO: объяви класс BankAccount здесь

int main() {
    // ваш код здесь
    return 0;
}
