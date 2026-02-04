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

class ShoppingCartStorage {
private:
    ShoppingCart* cart;
public:
    ShoppingCartStorage(ShoppingCart* cart) {
        this->cart = cart;
    }

    void SavetoSql(){
        cout<<"Saving shopping cart to SQL Database"<<endl;
    }

    void SavetoFilesystem(){
        cout<<"Saving shopping cart to File System"<<endl;
    }  

    void SaveToCloud(){
        cout<<"Saving shopping cart to Cloud Storage"<<endl;
    }

    void savetoMongoDB(){
        cout<<"Saving shopping cart to MongoDB Database"<<endl;
    }

};




int main(){
ShoppingCart *cart = new ShoppingCart();
cart->AddProduct(new Product("Laptop", 1000));
cart->AddProduct(new Product("Phone", 500));

ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
printer->PrintInvoice();

ShoppingCartStorage *storage = new ShoppingCartStorage(cart);
storage->SavetoSql();
storage->SavetoFilesystem();
storage->SaveToCloud();
storage->savetoMongoDB();
return 0;
}