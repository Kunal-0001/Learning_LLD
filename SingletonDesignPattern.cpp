#include<iostream>
using namespace std;

class Singleton {
    private:
        static Singleton* Instance;

        Singleton(){    
            cout<<"Singleton constructor called"<<endl;
        }
    public:
        static Singleton* getInstance (){
            if(Instance==nullptr)
                Instance=new Singleton();
            return Instance;
        }
};

Singleton* Singleton::Instance = nullptr;

int main(){

    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout<<(s1==s2)<<endl;

return 0;
}