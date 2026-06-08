// Урок 03 — Control Flow
// Задание: Угадай число
//
// Программа загадывает число от 1 до 10 (задай сам в коде).
// Пользователь вводит числа, пока не угадает.
// После каждой попытки выводи подсказку: "Больше", "Меньше" или "Угадал!".
// В конце выведи, сколько попыток потребовалось.
//
// Требования:
//  - используй do-while для основного цикла
//  - используй if/else if/else для подсказок
//  - используй переменную-счётчик попыток
//  - (бонус) если попыток > 5 — выведи "Следующий раз повезёт"
//
// Пример вывода:
//   Введите число (1-10): 5
//   Больше
//   Введите число (1-10): 8
//   Меньше
//   Введите число (1-10): 7
//   Угадал! Попыток: 3

#include <iostream>
#include <random>


int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1,10);

    int gues_num = dist(gen);

    std::cout << "Введи целое число от 1 до 10" << std::endl;
    int try_num;
    int try_count = 0;

    do {
        try_count++;
        std::cin >> try_num;
        if (try_num > gues_num) 
            std::cout << "Меньше" << std::endl;
        else if (try_num < gues_num)
            std::cout << "Больше" << std::endl;
        else
            break;
    } while (try_num != gues_num);
    
    std::cout << "Угадал! Попыток: " << try_count << std::endl;

    return 0;
}
