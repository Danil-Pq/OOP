#include <iostream>
using namespace std;

// Базовый класс GameCharacter
class GameCharacter {
protected:
    int health;

public:
    GameCharacter(int h) : health(h) {}

    virtual void displayInfo() const {
        cout << "Health: " << health << endl;
    }
};

// Интерфейс Warrior с виртуальным наследованием
class Warrior : virtual public GameCharacter {
protected:
    int attack;

public:
    Warrior(int h, int a) : GameCharacter(h), attack(a) {}

    void displayInfo() const override {
        cout << "Health: " << health << ", Attack: " << attack << endl;
    }
};

// Интерфейс Mage с виртуальным наследованием
class Mage : virtual public GameCharacter {
protected:
    int mana;

public:
    Mage(int h, int m) : GameCharacter(h), mana(m) {}

    void displayInfo() const override {
        cout << "Health: " << health << ", Mana: " << mana << endl;
    }
};

// Класс BattleMage, наследующий Warrior и Mage
class BattleMage : public Warrior, public Mage {
public:
    BattleMage(int h, int a, int m) 
        : GameCharacter(h), Warrior(h, a), Mage(h, m) {}

    void displayInfo() const override {
        cout << "Health: " << health << ", Mana: " << mana << ", Attack: " << attack << endl;
    }
};

int main() {
    BattleMage bm(100, 50, 200);
    bm.displayInfo();  // Вывод: "Health: 100, Mana: 200, Attack: 50"
    return 0;
}
