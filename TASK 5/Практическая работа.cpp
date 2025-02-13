Практическая работа №1

#include <iostream>

class Engine {
public:
    void run() {
        std::cout << "Двигатель работает." << std::endl;
    }
};

class Car {
private:
    Engine engine; // Композиция: Car управляет жизненным циклом Engine

public:
    void start() {
        engine.run(); // Вызов метода run() у Engine
    }
};

int main() {
    Car car;
    car.start(); // Запуск автомобиля
    return 0;
}

Практическая работа №2

#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    std::string name;

    Student(const std::string& name) : name(name) {}
};

class University {
private:
    std::vector<Student*> students; // Агрегация: University не управляет временем жизни Student

public:
    void addStudent(Student* student) {
        students.push_back(student);
    }

    void listStudents() {
        std::cout << "Студенты в университете:" << std::endl;
        for (const auto& student : students) {
            std::cout << student->name << std::endl;
        }
    }
};

int main() {
    University university;
    Student* student1 = new Student("Алиса");
    Student* student2 = new Student("Боб");

    university.addStudent(student1);
    university.addStudent(student2);
    university.listStudents();

    // Освобождение памяти
    delete student1;
    delete student2;

    return 0;
}

Практическая работа №3

#include <iostream>
#include <vector>
#include <string>

class Programmer; // Предварительное объявление

class Manager {
private:
    std::vector<Programmer*> programmers; // Менеджер хранит программистов

public:
    void addProgrammer(Programmer* programmer);
    void listProgrammers();
};

class Programmer {
private:
    Manager* manager; // Программист знает о своем менеджере
    std::string name;

public:
    Programmer(const std::string& name) : name(name), manager(nullptr) {}

    void setManager(Manager* mgr) {
        manager = mgr;
    }

    std::string getName() {
        return name;
    }
};

void Manager::addProgrammer(Programmer* programmer) {
    programmers.push_back(programmer);
    programmer->setManager(this); // Установка менеджера для программиста
}

void Manager::listProgrammers() {
    std::cout << "Программисты под этим менеджером:" << std::endl;
    for (const auto& programmer : programmers) {
        std::cout << programmer->getName() << std::endl;
    }
}

int main() {
    Manager manager;
    Programmer* programmer1 = new Programmer("Джон");
    Programmer* programmer2 = new Programmer("Джейн");

    manager.addProgrammer(programmer1);
    manager.addProgrammer(programmer2);
    manager.listProgrammers();

    // Освобождение памяти
    delete programmer1;
    delete programmer2;

    return 0;
}
  
