#include <iostream>
#include <vector>

// Принцип разделения интерфейсов (ISP)
class IOrderSaver {
public:
    virtual ~IOrderSaver() {}
    virtual void save(const std::vector<std::string>& items) = 0;
};

// Класс для сохранения в файл (SRP)
class FileOrderSaver : public IOrderSaver {
public:
    void save(const std::vector<std::string>& items) override {
        std::cout << "Сохранение заказа в файл: ";
        for (const auto& item : items) {
            std::cout << item << " ";
        }
        std::cout << '\n';
    }
};

// Класс для сохранения в БД (OCP)
class DatabaseOrderSaver : public IOrderSaver {
public:
    void save(const std::vector<std::string>& items) override {
        std::cout << "Сохранение заказа в базу данных: ";
        for (const auto& item : items) {
            std::cout << item << " ";
        }
        std::cout << '\n';
    }
};

// Базовый класс заказа
class Order {
public:
    virtual ~Order() {}
    
    virtual void addItem(const std::string& item) {
        items_.push_back(item);
    }

    virtual void printOrder() const {
        std::cout << "Заказ: ";
        for (const auto& item : items_) {
            std::cout << item << " ";
        }
        std::cout << '\n';
    }

    // Принимаем указатель на интерфейс (DIP)
    virtual void saveOrder(IOrderSaver* saver) {
        saver->save(items_);
    }

protected:
    std::vector<std::string> items_;
};

// Онлайн заказ (LSP)
class OnlineOrder : public Order {
public:
    OnlineOrder(const std::string& deliveryAddress) : deliveryAddress_(deliveryAddress) {}

    void printOrder() const override {
        Order::printOrder();
        std::cout << "Адрес доставки: " << deliveryAddress_ << '\n';
    }

private:
    std::string deliveryAddress_;
};

int main() {
    // Создаем объекты для сохранения
    FileOrderSaver fileSaver;
    DatabaseOrderSaver dbSaver;

    // Обычный заказ
    std::cout << "--- Обычный заказ ---" << '\n';
    Order order;
    order.addItem("Пицца");
    order.addItem("Салат");
    order.printOrder();
    order.saveOrder(&fileSaver);
    
    // Онлайн заказ
    std::cout << "\n--- Онлайн заказ ---" << '\n';
    OnlineOrder onlineOrder("ул. Примерная, д. 123");
    onlineOrder.addItem("Суши");
    onlineOrder.addItem("Роллы");
    onlineOrder.printOrder();
    onlineOrder.saveOrder(&dbSaver);
    
    // Демонстрация OCP
    std::cout << "\n--- Новый способ сохранения ---" << '\n';
    order.saveOrder(&dbSaver);
    
    return 0;
}

Вывод
--- Обычный заказ ---
Заказ: Пицца Салат 
Сохранение заказа в файл: Пицца Салат 

--- Онлайн заказ ---
Заказ: Суши Роллы 
Адрес доставки: ул. Примерная, д. 123
Сохранение заказа в базу данных: Суши Роллы 

--- Новый способ сохранения ---
Сохранение заказа в базу данных: Пицца Салат 
