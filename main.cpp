#include <iostream>
#include <map>
#include <iterator>
using namespace std;

class Menu {
    private:
    string name;
    double price;

    public:
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    void setPrice(double price) {
        this->price = price;
    }
    double getPrice() {
        return price;
    }
    Menu(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

class Order {
    private:
    string menu;
    int quantity;

    public:
    void setMenu(string menu) {
        this->menu = menu;
    }
    string getMenu() {
        return menu;
    }
    void setQuantity(int quantity) {
        this->quantity = quantity;
    }
    int getQuantity() {
        return quantity;
    }

    Order(string menu, int quantity) {
        this->menu = menu;
        this->quantity = quantity;
    }
};

void printFoods() {
    map<int, Menu*> foods;
    foods.insert(make_pair(1, new Menu("Hamburger", 35000)));
    foods.insert(make_pair(2, new Menu("Sate Padang", 45000)));
    foods.insert(make_pair(3, new Menu("Fried Chicken", 15000)));
    foods.insert(make_pair(4, new Menu("Rendang Beef", 55000)));
    foods.insert(make_pair(5, new Menu("Fish n Chips", 65000)));
    cout << "no" << "\t" << "   name" << "\t\t" << "price" << endl;
    for (auto it = foods.begin(); it != foods.end(); ++it) {
      cout << it->first << "\t" << it->second->getName() << "\t" << it->second->getPrice() << endl;
    }
}

void display() {
    char input1, input2, input3;
    int orderNum;
    do {
        cout << "-----------------------------" << endl;
        cout << "Welcome to Amazing Restaurant" << endl;
        cout << "-----------------------------" << endl << endl;
        do {
            cout << "Do you want to order Food?" << endl;
            cin >> input1;
        } while (input1 != 'n' && input1 != 'y');
        cout << "Please choose our Food by selecting number below:" << endl;
        printFoods();
        cout << endl;
        do {
            cout << "Your Food order number?" << endl;
            cin >> orderNum;
        } while (orderNum <= 0 || orderNum > 6);
        do {
            cout << "Do you want to order Drink?" << endl;
            cin >> input2;
        } while (input2 != 'n');
        do {
            cout << "Do you want to order more?" << endl;
            cin >> input3;
        } while (input3 != 'n');
    } while (input3 != 'n');

}

void printDrinks() {
    map<int, Menu*> drinks;
    drinks.insert(make_pair(1, new Menu("Coca cola", 4500)));
    drinks.insert(make_pair(2, new Menu("Sprite\t", 5000)));
    drinks.insert(make_pair(3, new Menu("Fruit Tea", 3500)));
    drinks.insert(make_pair(4, new Menu("Coffee\t", 7000)));
    drinks.insert(make_pair(5, new Menu("Water\t", 2000)));
    cout << "no" << "\t" << "   name" << "\t\t" << "price" << endl;
    for (auto it = drinks.begin(); it != drinks.end(); ++it) {
      cout << it->first << "\t" << it->second->getName() << "\t" << it->second->getPrice() << endl;
    }
}

int main() {
    display();
    cout << "Thank you for coming!";
    // printDrinks();
    // Order order;
    // Menu("Ayam", 12000);
    return 0;
}