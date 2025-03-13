#include <iostream>
#include <vector>
#include <algorithm>

// Интерфейс наблюдателя
class IObserver {
public:
    virtual void update(float price) = 0;
};

// Конкретный наблюдатель
class Investor : public IObserver {
private:
    std::string name;
public:
    Investor(const std::string& name) : name(name) {}

    void update(float price) override {
        std::cout << "Инвестор " << name << " получил уведомление: новая цена акций " << price << '\n';
    }
};

// Субъект, уведомляющий наблюдателей
class Stock {
private:
    std::vector<IObserver*> observers;
    float price;
public:
    void subscribe(IObserver* observer) {
        observers.push_back(observer);
    }

    void unsubscribe(IObserver* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void setPrice(float newPrice) {
        price = newPrice;
        notifyObservers();
    }

    void notifyObservers() {
        for (auto observer : observers) {
            observer->update(price);
        }
    }
};

// Клиентский код
int main() {
    setlocale(LC_ALL, "Russian");
    Stock stock;

    Investor investor1("Алексей");
    Investor investor2("Екатерина");

    stock.subscribe(&investor1);
    stock.subscribe(&investor2);

    stock.setPrice(100.0f);

    stock.unsubscribe(&investor1);

    stock.setPrice(120.0f);

    return 0;
}
