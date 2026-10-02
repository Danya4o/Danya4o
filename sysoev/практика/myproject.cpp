#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    // Настройка кодировки консоли для Windows
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    std::cout << "=== МЕДИЦИНСКОЕ СТРАХОВАНИЕ ===" << std::endl;
    std::cout << std::endl;

    // Объявление переменных разных типов
    std::string fullName;       // ФИО владельца полиса
    std::string policyNumber;   // номер полиса
    std::string company;        // страховая компания
    double price;               // стоимость страховки, руб.
    int durationMonths;         // срок действия, мес.
    int monthsPassed;           // сколько месяцев прошло
    bool isActive;              // действует ли полис

    // Ввод данных (getline позволяет вводить строки с пробелами)
    std::cout << "Введите ФИО владельца полиса: ";
    std::getline(std::cin, fullName);

    std::cout << "Введите номер полиса: ";
    std::getline(std::cin, policyNumber);

    std::cout << "Введите страховую компанию: ";
    std::getline(std::cin, company);

    std::cout << "Введите стоимость страховки (руб): ";
    std::cin >> price;

    std::cout << "Введите срок действия (мес): ";
    std::cin >> durationMonths;

    std::cout << "Введите, сколько месяцев прошло: ";
    std::cin >> monthsPassed;

    // Вычисления
    double costPerMonth = price / durationMonths;     // стоимость в месяц
    int monthsLeft = durationMonths - monthsPassed;   // осталось месяцев
    if (monthsLeft < 0) monthsLeft = 0;               // не может быть отрицательным
    double tax = price * 0.13;                        // налоговый вычет 13%
    isActive = (monthsPassed < durationMonths);       // действует ли полис

    // Вывод результатов
    std::cout << std::endl;
    std::cout << "=== ИНФОРМАЦИЯ О ПОЛИСЕ ===" << std::endl;
    std::cout << "Владелец:           " << fullName << std::endl;
    std::cout << "Номер полиса:       " << policyNumber << std::endl;
    std::cout << "Страховая компания: " << company << std::endl;
    std::cout << "Стоимость:          " << price << " руб." << std::endl;
    std::cout << "Срок действия:      " << durationMonths << " мес." << std::endl;
    std::cout << "Стоимость в месяц:  " << costPerMonth << " руб." << std::endl;
    std::cout << "Прошло месяцев:     " << monthsPassed << " мес." << std::endl;
    std::cout << "Осталось месяцев:   " << monthsLeft << " мес." << std::endl;
    std::cout << "Налоговый вычет:    " << tax << " руб." << std::endl;
    std::cout << "Статус полиса:      " << (isActive ? "Действует" : "Истёк") << std::endl;

    return 0;
}