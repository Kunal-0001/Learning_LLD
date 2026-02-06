#include<iostream>
using namespace std;

class Burger {
    public:
        virtual void prepare() = 0;
};

class BasicBurger : public Burger {
    public:
        void prepare() override {
            cout<<"Cooking Basic Burger with aloo tikki and some indian masala"<<endl;
        }
};

class StandardBurger : public Burger {
    public:
        void prepare() override {
            cout<<"Cooking Standard Burger with korean tikki and some korean masala"<<endl;
        }
};

class PremiumBurger : public Burger {
    public:
        void prepare() override {
            cout<<"Cooking Premium Burger with american tikki, paneer, onion, cucumber and some oregano, chilli flakes"<<endl;
        }
};

class BurgerFactory {
    public:
        Burger* cookBurger(string type){
            if(type == "basic")
                return new BasicBurger();
            else if(type == "standard")
                return new StandardBurger();
            else if(type == "premium")
                return new PremiumBurger();
            else
                cout<<"Invalid Burger type!"<<endl;
                return nullptr;
        }
};

int main(){
    string BurgerType = "basic";
    BurgerFactory* myfactory = new BurgerFactory();

    Burger* myBurger = myfactory->cookBurger(BurgerType);
    myBurger->prepare();
return 0;
}