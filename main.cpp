#include <iostream>
#include <map>
#include <iterator>
#include <vector>
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
    cout << "no" << "\t" << "   name" << "\t\t\t   " << "price" << endl;
    for (auto it = foods.begin(); it != foods.end(); ++it) {
      cout << it->first << "\t" << it->second->getName() << "\t\t Rp." << it->second->getPrice() << endl;
    }
}

void printDrinks() {
    map<int, Menu*> drinks;
    drinks.insert(make_pair(1, new Menu("Coca cola", 4500)));
    drinks.insert(make_pair(2, new Menu("Sprite\t", 5000)));
    drinks.insert(make_pair(3, new Menu("Fruit Tea", 3500)));
    drinks.insert(make_pair(4, new Menu("Coffee\t", 7000)));
    drinks.insert(make_pair(5, new Menu("Water\t", 2000)));
    cout << "no" << "\t" << "   name" << "\t\t\t   " << "price" << endl;
    for (auto it = drinks.begin(); it != drinks.end(); ++it) {
      cout << it->first << "\t" << it->second->getName() << "\t\t Rp." << it->second->getPrice() << endl;
    }
}

void display() {
    char input;
    int orderNum, quantity;
    vector<Order*> orders;
    cout << "-----------------------------" << endl;
    cout << "Welcome to Amazing Restaurant" << endl;
    cout << "-----------------------------" << endl << endl;
    do {
        cout << "Do you want to order Food?" << endl;
        cin >> input;

        if(input=='y') {
            do {
                cout << "Please choose our Food by selecting number below:" << endl;
                printFoods();
                cout << endl;
                do {
                    cout << "Your Food order number?" << endl;
                    cin >> orderNum;
                    if(cin.fail()){
                        cin.clear(cin.rdstate() & ~ios_base::failbit);
                        cin.ignore();
                    }
                } while (orderNum <= 0 || orderNum > 6 && !cin.fail());
                cout << "How many quantity?" << endl;
                do {
                    cin >> quantity;
                    if(cin.fail()){
                        cout << "You entered an incorrect value. Try again" << endl;
                        cin.clear(cin.rdstate() & ~ios_base::failbit);
                        cin.ignore();
                    }
                } while (quantity <= 0 && !cin.fail());
                
                Order *order = new Order;
                order->setMenu = "sa";
                order->setQuantity = quantity;
                orders.push_back(*order);
                for(vector<Order>::iterator itr=orders.begin();itr!=orders.end();++itr)  
                    cout<<*itr << endl;
                do {
                    cout << "Do you want to order more?" << endl;
                    cin >> input;
                } while (input != 'y' && input != 'n');
            } while (input != 'n');
        }
    } while (input != 'n' && input != 'y');

    do {
        cout << "Do you want to order Drink?" << endl;
        cin >> input;

        if (input == 'y') {
            do {
                cout << "Please choose our Food by selecting number below:" << endl;
                printDrinks();
                cout << endl;
                do {
                    cout << "Your Drink order number?" << endl;
                    cin >> orderNum;
                } while (orderNum <= 0 || orderNum > 6 && !cin.fail());
                cout << "How many quantity?" << endl;
                do {
                    cin >> quantity;
                    if(cin.fail()){
                        cout << "You entered an incorrect value. Try again" << endl;
                        cin.clear(cin.rdstate() & ~ios_base::failbit);
                        cin.ignore();
                    }
                } while (quantity <= 0 && !cin.fail());
                // Order *order = new Order;
                // order->setMenu = "sa";
                // order->setQuantity = quantity;
                // orders.push_back(*order);
                // for(vector<Order>::iterator itr=orders.begin();itr!=orders.end();++itr)  
                //     cout<<*itr << endl;
                do {
                    cout << "Do you want to order more?";
                    cin >> input;
                } while (input != 'y' && input != 'n');
            } while (input != 'n');
        }
    } while (input != 'n' && input != 'y');
}

int main() {
    char input;
    do {
        display();
        do {
            cout << "Do you want to order more?" << endl;
            cin >> input;
        } while (input != 'n' && input != 'y');
    } while (input != 'n');
    cout << "Thank you for coming!";
    return 0;
}