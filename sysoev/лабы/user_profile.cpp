#include <iostream>
#include <string>

int main() {
    system("chcp 65001 > nul");
    // === ОБЪЯВЛЕНИЕ ПЕРЕМЕННЫХ ===

    // Личные данные (заполнить собственными данными)
    std::string firstName = "Даниил";     // Имя
    std::string lastName = "Сысоев";      // Фамилия
    int age = 16;                    // Возраст (целое число)
    char gender = 'M';              // Пол ('M' или 'F')
    double height = 1.97;            // Рост в метрах
    double weight = 70.0;            // Вес в килограммах

    // Учебные данные
    std::string group = "252";         // Номер группы
    int course = 2;                 // Курс (1-4)
    double averageGrade = 5.0;      // Средний балл
    bool hasScholarship = true;    // Наличие стипендии

    // Контактные данные
    std::string email = "daniilsysoev72@gmail.com";         // Адрес электронной почты
    std::string phone = "+7 (961) 667-18-08";         // Номер телефона

    // === ВЫВОД ИНФОРМАЦИИ ===

    std::cout << "==============================" << std::endl;
    std::cout << "     ПРОФИЛЬ ПОЛЬЗОВАТЕЛЯ     " << std::endl;
    std::cout << "==============================" << std::endl;

    std::cout << std::endl;
    std::cout << "--- Личные данные ---" << std::endl;
    std::cout << "Имя: " << firstName << std::endl;
    std::cout << "Фамилия: " << lastName << std::endl;
    std::cout << "Возраст: " << age << " лет" << std::endl;
    std::cout << "Пол: " << gender << std::endl;
    std::cout << "Рост: " << height << " м" << std::endl;
    std::cout << "Вес: " << weight << " кг" << std::endl;

    std::cout << std::endl;
    std::cout << "--- Учебные данные ---" << std::endl;
    std::cout << "Группа: " << group << std::endl;
    std::cout << "Курс: " << course << std::endl;
    std::cout << "Средний балл: " << averageGrade << std::endl;
    std::cout << "Стипендия: " << (hasScholarship ? "Да" : "Нет") << std::endl;

    std::cout << std::endl;
    std::cout << "--- Контактные данные ---" << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Телефон: " << phone << std::endl;

    std::cout << std::endl;
    std::cout << "==============================" << std::endl;

    return 0;
}
