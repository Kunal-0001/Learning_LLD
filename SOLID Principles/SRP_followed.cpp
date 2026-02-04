#include<iostream>
using namespace std;
 
class Product {
    public:
        string name;
        float price;

        Product(string n, float p){
            this->name = n;
            this->price = p;
        }

};

class ShoppingCart {

    private:
        vector<Product*> products;
    public:
        void AddProduct(Product* product) {
            products.push_back(product);
        }

        const vector<Product*>& getProducts() const {
            return products;
        }

        double GetTotalPrice() {
            float total = 0;
            for (auto product : products) {
                total += product->price;
            }
            return total;
        }
};

class ShoppingCartPrinter {

private:
    ShoppingCart* cart;

public:
    ShoppingCartPrinter(ShoppingCart* cart) {
        this->cart = cart;
    }

    void PrintInvoice() {
        cout<<"Shopping cart invoice:"<<endl;
        for(auto p : cart->getProducts()) {
            cout << "Product Name: " << p->name << ", Price: " << p->price << endl;
        }
        cout<<"Total Price: "<<cart->GetTotalPrice()<<endl;
    }
};

class ShoppingCartStore {
private:
    ShoppingCart* cart;
public:
    ShoppingCartStore(ShoppingCart* cart) {
        this->cart = cart;
    }

    void SaveToDB() {
        // Code to save the shopping cart details to a database
        cout << "Shopping cart details saved to database." << endl;
    }

};


int main(){

    ShoppingCart* cart = new ShoppingCart();

    cart->AddProduct(new Product("Laptop", 999.99));
    cart->AddProduct(new Product("Monitor", 499.99));

    ShoppingCartPrinter printer(cart);
    printer.PrintInvoice();

    ShoppingCartStore store(cart);
    store.SaveToDB();

return 0;
}