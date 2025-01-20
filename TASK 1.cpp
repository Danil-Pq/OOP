Задание №1

#include <iostream>
#include <string>

class Product {
private:
    std::string name;   // Название товара
    double price;       // Цена товара
    int quantity;       // Количество товара на складе

public:
    // Конструктор класса
    Product(const std::string& name, double price, int quantity)
        : name(name), price(price), quantity(quantity) {
        // Устанавливаем количество товара в 0, если оно отрицательное
        if (this->quantity < 0) {
            this->quantity = 0;
        }
    }

    // Методы доступа и обновления
    void setName(const std::string& name) {
        this->name = name;
    }

    std::string getName() const {
        return name;
    }

    void setPrice(double price) {
        if (price >= 0) {
            this->price = price;
        } else {
            std::cout << "Цена не может быть отрицательной." << std::endl;
        }
    }

    double getPrice() const {
        return price;
    }

    void setQuantity(int quantity) {
        if (quantity >= 0) {
            this->quantity = quantity;
        } else {
            std::cout << "Количество не может быть отрицательным." << std::endl;
        }
    }

    int getQuantity() const {
        return quantity;
    }

    // Метод для продажи товара
    void sell(int amount) {
        if (amount > 0 && quantity >= amount) {
            quantity -= amount;
            std::cout << "Продано " << amount << " единиц товара: " << name << std::endl;
        } else {
            std::cout << "Недостаточно товара для продажи." << std::endl;
        }
    }
};

// Пример использования класса Product
int main() {
    Product apple("Яблоко", 1.50, 10);
    apple.sell(2);
    std::cout << "Осталось " << apple.getQuantity() << " яблок." << std::endl;
    apple.sell(9);  // Попытка продать больше, чем есть в наличии
    std::cout << "Осталось " << apple.getQuantity() << " яблок." << std::endl;

    return 0;
}

Задание №2

#include <iostream>

class TimePeriod {
private:
    int startHour;
    int startMinute;
    int startSecond;
    int endHour;
    int endMinute;
    int endSecond;

    // Проверяем корректность времени
    bool isValidTime(int hour, int minute, int second) const {
        return hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60;
    }

public:
    // Конструктор класса
    TimePeriod(int startHour, int startMinute, int startSecond,
               int endHour, int endMinute, int endSecond) {
        if (isValidTime(startHour, startMinute, startSecond) &&
            isValidTime(endHour, endMinute, endSecond)) {
            this->startHour = startHour;
            this->startMinute = startMinute;
            this->startSecond = startSecond;
            this->endHour = endHour;
            this->endMinute = endMinute;
            this->endSecond = endSecond;
        } else {
            throw std::invalid_argument("Некорректное время.");
        }
    }

    // Метод для отображения временного промежутка
    void display() const {
        std::cout << "Начало: " << startHour << ":" << startMinute << ":" << startSecond
                  << ", Конец: " << endHour << ":" << endMinute << ":" << endSecond << std::endl;
    }
};

// Пример использования класса TimePeriod
int main() {
    try {
        TimePeriod period(10, 30, 25, 15, 45, 55);
        period.display();
    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
