#include <iostream>

/*
 * Программа: О себе
 * Автор: [Ваше имя]
 * Дата: [Текущая дата]
 * Группа: [Ваша группа]
 */

int main() {
    system("chcp 65001 > nul");
    // Заголовок
    std::cout << "================================" << std::endl;
    std::cout << "       Информация о студенте    " << std::endl;
    std::cout << "================================" << std::endl;

    // Личные данные
    std::cout << std::endl;
    std::cout << "Имя: [Ваше имя]" << std::endl;
    std::cout << "Группа: [Ваша группа]" << std::endl;
    std::cout << "Возраст: [Ваш возраст]" << std::endl;

    // Увлечения
    std::cout << std::endl;
    std::cout << "Мои увлечения:" << std::endl;
    std::cout << "  1. [Увлечение 1]" << std::endl;
    std::cout << "  2. [Увлечение 2]" << std::endl;
    std::cout << "  3. [Увлечение 3]" << std::endl;

    // Мотивация
    std::cout << std::endl;
    std::cout << "Почему я изучаю программирование:" << std::endl;
    std::cout << "[Ваш ответ]" << std::endl;

    std::cout << std::endl;
    std::cout << "================================" << std::endl;

    return 0;
}
