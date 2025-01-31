Задание 1

#include <iostream>

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

    bool operator==(const Seconds& other) const { // Оператор сравнения
        return time == other.time;
    }
};

void modifyTime(Seconds& sec, int newTime) {
    sec.setTime(newTime);
}

int main() {
    Seconds sec1(10);
    Seconds sec2(20);

    sec1.display();
    sec2.display();

    modifyTime(sec1, 15);
    
    sec1.display();

    if (sec1 == sec2) {
        std::cout << "Объекты равны." << std::endl;
    } else {
        std::cout << "Объекты не равны." << std::endl;
    }

    return 0;
}

Задание 2

#include <iostream>

class Seconds {
private:
    int time; // Время в секундах
public:
    Seconds(int t) : time(t) {} // Конструктор

    void display() const { // Метод для отображения времени

        std::cout << "Время: " << time << " секунды" << std::endl;
    }
};

int main() {
    Seconds* sec1 = new Seconds(30);
    Seconds* sec2 = new Seconds(45);

    sec1->display();
    sec2->display();

    // Освобождение памяти
    delete sec1;
    delete sec2;

    return 0;
}

Задание 3

#include <iostream>

class Seconds {
private:
    int time; // Время в секундах
public:
    Seconds(int t) : time(t) {} // Конструктор

    void display() const { // Метод для отображения времени
        std::cout << "Time: " << time << " seconds" << std::endl;
    }
};

int main() {
    // Создание безымянного объекта в динамической памяти
    new Seconds(60); // Этот объект не сохраняется в указателе и не может быть освобожден

    // Утечка памяти, так как мы не можем удалить этот объект позже

    return 0;
}

Объяснение: В задании создается объект Seconds в динамической памяти без указателя, что приводит к утечке памяти, так как мы не можем освободить память, занятую этим объектом. Чтобы избежать этого, всегда следует сохранять адрес динамически выделенного объекта в указателе и освобождать его после использования.
