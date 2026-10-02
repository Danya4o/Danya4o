#include <iostream>
#include <string>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif

const int MAX_RECORDS = 100;

int main() {
    #ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

    std::cout << "=== МЕДИЦИНСКОЕ СТРАХОВАНИЕ: СУММЫ ВЫПЛАТ ===" << std::endl;

    // Массивы данных
    std::string fullNames[MAX_RECORDS];      // ФИО застрахованного
    std::string policyNumbers[MAX_RECORDS];  // номер полиса
    std::string companies[MAX_RECORDS];      // страховая компания
    double payouts[MAX_RECORDS];             // сумма выплат (руб.)
    int count = 0;

    // Ввод данных
    std::cout << "Вводите данные о страховых выплатах"
              << " (пустое ФИО для завершения):" << std::endl;

    while (count < MAX_RECORDS) {
        std::string fullName;
        std::cout << "ФИО застрахованного: ";
        std::getline(std::cin, fullName);

        if (fullName.empty()) break;

        std::string policyNumber;
        std::cout << "Номер полиса: ";
        std::getline(std::cin, policyNumber);

        std::string company;
        std::cout << "Страховая компания: ";
        std::getline(std::cin, company);

        double payout;
        std::cout << "Сумма выплат (руб.): ";
        std::cin >> payout;
        std::cin.ignore();   // очистка буфера после числа

        fullNames[count] = fullName;
        policyNumbers[count] = policyNumber;
        companies[count] = company;
        payouts[count] = payout;
        count++;
    }

    if (count == 0) {
        std::cout << "Список записей пуст" << std::endl;
        return 0;
    }

    // Вывод всех записей
    std::cout << "\n=== ВСЕ ВЫПЛАТЫ ===" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << (i + 1) << ". " << fullNames[i]
                  << " | полис: " << policyNumbers[i]
                  << " | " << companies[i]
                  << " - выплата: " << payouts[i] << " руб." << std::endl;
    }

    // Статистика
    double minPayout = payouts[0];
    double maxPayout = payouts[0];
    double sum = 0;
    for (int i = 0; i < count; i++) {
        if (payouts[i] < minPayout) minPayout = payouts[i];
        if (payouts[i] > maxPayout) maxPayout = payouts[i];
        sum += payouts[i];
    }
    double avgPayout = sum / count;

    std::cout << "\n=== СТАТИСТИКА ===" << std::endl;
    std::cout << "Всего записей: " << count << std::endl;
    std::cout << "Минимальная выплата: " << minPayout << " руб." << std::endl;
    std::cout << "Максимальная выплата: " << maxPayout << " руб." << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Средняя выплата: " << avgPayout << " руб." << std::endl;
    std::cout << "Общая сумма выплат: " << sum << " руб." << std::endl;

    // Записи с выплатами выше среднего
    std::cout << "\n=== ВЫПЛАТЫ ВЫШЕ СРЕДНЕГО ===" << std::endl;
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (payouts[i] > avgPayout) {
            std::cout << "  " << fullNames[i]
                      << " (выплата: " << payouts[i] << " руб.)" << std::endl;
            found++;
        }
    }
    if (found == 0) {
        std::cout << "  Таких записей нет" << std::endl;
    }

    // Фильтрация по сумме выплат
    double threshold;
    std::cout << "\nВведите пороговое значение суммы выплат для фильтрации: ";
    std::cin >> threshold;

    std::cout << "\nЗаписи с выплатами >= " << threshold << " руб.:" << std::endl;
    found = 0;
    for (int i = 0; i < count; i++) {
        if (payouts[i] >= threshold) {
            std::cout << "  " << fullNames[i]
                      << " (выплата: " << payouts[i] << " руб.)" << std::endl;
            found++;
        }
    }
    if (found == 0) {
        std::cout << "  Записи с указанной суммой отсутствуют" << std::endl;
    }

    return 0;
}