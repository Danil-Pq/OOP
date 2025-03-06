#include <iostream>
#include <vector>
#include <string>

// Интерфейс Наблюдателя
class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() {}
};

// Интерфейс Издателя
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify(const std::string& message) = 0;
    virtual ~Subject() {}
};

// Конкретный класс Издателя
class ConcreteSubject : public Subject {
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(const std::string& message) override {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }

    void changeState(const std::string& newState) {
        // Здесь меняем состояние и уведомляем наблюдателей
        std::cout << "State changed to: " << newState << std::endl;
        notify("State changed to: " + newState);
    }
};

// Конкретный класс Наблюдателя
class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update(const std::string& message) override {
        std::cout << name << " received update: " << message << std::endl;
    }
};

// Пример использования
int main() {
    ConcreteSubject subject;

    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.changeState("New State");

    subject.detach(&observer1);

    subject.changeState("Another State");

    return 0;
}

Вывод:

State changed to: New State
Observer 1 received update: State changed to: New State
Observer 2 received update: State changed to: New State
State changed to: Another State
Observer 2 received update: State changed to: Another State
