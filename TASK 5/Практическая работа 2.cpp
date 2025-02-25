Практическая работа №1
  
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    double salary;

public:
    Employee(const string& n, double s) : name(n), salary(s) {}

    virtual void printInfo() const {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(const string& n, double s, double b) : Employee(n, s), bonus(b) {}

    void printInfo() const override {
        cout << "Name: " << name << ", Salary: " << salary << ", Bonus: " << bonus << endl;
    }
};

int main() {
    Employee emp("Alice", 50000);
    Manager mgr("Bob", 70000, 10000);

    Employee* ptr = &mgr;  // Указатель на базовый класс
    ptr->printInfo();      // Вывод: "Name: Bob, Salary: 70000, Bonus: 10000"

    return 0;
}

Практическая работа №2

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(const string& n, int a) : name(n), age(a) {}

    virtual void printInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : virtual public Person {
protected:
    string university;

public:
    Student(const string& n, int a, const string& u) : Person(n, a), university(u) {}

    void printInfo() const override {
        cout << "Name: " << name << ", Age: " << age << ", University: " << university << endl;
    }
};

class Worker : virtual public Person {
protected:
    string company;

public:
    Worker(const string& n, int a, const string& c) : Person(n, a), company(c) {}

    void printInfo() const override {
        cout << "Name: " << name << ", Age: " << age << ", Company: " << company << endl;
    }
};

class Intern : public Student, public Worker {
public:
    Intern(const string& n, int a, const string& u, const string& c)
        : Person(n, a), Student(n, a, u), Worker(n, a, c) {}

    void printInfo() const override {
        cout << "Name: " << name << ", Age: " << age << ", University: " << university << ", Company: " << company << endl;
    }
};

int main() {
    Intern intern("Charlie", 20, "MIT", "Google");
    intern.printInfo();  // Вывод: "Name: Charlie, Age: 20, University: MIT, Company: Google"

    return 0;
}
