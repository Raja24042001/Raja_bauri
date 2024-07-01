#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item {
public:
    string name;
    int quantity;
    double price;

    Item(string n, int q, double p) : name(n), quantity(q), price(p) {}
};

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(string name, int quantity, double price) {
        items.push_back(Item(name, quantity, price));
        cout << "Item added: " << name << endl;
    }

    void removeItem(string name) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->name == name) {
                items.erase(it);
                cout << "Item removed: " << name << endl;
                return;
            }
        }
        cout << "Item not found: " << name << endl;
    }

    void displayInventory() {
        cout << "Inventory:\n";
        for (const auto& item : items) {
            cout << "Name: " << item.name << ", Quantity: " << item.quantity << ", Price: $" << item.price << endl;
        }
    }
};

int main() {
    Inventory inventory;
    int choice;
    string name;
    int quantity;
    double price;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Display Inventory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter quantity: ";
                cin >> quantity;
                cout << "Enter price: ";
                cin >> price;
                inventory.addItem(name, quantity, price);
                break;
            case 2:
                cout << "Enter item name to remove: ";
                cin >> name;
                inventory.removeItem(name);
                break;
            case 3:
                inventory.displayInventory();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}