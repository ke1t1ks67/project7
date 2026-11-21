#include <iostream>

int main() {
    int a = 5, b = 10;
    int max;

    // Находим максимальное число
    if (a > b) {
        max = a;
    }
    else {
        max = b;
    }

    // Проверяем на четность
    if (max % 2 == 0) {
        std::cout << "Число четное";
    }
    else {
        std::cout << "Число нечетное";
    }

    return 0;
}

