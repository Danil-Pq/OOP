#include <iostream>
#include <mutex>

class Singleton {
public:
    // Удаляем операции копирования и присваивания
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Метод получения единственного экземпляра
    static Singleton& getInstance() {
        static Singleton instance; // Инициализация при первом вызове
        return instance;
    }

    void someBusinessLogic() {
        // Пример метода, который может выполнять логику
        std::cout << "Выполнение бизнес-логики" << '\n';
    }

private:
    // Приватный конструктор, чтобы предотвратить создание экземпляра
    Singleton() {
        std::cout << "Создание экземпляра Singleton" << '\n';
    }

    // Приватный деструктор
    ~Singleton() {}
};

int main() {
    setlocale(LC_ALL, "Russian");
    // Получение экземпляра Singleton и вызов метода
    Singleton::getInstance().someBusinessLogic();
    return 0;
}

Вывод 

Создание экземпляра Singleton
Выполнение бизнес-логики
