#include <iostream>
#include <iomanip>
#include <string>

int main() {
    system("chcp 65001 > nul");
    // === Шаг 2. Объявление переменных ===
    std::string firstName;   // Имя
    std::string lastName;    // Фамилия
    int age;                 // Возраст
    double height;           // Рост в метрах
    double weight;           // Вес в килограммах
    int course;              // Курс обучения

    // === Шаг 3. Организация ввода данных ===
    std::cout << "=== АНКЕТА СТУДЕНТА ===" << std::endl;
    std::cout << std::endl;

    std::cout << "Введите имя: ";
    std::cin >> firstName;

    std::cout << "Введите фамилию: ";
    std::cin >> lastName;

    std::cout << "Введите возраст: ";
    std::cin >> age;

    std::cout << "Введите рост (в метрах, например 1.75): ";
    std::cin >> height;

    std::cout << "Введите вес (в кг): ";
    std::cin >> weight;

    std::cout << "Введите курс обучения (1-4): ";
    std::cin >> course;

    // === Расчёт ИМТ ===
    double bmi = weight / (height * height);

    // === Шаг 5. Вывод результата с форматированием ===
    std::cout << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "           КАРТОЧКА СТУДЕНТА             " << std::endl;
    std::cout << "=========================================" << std::endl;

    std::cout << std::left;  // выравнивание по левому краю
    std::cout << std::setfill(' ') << std::setw(20) << "Фамилия:" << lastName << std::endl;
    std::cout << std::setw(20) << "Имя:" << firstName << std::endl;
    std::cout << std::setw(20) << "Возраст:" << age << " лет" << std::endl;
    std::cout << std::setw(20) << "Курс:" << course << std::endl;

    // Рост и вес с фиксированной точностью
    std::cout << std::setw(20) << "Рост:"
        << std::fixed << std::setprecision(2) << height << " м" << std::endl;
    std::cout << std::setw(20) << "Вес:"
        << std::fixed << std::setprecision(1) << weight << " кг" << std::endl;

    // ИМТ с точностью 1 знак после запятой
    std::cout << std::setw(20) << "ИМТ:"
        << std::fixed << std::setprecision(1) << bmi << std::endl;

    std::cout << "=========================================" << std::endl;

    return 0;
}