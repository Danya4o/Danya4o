#include <iostream>
#include <string>
#include <regex>

int main() {
    system("chcp 65001 > nul");
    std::cout << "=== РЕГУЛЯРНЫЕ ВЫРАЖЕНИЯ ===" << std::endl;

    // Валидация email-адресов
    std::cout << "\n--- Проверка email ---" << std::endl;
    std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    std::string emails[] = {
        "user@example.com",
        "invalid.email",
        "test.user@domain.org",
        "@missing.com",
        "spaces in@email.com"
    };

    for (int i = 0; i < 5; i++) {
        bool valid = std::regex_match(emails[i], emailPattern);
        std::cout << emails[i] << " : " << (valid ? "корректный" : "некорректный") << std::endl;
    }

    // Валидация телефонных номеров
    std::cout << "\n--- Проверка телефона ---" << std::endl;
    std::regex phonePattern(R"(\+7[\s-]?\(?[0-9]{3}\)?[\s-]?[0-9]{3}[\s-]?[0-9]{2}[\s-]?[0-9]{2})");

    std::string phones[] = {
        "+7 (999) 123-45-67",
        "+79991234567",
        "+7-999-123-45-67",
        "89991234567",
        "+7(999)1234567"
    };

    for (int i = 0; i < 5; i++) {
        bool valid = std::regex_match(phones[i], phonePattern);
        std::cout << phones[i] << " : " << (valid ? "корректный" : "некорректный") << std::endl;
    }

    // Извлечение числовых данных
    std::cout << "\n--- Извлечение чисел ---" << std::endl;
    std::string text = "Цена: 1500 руб, скидка 20%, итого 1200 руб.";
    std::regex numberPattern(R"(\d+)");

    std::cout << "Текст: " << text << std::endl;
    std::cout << "Найденные числа: ";

    std::sregex_iterator begin(text.begin(), text.end(), numberPattern);
    std::sregex_iterator end;

    for (auto it = begin; it != end; ++it) {
        std::cout << it->str() << " ";
    }
    std::cout << std::endl;

    // Замена с использованием regex
    std::cout << "\n--- Замена с regex ---" << std::endl;
    std::string censored = std::regex_replace(text, numberPattern, "***");
    std::cout << "После замены чисел: " << censored << std::endl;

    return 0;
}
