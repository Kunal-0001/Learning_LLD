// We are revising abstraction and doing some hands-on

#include <iostream>
using namespace std;

class Car{
  public:
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void shiftGear( int gear ) = 0;
    virtual ~Car() {}
};

class sportsCar : public Car{
  public:
    string brand;
    string model;
    int currentSpeed;
    int currentGear;
    bool isEngineOn;
    
    sportsCar(string b, string m){
      this->brand = b;
      this->model = m;
      currentSpeed = 0;
      currentGear = 0;
      isEngineOn = false;
    }
    
    void startEngine(){
      isEngineOn = true;
      cout<<brand<<" "<<model<<" "<<": Engine started with a Roar!"<<endl;
    }
    
    void stopEngine(){
      isEngineOn = false;
      currentGear = 0;
      currentSpeed = 0;
      cout<<"Enginse has been turned off"<<endl;
    }
    
    void accelerate(){
      if(!isEngineOn){
        cout<<"Unable to accelerate, as the Engine is off"<<endl;
        return;
      }
      currentSpeed += 20;
      cout<<"The speed has been accelerated to "<<currentSpeed<<endl;
    }
    
    void brake(){
      if(!isEngineOn){
        cout<<"Engine is already off"<<endl;
        return;
      }
      currentSpeed-=20;
      cout<<"Brake has been applied, the current speed is "<<currentSpeed<<endl;
    }
    
    void shiftGear(int gear){
      if(!isEngineOn){
        cout<<"Engine is already off, cant' shift gear"<<endl;
        return;
      }
      
      currentGear = gear;
      cout<<"The gear has been shifted to "<<gear<<endl;
    }
};

int main() 
{
    Car *myCar = new sportsCar("lamborghini", "hurricane");
    myCar->startEngine();
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->brake();
    myCar->stopEngine();
    
    delete myCar;
    
    return 0;
    
}