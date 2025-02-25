#include <iostream>
#include <string>
using namespace std;

// Базовый класс Character
class Character {
protected:
    string name;

public:
    Character(const string& n) : name(n) {}

    virtual void introduce() const {
        cout << "I am " << name << "." << endl;
    }
};

// Интерфейс Hero с виртуальным наследованием
class Hero : virtual public Character {
public:
    Hero(const string& n) : Character(n) {}

    void introduce() const override {
        cout << "I am " << name << ". I am a hero." << endl;
    }
};

// Интерфейс Villain с виртуальным наследованием
class Villain : virtual public Character {
public:
    Villain(const string& n) : Character(n) {}

    void introduce() const override {
        cout << "I am " << name << ". I am a villain." << endl;
    }
};

// Класс AntiHero, наследующий Hero и Villain
class AntiHero : public Hero, public Villain {
public:
    AntiHero(const string& n) : Character(n), Hero(n), Villain(n) {}

    void introduce() const override {
        cout << "I am " << name << ". I am both a hero and a villain. I do what I want!" << endl;
    }
};

int main() {
    AntiHero ah("Deadpool");
    ah.introduce();  // Вывод: "I am Deadpool. I am both a hero and a villain. I do what I want!"
    return 0;
}
