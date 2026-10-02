#include <iostream>
#include <string>

int main() {
    system("chcp 65001 > nul");
    std::string text = "The quick brown fox jumps over the lazy dog. The dog barks.";

    std::cout << "Исходный текст:\n" << text << std::endl;

    // Поиск подстроки
    std::string search;
    std::cout << "\nВведите искомую подстроку: ";
    std::getline(std::cin, search);

    size_t pos = text.find(search);
    if (pos != std::string::npos) {
        std::cout << "Найдено на позиции: " << pos << std::endl;

        // Поиск всех вхождений
        std::cout << "Все позиции: ";
        size_t count = 0;
        pos = 0;
        while ((pos = text.find(search, pos)) != std::string::npos) {
            std::cout << pos << " ";
            pos += search.length();
            count++;
        }
        std::cout << "\nВсего вхождений: " << count << std::endl;
    }
    else {
        std::cout << "Подстрока не найдена." << std::endl;
    }

    // Замена подстроки
    std::string replace;
    std::cout << "\nВведите строку для замены: ";
    std::getline(std::cin, replace);

    std::string result = text;
    pos = 0;
    while ((pos = result.find(search, pos)) != std::string::npos) {
        result.replace(pos, search.length(), replace);
        pos += replace.length();
    }

    std::cout << "\nРезультат:\n" << result << std::endl;

    return 0;
}
