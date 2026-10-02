#include <iostream>
#include <string>
#include <algorithm>

int main() {
    system("chcp 65001 > nul");
    std::string text;

    std::cout << "Введите текст: ";
    std::getline(std::cin, text);

    std::cout << "\n=== АНАЛИЗ СТРОКИ ===" << std::endl;
    std::cout << "Длина: " << text.length() << " символов" << std::endl;

    // Подсчет символов по категориям
    int letters = 0, digits = 0, spaces = 0, other = 0;
    for (char c : text) {
        if (isalpha(c)) letters++;
        else if (isdigit(c)) digits++;
        else if (isspace(c)) spaces++;
        else other++;
    }

    std::cout << "Букв: " << letters << std::endl;
    std::cout << "Цифр: " << digits << std::endl;
    std::cout << "Пробелов: " << spaces << std::endl;
    std::cout << "Других: " << other << std::endl;

    // Преобразование регистра
    std::string upper = text;
    std::string lower = text;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    std::cout << "\nВерхний регистр: " << upper << std::endl;
    std::cout << "Нижний регистр: " << lower << std::endl;

    // Реверс строки
    std::string reversed = text;
    std::reverse(reversed.begin(), reversed.end());
    std::cout << "Реверс: " << reversed << std::endl;

    // Проверка на палиндром
    std::string cleaned;
    for (char c : text) {
        if (isalnum(c)) cleaned += tolower(c);
    }
    std::string cleanedReversed = cleaned;
    std::reverse(cleanedReversed.begin(), cleanedReversed.end());

    if (cleaned == cleanedReversed && !cleaned.empty()) {
        std::cout << "\nСтрока является палиндромом." << std::endl;
    }

    return 0;
}
