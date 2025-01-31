Задание 1
  
#include <iostream>

class Seconds {
private:
    int time; // Время в секундах
public:
    // Конструктор с параметром
    Seconds(int t) : time(t) {} 

    // Метод для отображения времени
    void display() const { 
        std::cout << "Время: " << time << " секунды" << std::endl;
    }
};

int main() {
    int n;
    std::cout << "Введите количество объектов Seconds: ";
    std::cin >> n;

    // Выделение динамической памяти для массива указателей на объекты Seconds
    Seconds** secondsArray = new Seconds*[n];

    // Инициализация объектов
    for (int i = 0; i < n; ++i) {
        int inputTime;
        std::cout << "Введите время в секундах для объекта " << i + 1 << ": ";
        std::cin >> inputTime;
        secondsArray[i] = new Seconds(inputTime); // Создание объекта с помощью конструктора
    }

    // Вывод значений на экран
    for (int i = 0; i < n; ++i) {
        secondsArray[i]->display(); // Используем оператор -> для доступа к методу
    }

    // Освобождение выделенной памяти
    for (int i = 0; i < n; ++i) {
        delete secondsArray[i]; // Удаляем каждый объект
    }
    delete[] secondsArray; // Удаляем массив указателей

    return 0;
}

Задание 2

#include <iostream>
#include <vector>

class Seconds {
private:
    int time; // Время в секундах
public:
    Seconds(int t) : time(t) {} // Конструктор

    void display() const { // Метод для отображения времени
        std::cout << "Время: " << time << " секунды" << std::endl;
    }

    void setTime(int t) { // Метод для изменения времени
        time = t;
    }
};

int main() {
    std::vector<Seconds> secondsVector;

    // Добавление объектов в вектор
    for (int i = 0; i < 3; ++i) {
        int inputTime;
        std::cout << "Введите время в секундах для объекта " << i + 1 << ": ";
        std::cin >> inputTime;
        secondsVector.emplace_back(inputTime);
    }

    // Вывод значений на экран
    for (const auto& sec : secondsVector) {
        sec.display();
    }

    // Изменение значения определенного элемента
    int index, newTime;
    std::cout << "Введите индекс объекта, который необходимо изменить (от 0 до " << secondsVector.size() - 1 << "): ";
    std::cin >> index;
    if (index >= 0 && index < secondsVector.size()) {
        std::cout << "Введите новое время в секундах: ";
        std::cin >> newTime;
        secondsVector[index].setTime(newTime);
    } else {
        std::cout << "Неверный индекс!" << std::endl;
    }

    // Вывод обновленных значений
    for (const auto& sec : secondsVector) {
        sec.display();
    }

    return 0;
}
