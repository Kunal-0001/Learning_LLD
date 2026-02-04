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

class DBPersistence {
    private:
        ShoppingCart* cart;
    public:
        virtual void SaveToDatabase(ShoppingCart* cart) = 0;
};

class MongoDBPersistence: public DBPersistence {
    public:

        void SaveToDatabase(ShoppingCart* cart) override {
            cout<<"Saving data to mongoDB"<<endl;
        }
};

class SQLPersistence: public DBPersistence {
    public:
        void SaveToDatabase(ShoppingCart* cart) override{
            cout<<"Saving data to sql database"<<endl;
        }
};

class CloudPersistence: public DBPersistence {
    public:
        void SaveToDatabase(ShoppingCart* cart) override{
            cout<<"Saving data to cloud"<<endl;
        }
};

class FilePersistence: public DBPersistence {
    public:
        void SaveToDatabase(ShoppingCart* cart) override{
            cout<<"Saving data to file systemts"<<endl;
        }
};


int main(){

ShoppingCart* cart = new ShoppingCart();
cart->AddProduct(new Product("Laptop",999));
cart->AddProduct(new Product("Monitor",199));

ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
printer->PrintInvoice();

DBPersistence* mongo = new MongoDBPersistence();
DBPersistence* sql = new SQLPersistence();
DBPersistence* cloud = new CloudPersistence();
DBPersistence* file = new FilePersistence();

mongo->SaveToDatabase(cart);
sql->SaveToDatabase(cart);
cloud->SaveToDatabase(cart);
file->SaveToDatabase(cart);




return 0;
}