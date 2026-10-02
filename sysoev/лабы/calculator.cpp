#include <iostream>
#include <iomanip>

int main() {
    system("chcp 65001 > nul");
    // === Шаг 2. Объявление переменных ===
    double num1, num2;
    char operation;
    double result;

    // === Шаг 3. Организация ввода данных ===
    std::cout << "=== ПРОСТОЙ КАЛЬКУЛЯТОР ===" << std::endl;
    std::cout << std::endl;

    std::cout << "Введите первое число: ";
    std::cin >> num1;

    std::cout << "Введите операцию (+, -, *, /, %): ";
    std::cin >> operation;

    std::cout << "Введите второе число: ";
    std::cin >> num2;

    // === Шаг 4. Выполнение вычисления ===
    bool valid = true;

    if (operation == '+') {
        result = num1 + num2;
    }
    else if (operation == '-') {
        result = num1 - num2;
    }
    else if (operation == '*') {
        result = num1 * num2;
    }
    else if (operation == '/') {
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            valid = false;
        }
    }
    else if (operation == '%') {
        // Остаток от деления работает только с целыми числами
        int int1 = static_cast<int>(num1);
        int int2 = static_cast<int>(num2);
        if (int2 != 0) {
            result = int1 % int2;
        }
        else {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            valid = false;
        }
    }
    else {
        std::cout << "Ошибка: неизвестная операция!" << std::endl;
        valid = false;
    }

    // === Шаг 5. Вывод результата ===
    if (valid) {
        std::cout << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << num1 << " " << operation << " " << num2
            << " = " << result << std::endl;
    }

    // === Шаг 6. Демонстрационный раздел ===
    std::cout << std::endl;
    std::cout << "=== ДЕМОНСТРАЦИЯ ОСОБЕННОСТЕЙ ===" << std::endl;

    // Целочисленное и вещественное деление
    std::cout << std::endl << "Деление 7 / 3:" << std::endl;
    std::cout << "  int / int    = " << (7 / 3) << std::endl;
    std::cout << "  double / int = " << (7.0 / 3) << std::endl;

    // Остаток от деления
    std::cout << std::endl << "Остаток от деления:" << std::endl;
    std::cout << "  10 % 3 = " << (10 % 3) << std::endl;
    std::cout << "  15 % 5 = " << (15 % 5) << std::endl;

    // Инкремент
    int x = 5;
    std::cout << std::endl << "Инкремент (x = 5):" << std::endl;
    std::cout << "  ++x = " << (++x) << ", после x = " << x << std::endl;
    x = 5;
    std::cout << "  x++ = " << (x++) << ", после x = " << x << std::endl;

    // Приоритет операций
    std::cout << std::endl << "Приоритет операций:" << std::endl;
    std::cout << "  2 + 3 * 4   = " << (2 + 3 * 4) << " (умножение первым)" << std::endl;
    std::cout << "  (2 + 3) * 4 = " << ((2 + 3) * 4) << std::endl;

    return 0;
}