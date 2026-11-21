#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функция 1: Ввод и проверка имени пользователя
string getValidUserName() {
    string name;
    while (true) {
        cout << "Введите имя пользователя (без пробелов): ";
        cin >> name;

        if (!name.empty()) {
            return name;
        }
        cout << "Ошибка: имя не может быть пустым. Попробуйте снова.\n";
    }
}

// Функция 2: Ввод, проверка и применение цвета консоли
string setAndGetValidConsoleColor(string color = "") {
    // Если цвет не передан (первый ввод или изменение), запрашиваем его с проверкой
    if (color.empty()) {
        while (true) {
            cout << "Выберите цвет текста (1 - Синий, 2 - Зелёный, 3 - Голубой, 4 - Красный, 5 - Фиолетовый, 6 - Жёлтый, 7 - Белый): ";
            cin >> color;

            if (color == "1" || color == "2" || color == "3" ||
                color == "4" || color == "5" || color == "6" || color == "7") {
                break;
            }
            cout << "Ошибка: неверный код цвета! Введите цифру от 1 до 7.\n";
        }
    }

    // Применяем выбранный цвет текста на чёрном фоне (0)
    string command = "color 0" + color;
    system(command.c_str());

    return color;
}

// Вспомогательная функция для сохранения настроек в файл
void saveSettings(const string& userName, const string& colorCode) {
    ofstream fout("settings_var1.txt");
    if (fout.is_open()) {
        fout << userName << "\n" << colorCode;
        fout.close();
    }
    else {
        cout << "Ошибка открытия файла для записи!\n";
    }
}

int main() {
    setlocale(0, "ru");

    string userName;
    string colorCode;

    ifstream fin("settings_var1.txt");

    // Проверяем, существует ли файл с сохранёнными настройками
    if (fin.is_open() && (fin >> userName >> colorCode)) {
        fin.close();

        // Восстанавливаем цвет консоли и выводим имя
        setAndGetValidConsoleColor(colorCode);
        cout << "Добро пожаловать, " << userName << "!" << endl;

        // Предлагаем изменить настройки
        char choice;
        cout << "\nХотите изменить настройки? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            userName = getValidUserName();
            colorCode = setAndGetValidConsoleColor();
            saveSettings(userName, colorCode);
            cout << "\nНастройки обновлены! Привет, " << userName << "!" << endl;
        }
    }
    else {
        // Если файла нет или он пуст — запрашиваем данные впервые
        if (fin.is_open()) fin.close();

        cout << "Файл настроек не найден. Выполните первичную настройку.\n";
        userName = getValidUserName();
        colorCode = setAndGetValidConsoleColor();
        saveSettings(userName, colorCode);

        cout << "\nНастройки сохранены! Привет, " << userName << "!" << endl;
    }

    return 0;
}

