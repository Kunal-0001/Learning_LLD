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

class BasicWheatBurger : public Burger {
    public:
        void prepare() override {
            cout<<"Cooking Basic Wheat Burger with aloo tikki and some indian masala"<<endl;
        }
};

class StandardWheatBurger : public Burger {
    public:
        void prepare() override {
            cout<<"Cooking Standard Wheat Burger with korean tikki and some korean masala"<<endl;
        }
};

class PremiumWheatBurger : public Burger {
    public:
        void prepare() override {
            cout<<"Cooking Premium Wheat Burger with american tikki, paneer, onion, cucumber and some oregano, chilli flakes"<<endl;
        }
};

class BurgerFactory {
    public:
        virtual Burger* cookBurger(string type) = 0;
};

class SinghBurger: public BurgerFactory {
    Burger* cookBurger(string type) override {
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

class KingBurger: public BurgerFactory {
    Burger* cookBurger(string type) override {
            if(type == "basic")
                return new BasicWheatBurger();
            else if(type == "standard")
                return new StandardWheatBurger();
            else if(type == "premium")
                return new PremiumWheatBurger();
            else
                cout<<"Invalid Burger type!"<<endl;
                return nullptr;
        }
};

int main(){
    string BurgerType = "premium";
    BurgerFactory* myfactory = new KingBurger();

    Burger* myBurger = myfactory->cookBurger(BurgerType);
    myBurger->prepare();
return 0;
}