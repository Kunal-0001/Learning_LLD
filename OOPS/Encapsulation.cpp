#include<iostream>
using namespace std;

class sportsCar
{
private:
    string Brand;
    string model;
    bool isEngineOn;
    int CurrentSpeed;
    int CurrenGear;
    string TyreCompany;

public:
    sportsCar(string b, string m){
        this->Brand = b;
        this->model = m;
        CurrentSpeed = 0;
        CurrenGear = 0;
        TyreCompany = "MRF";
        isEngineOn = false;
    }

    int getCurrentSpeed(){
        return CurrentSpeed;
    }

    int getCurrentGear(){
        if(!isEngineOn){
            cout<<"Unable to get gear, as the Engine is off"<<endl;
            return -1;
        }
        return CurrenGear;
    }

    string getTyreCompany(){
        return TyreCompany;
    }

    void setCurrentGear(int gear){
        CurrenGear = gear;
    }

    void setCurrentSpeed(int speed){
        CurrentSpeed = speed;
    }

    void setTyreCompany(string company){
        TyreCompany = company;
    }

    void startEngine(){
        isEngineOn = true;
        cout<<Brand<<" "<<model<<" "<<": Engine started with a Roar!"<<endl;
    }

    void stopEngine(){
        isEngineOn = false;
        cout<<Brand<<" "<<model<<" "<<": Engine stopped."<<endl;
    }

    void accelerate(int increment){
        if(!isEngineOn){
            cout<<"Unable to accelerate, as the Engine is off"<<endl;
            return;
        }
        CurrentSpeed += increment;
        cout<<Brand<<" "<<model<<" "<<": Accelerating. Current Speed: "<<CurrentSpeed<<endl;
    }

    void brake(int decrement){
        if(!isEngineOn){
            cout<<"Unable to brake, as the Engine is off"<<endl;
            return;
        }
        CurrentSpeed -= decrement;
        if(CurrentSpeed < 0) CurrentSpeed = 0;
        cout<<Brand<<" "<<model<<" "<<": Braking. Current Speed: "<<CurrentSpeed<<endl;
    }

    ~sportsCar(){
        cout<<Brand<<" "<<model<<" "<<": Destructor called, resources released."<<endl;
    }
};


 
int main(){
    sportsCar* myCar = new sportsCar("Ferrari", "488 Spider");
    myCar->startEngine();
    myCar->accelerate(30);
    myCar->setCurrentGear(2);
    myCar->getCurrentSpeed();
    myCar->getCurrentGear();
    myCar->getTyreCompany();
    myCar->brake(10);
    myCar->stopEngine();

return 0;
}