#include<iostream>
using namespace std;

class Car{
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
    public:
        Car(string b, string m){
            this->brand = b;
            this->model = m;
            this->isEngineOn = false;
            this->currentSpeed = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout<<"Engine Started"<<endl;
        }

        void accelerate(){
            if(!isEngineOn){
                cout<<"Unable to accelerate, as the Engine is off"<<endl;
                return;
            }
            currentSpeed += 20;
            cout<<"The speed has been accelerated to "<<currentSpeed<<endl;
        }

        void stopEngine(){
            isEngineOn = false;
            currentSpeed = 0;
            cout<<"Engine Stopped"<<endl;
        }

        void brake(){
            if(!isEngineOn){
                cout<<"Engine is already off"<<endl;
                return;
            }
            currentSpeed -= 20;
            cout<<"Brake has been applied, the current speed is "<<currentSpeed<<endl;
        }

        virtual ~Car(){
            cout<<"Car object destroyed"<<endl;
        }
};

class ManualCar : public Car {
    private:
        int CurrentGear;
    public:
        ManualCar(string b, string m) : Car(b, m) {
            CurrentGear = 0;
        }

        int getCurrentGear(){
            return CurrentGear;
        }

        int getCurrentSpeed(){
            return currentSpeed;
        }

        void ShiftGear(int gear){
            if(!isEngineOn){
                cout<<"Engine is already off, cant' shift gear"<<endl;
                return;
            }
            CurrentGear = gear;
            cout<<"Gear shifted to "<<CurrentGear<<endl;
        }
    };

class ElectricCar: public Car {
    private:
        int batteryLevel;
    public:
        ElectricCar(string b, string m) : Car(b, m) {
            batteryLevel = 100; // Battery level in percentage
        }

        void chargeBattery(int amount) {
            batteryLevel += amount;
            if(batteryLevel > 100) batteryLevel = 100;
            cout<<"Battery charged to "<<batteryLevel<<"%"<<endl;
        }

        int getBatteryLevel() {
            return batteryLevel;
        }
};

int main(){
    ManualCar* myManualCar = new ManualCar("Toyota", "Corolla");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->ShiftGear(2);
    myManualCar->brake();
    myManualCar->stopEngine();

    delete myManualCar;

    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->chargeBattery(20);
    myElectricCar->brake();
    myElectricCar->stopEngine();

    delete myElectricCar;

    return 0;
}