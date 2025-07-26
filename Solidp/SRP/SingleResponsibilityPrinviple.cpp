/*This means that a class should do only one thing and be responsible for only one part of the functionality provided by the software.
When a class has multiple responsibilities:

It becomes hard to test.

It becomes fragile — a change in one responsibility can unintentionally break another.

It becomes hard to maintain and understand.
thus divide that single class into multiple classes to follow this SRP nicely */

#include <iostream>
#include <vector>

using namespace std;

// Product class representing any item of any ECommerce.
class Product {
public:
    string name;
    double price;
 
    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

// Violating SRP: ShoppingCart is handling multiple responsibilities
class ShoppingCart {
private:
    vector<Product*> products; 

public:
    void addProduct(Product* p) { 
        products.push_back(p);
    }

    const vector<Product*>& getProducts() { 
        return products;
    } 

    // 1. Calculates total price in cart.
    double calculateTotal() {
        double total = 0;
        for (auto p : products) {
            total += p->price;
        }
        return total;
    }

    // 2. Violating SRP - Prints invoice (Should be in a separate class)
    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : products) {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << calculateTotal() << endl;
    }

    // 3. Violating SRP - Saves to DB (Should be in a separate class)
    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    cart->printInvoice();  
    cart->saveToDatabase();

    return 0;
}

// Note: In a well-designed system, the ShoppingCart class would only handle product management,
// while invoice printing and database operations would be handled by separate classes, adhering to the Single Responsibility Principle (SRP).


