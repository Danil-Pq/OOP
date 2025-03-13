#include <iostream>

// Интерфейсы оружия и брони
class IWeapon {
public:
    virtual void use() = 0;
};

class IArmor {
public:
    virtual void wear() = 0;
};

// Конкретные классы для Эльфов
class ElfWeapon : public IWeapon {
public:
    void use() override {
        std::cout << "Эльф использует лук!" << '\n';
    }
};

class ElfArmor : public IArmor {
public:
    void wear() override {
        std::cout << "Эльф надевает легкие доспехи!" << '\n';
    }
};

// Конкретные классы для Орков
class OrcWeapon : public IWeapon {
public:
    void use() override {
        std::cout << "Орк использует меч!" << '\n';
    }
};

class OrcArmor : public IArmor {
public:
    void wear() override {
        std::cout << "Орк надевает тяжелые доспехи!" << '\n';
    }
};

// Абстрактная фабрика
class ICharacterFactory {
public:
    virtual IWeapon* createWeapon() = 0;  // Возвращаем обычный указатель
    virtual IArmor* createArmor() = 0;     // Возвращаем обычный указатель
};

// Фабрика для Эльфов
class ElfFactory : public ICharacterFactory {
public:
    IWeapon* createWeapon() override {
        return new ElfWeapon();  // Создаем объект через оператор new
    }
    IArmor* createArmor() override {
        return new ElfArmor();  // Создаем объект через оператор new
    }
};

// Фабрика для Орков
class OrcFactory : public ICharacterFactory {
public:
    IWeapon* createWeapon() override {
        return new OrcWeapon();  // Создаем объект через оператор new
    }
    IArmor* createArmor() override {
        return new OrcArmor();  // Создаем объект через оператор new
    }
};

// Клиентский код
void createCharacter(ICharacterFactory* factory) {
    IWeapon* weapon = factory->createWeapon();
    IArmor* armor = factory->createArmor();

    weapon->use();
    armor->wear();

}

int main() {
    setlocale(LC_ALL, "Russian");
    ICharacterFactory* elfFactory = new ElfFactory();
    createCharacter(elfFactory);
    
    ICharacterFactory* orcFactory = new OrcFactory();
    createCharacter(orcFactory);


    return 0;
}
