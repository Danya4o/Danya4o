#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif

// Валидация номера полиса (формат: MP-1234)
bool validatePolicyNumber(const std::string& number) {
    std::regex numberPattern(R"(MP-\d{4})", std::regex::icase);
    return std::regex_match(number, numberPattern);
}

// Валидация срока действия (формат: ДД.ММ.ГГГГ)
bool validateDuration(const std::string& date) {
    std::regex datePattern(R"((0[1-9]|[12][0-9]|3[01])\.(0[1-9]|1[0-2])\.\d{4})");
    return std::regex_match(date, datePattern);
}

// Валидация суммы (положительное число, максимум 2 знака после точки)
bool validateAmount(const std::string& amount) {
    std::regex amountPattern(R"(\d+(\.\d{1,2})?)");
    return std::regex_match(amount, amountPattern);
}

// Разбор номера полиса
void parsePolicyNumber(const std::string& number) {
    if (!validatePolicyNumber(number)) {
        std::cout << "Некорректный номер полиса" << std::endl;
        return;
    }

    std::cout << "Анализ полиса: " << number << std::endl;
    std::cout << "  Префикс: " << number.substr(0, 2) << std::endl;
    std::cout << "  Номер:   " << number.substr(3) << std::endl;

    int num = std::stoi(number.substr(3));
    if (num < 1000) std::cout << "  Категория: Ранние полисы" << std::endl;
    else if (num < 5000) std::cout << "  Категория: Текущие полисы" << std::endl;
    else std::cout << "  Категория: Новые полисы" << std::endl;
}

// Разбор даты срока действия
void parseDuration(const std::string& date) {
    if (!validateDuration(date)) {
        std::cout << "Некорректная дата" << std::endl;
        return;
    }

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    std::cout << "Анализ срока действия:" << std::endl;
    std::cout << "  День:   " << day << std::endl;
    std::cout << "  Месяц:  " << month << std::endl;
    std::cout << "  Год:    " << year << std::endl;

    if (year < 2024) std::cout << "  Категория: Старый срок" << std::endl;
    else if (year < 2027) std::cout << "  Категория: Действующий срок" << std::endl;
    else std::cout << "  Категория: Долгосрочный срок" << std::endl;
}

// Разбор суммы
void parseAmount(const std::string& amount) {
    if (!validateAmount(amount)) {
        std::cout << "Некорректная сумма" << std::endl;
        return;
    }

    double value = std::stod(amount);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Анализ суммы: " << value << " руб." << std::endl;

    if (value < 10000) std::cout << "  Категория: Минимальная страховка" << std::endl;
    else if (value < 100000) std::cout << "  Категория: Стандартная страховка" << std::endl;
    else std::cout << "  Категория: Премиум-страховка" << std::endl;
}

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    std::cout << "=== МЕДИЦИНСКОЕ СТРАХОВАНИЕ: ВАЛИДАТОР ДАННЫХ ===" << std::endl;

    int choice;
    do {
        std::cout << "\n1. Проверить номер полиса (MP-XXXX)" << std::endl;
        std::cout << "2. Проверить срок действия (ДД.ММ.ГГГГ)" << std::endl;
        std::cout << "3. Проверить сумму (руб.)" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> choice;
        std::cin.ignore();

        std::string input;

        switch (choice) {
        case 1:
            std::cout << "Введите номер полиса (например, MP-1234): ";
            std::getline(std::cin, input);
            if (validatePolicyNumber(input)) {
                std::cout << "Номер полиса корректен." << std::endl;
                parsePolicyNumber(input);
            }
            else {
                std::cout << "Номер полиса некорректен." << std::endl;
                std::cout << "Формат: MP-XXXX (4 цифры)" << std::endl;
            }
            break;

        case 2:
            std::cout << "Введите срок действия (ДД.ММ.ГГГГ): ";
            std::getline(std::cin, input);
            if (validateDuration(input)) {
                std::cout << "Срок действия корректен." << std::endl;
                parseDuration(input);
            }
            else {
                std::cout << "Срок действия некорректен." << std::endl;
                std::cout << "Формат: ДД.ММ.ГГГГ" << std::endl;
            }
            break;

        case 3:
            std::cout << "Введите сумму (например, 25000 или 25000.50): ";
            std::getline(std::cin, input);
            if (validateAmount(input)) {
                std::cout << "Сумма корректна." << std::endl;
                parseAmount(input);
            }
            else {
                std::cout << "Сумма некорректна." << std::endl;
                std::cout << "Формат: положительное число, до 2 знаков после точки" << std::endl;
            }
            break;

        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;

        default:
            std::cout << "Неверный пункт меню." << std::endl;
        }
    } while (choice != 0);

    return 0;
}