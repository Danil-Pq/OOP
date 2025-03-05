#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

    using namespace std;

    // Функция для выбора слова в зависимости от уровня сложности
    string getWord(int difficulty) {
        vector<string> easyWords = { "cat", "dog", "bat" };
        vector<string> mediumWords = { "apple", "grape", "orange" };
        vector<string> hardWords = { "computer", "programming", "development" };

        switch (difficulty) {
        case 1: // Легкий уровень
            return easyWords[rand() % easyWords.size()];
        case 2: // Средний уровень
            return mediumWords[rand() % mediumWords.size()];
        case 3: // Сложный уровень
            return hardWords[rand() % hardWords.size()];
        default:
            return "";
        }
    }

    void displayStatus(const string & word, const string & guessedLetters) {
        for (char c : word) {
            if (guessedLetters.find(c) != string::npos) {
                cout << c << " ";
            }
            else {
                cout << "_ ";
            }
        }
        cout << '\n';
    }

    int main() {
        setlocale(LC_ALL, "Russian");
        srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

        int difficulty;
        cout << "Выберите уровень сложности (1 - легкий, 2 - средний, 3 - сложный): ";
        cin >> difficulty;

        string word = getWord(difficulty);
        string guessedLetters;
        int attempts = 6; // Количество попыток

        cout << "Добро пожаловать в игру Виселица!" << '\n';

        while (attempts > 0) {
            displayStatus(word, guessedLetters);
            cout << "Оставшиеся попытки: " << attempts << '\n';

            char guess;
            cout << "Введите букву: ";
            cin >> guess;

            if (guessedLetters.find(guess) == string::npos) {
                guessedLetters += guess; // Добавляем букву в угаданные
                if (word.find(guess) == string::npos) {
                    attempts--; // Уменьшаем количество попыток
                    cout << "Неправильно!" << '\n';
                }
                else {
                    cout << "Правильно!" << '\n';
                }
            }
            else {
                cout << "Вы уже угадали эту букву!" << '\n';
            }

            // Проверка на выигрыш
            bool won = true;
            for (char c : word) {
                if (guessedLetters.find(c) == string::npos) {
                    won = false;
                    break;
                }
            }

            if (won) {
                cout << "Поздравляю! Вы угадали слово: " << word << '\n';
                break;
            }
        }

        if (attempts == 0) {
            cout << "Вы проиграли! Загаданное слово: " << word <<  '\n';
        }

        return 0;
    }

Вывод

Выберите уровень сложности (1 - легкий, 2 - средний, 3 - сложный): 1
Добро пожаловать в игру Виселица!
_ _ _
Оставшиеся попытки: 6
Введите букву: с
Неправильно!
_ _ _
Оставшиеся попытки: 5
Введите букву: c
Правильно!
c _ _
Оставшиеся попытки: 5
Введите букву: a
Правильно!
c a _
Оставшиеся попытки: 5
Введите букву: t
Правильно!
Поздравляю! Вы угадали слово: cat

