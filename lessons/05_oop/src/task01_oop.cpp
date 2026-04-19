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

class Person {
    private:
        std::string name;
        int age;
        std::string address;
    public:
        Person(std::string name, int age = 0, std::string address = "Unknown")
            : name(name), age(age), address(address) {
                if (age < 0) {
                    std::cout << "Возраст не может быть отрицательным. Устанавливаем возраст в 0." << std::endl;
                    this->age = 0;
                }
            }
        std::string toString() const {
            return "Name: " + name + ", Age: " + std::to_string(age) + ", Address: " + address;
        }
        void printInfo() const {
            std::cout << "Person[" << std::endl;
            std::cout << toString() << std::endl;
            std::cout << "]" << std::endl;
        }
};

class BankAccount {
    private:
        Person owner;
        double balance;
    public:
        BankAccount(std::string name, int age = 0, double initialBalance = 0.0) 
            : owner(name, age), balance(initialBalance) {
                if (initialBalance < 0) {
                    std::cout << "Начальный баланс не может быть отрицательным. Устанавливаем баланс в 0." << std::endl;
                    balance = 0;
                }
            }
        bool deposit(double amount) {
            if (amount <= 0) {
                return false;
            }
            if (amount > std::numeric_limits<double>::max() - balance) {
                return false;
            }
            balance += amount;
            return true;
        }
        bool withdraw(double amount) {
            if (amount <= 0 || amount > balance) {
                return false;
            }
            balance -= amount;
            return true;
        }
        double getBalance() const {
            return balance;
        }
        void printInfo() const {
            std::cout << "Account[" << owner.toString() << "]:" << std::endl;
            std::cout << "Balance: " << getBalance() << std::endl;
        }
};

    

int main() {
    BankAccount aliceAccount("Alice", 30, 1000.0);
    if (aliceAccount.deposit(500.5)) {
        std::cout << "Депозит 500.5 успешен" << std::endl;
    } else {
        std::cout << "Депозит 500.5 не удался" << std::endl;
    }
    if (aliceAccount.withdraw(200.0)) {
        std::cout << "Снятие 200.0 успешно" << std::endl;
    } else {
        std::cout << "Снятие 200.0 не удалось" << std::endl;
    }
    if (aliceAccount.withdraw(2000.0)) {
        std::cout << "Снятие 2000.0 успешно" << std::endl;
    } else {
        std::cout << "Снятие 2000.0 не удалось" << std::endl;
    }
    aliceAccount.printInfo();

}
