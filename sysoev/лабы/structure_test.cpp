int main() {
    std::cout << "Hello"; //"cout": не является членом "std"
    return 0;
}


#include <iostream>

int start() {              //Ссылка на неразрешенный внешний символ _main
    std::cout << "Hello";
    return 0;
}


#include <iostream>

int main() {
    std::cout << "Hello"; //Компилятор автоматически  добавляет return 0; в конец main
}

#include <iostream>

int main() {
    cout << "Hello"; // cout необъявленный идентификатор 
    return 0;
}