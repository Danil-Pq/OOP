#include <iostream>

// Продукты A
class AbstractProductA {
public:
    virtual void doSomething() = 0;
};

// Продукты B
class AbstractProductB {
public:
    virtual void doSomethingElse() = 0;
};

// Конкретные продукты A1
class ProductA1 : public AbstractProductA {
public:
    void doSomething() override {
        std::cout << "ProductA1 doing something." << '\n';
    }
};

// Конкретные продукты A2
class ProductA2 : public AbstractProductA {
public:
    void doSomething() override {
        std::cout << "ProductA2 doing something." << '\n';
    }
};

// Конкретный продукт B1
class ProductB1 : public AbstractProductB {
public:
    void doSomethingElse() override {
        std::cout << "ProductB1 doing something else." << '\n';
    }
};

// Конкретный продукт B2
class ProductB2 : public AbstractProductB {
public:
    void doSomethingElse() override {
        std::cout << "ProductB2 doing something else." << '\n';
    }
};

// Абстрактная фабрика
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// Конкретная фабрика 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ProductA1();
    }
    AbstractProductB* createProductB() override {
        return new ProductB1();
    }
};

// Конкретная фабрика 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ProductA2();
    }
    AbstractProductB* createProductB() override {
        return new ProductB2();
    }
};

// Клиентский код
void clientCode(AbstractFactory* factory) {
    AbstractProductA* productA = factory->createProductA();
    AbstractProductB* productB = factory->createProductB();

    productA->doSomething();
    productB->doSomethingElse();

    delete productA;
    delete productB;
}

int main() {
    AbstractFactory* factory1 = new ConcreteFactory1();
    clientCode(factory1);
    delete factory1;

    AbstractFactory* factory2 = new ConcreteFactory2();
    clientCode(factory2);
    delete factory2;

    return 0;
}

Вывод

ProductA1 doing something.
ProductB1 doing something else.
ProductA2 doing something.
ProductB2 doing something else.
