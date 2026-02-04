#include<iostream>
using namespace std;
 
class Product {
    public:
        string name;
        float price;

        Product(string n, float p) {
            name = n;
            price = p;
        }
};

class ShoppingCart {
    private:
        vector<Product*> products;

    public:
        void AddProduct(Product* product) {
            products.push_back(product);
        }

        const vector<Product*>& getProducts() {
            return products;
        }

        float CalculateTotal() {
            float total = 0;
            for (auto& product : products) {
                total += product->price;
            }
            return total;
        }

        float GetTotalPrice() {
            return CalculateTotal();
        }

        void PrintInvoice() {
            cout << "Invoice:" << endl;
            for (const auto& product : products) {
                cout << " - " << product->name << ": $" << product->price << endl;
            }
            cout << "Total: $" << GetTotalPrice() << endl;
        }

        void SaveToDB() {
            // Code to save the shopping cart details to a database
            cout << "Shopping cart details saved to database." << endl;
        }

};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->AddProduct(new Product("Laptop", 999.99));
    cart->AddProduct(new Product("Mouse", 25.50));
    cart->AddProduct(new Product("Keyboard", 75.00));

    cart->PrintInvoice();
    cart->SaveToDB();

    // Clean up
    delete cart;
return 0;
}