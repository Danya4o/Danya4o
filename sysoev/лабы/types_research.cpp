#include <iostream>
#include <string>

int main() {
    system("chcp 65001 > nul");
    // 1. Размеры типов
    std::cout << "=== РАЗМЕРЫ ТИПОВ ===" << std::endl;
    std::cout << "bool:        " << sizeof(bool) << " байт" << std::endl;
    std::cout << "char:        " << sizeof(char) << " байт" << std::endl;
    std::cout << "short:       " << sizeof(short) << " байт" << std::endl;
    std::cout << "int:         " << sizeof(int) << " байт" << std::endl;
    std::cout << "long:        " << sizeof(long) << " байт" << std::endl;
    std::cout << "long long:   " << sizeof(long long) << " байт" << std::endl;
    std::cout << "float:       " << sizeof(float) << " байт" << std::endl;
    std::cout << "double:      " << sizeof(double) << " байт" << std::endl;

    std::cout << std::endl;

    // 2. Объявление переменных разных типов
    std::cout << "=== ПРИМЕРЫ ПЕРЕМЕННЫХ ===" << std::endl;

    int age = 20;
    std::cout << "int age = " << age << std::endl;

    double price = 149.99;
    std::cout << "double price = " << price << std::endl;

    char grade = 'A';
    std::cout << "char grade = " << grade << std::endl;

    bool isStudent = true;
    std::cout << "bool isStudent = " << isStudent << std::endl;

    std::string name = "Студент";
    std::cout << "string name = " << name << std::endl;

    return 0;
}
