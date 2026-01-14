#include<iostream>
using namespace std;
 
class Car
{
protected:
    string Brand;
    string Model;
    int CurrentSpeed;
    bool IsEngineOn;
public:
    Car(string brand, string model){
        this->Brand = brand;
        this->Model = model;
        this->CurrentSpeed = 0;
        this->IsEngineOn = false;
    };
    void StartEngine(){
        IsEngineOn = true;
    }
    void StopEngine(){
        IsEngineOn = false;
    }
    virtual void Accelerate()=0;
    virtual void Brake()=0;

    virtual ~Car() {
        // Destructor implementation
    }
};

class ManualCar: public Car
{
    private:
        int currentGear;
    public:
    ManualCar(string brand, string model) : Car(brand, model) {
        this->currentGear = 0;
    }

    void Accelerate(){
        if (!IsEngineOn)
        {
            cout << "Engine is not started yet!" << endl;
            return;
        }
        CurrentSpeed += 10;
        cout << "Accelerating. Current speed: " << CurrentSpeed << endl;
    }
    void Brake(){
        if (!IsEngineOn)
        {
            cout << "Engine is not started yet!" << endl;
            return;
        }
        CurrentSpeed -= 10;
        cout << "Braking. Current speed: " << CurrentSpeed << endl;
    }

    void ShiftGear(int gear) {
        if (!IsEngineOn)
        {
            cout << "Engine is not started yet!" << endl;
            return;
        }
        currentGear = gear;
        cout << "Shifted to gear: " << currentGear << endl;
    }

};

class ElectricCar: public Car
{
    private:
        int BatteryLevel;
    public:
    ElectricCar(string brand, string model) : Car(brand, model) {
        this->BatteryLevel = 100;
    }

    void Accelerate(){
        if(BatteryLevel > 0)
        {
            CurrentSpeed += 15;
            BatteryLevel -= 5;
            cout << "Accelerating. Current speed: " << CurrentSpeed << endl;
        }
        else
        {
            cout << "Battery is empty. Please charge the car." << endl;
        }
    }
    void Brake(){
        if(BatteryLevel > 0)
        {
            CurrentSpeed -= 15;
            BatteryLevel += 5;
            cout << "Braking. Current speed: " << CurrentSpeed << endl;
        }
        else
        {
            cout << "Battery is empty. Please charge the car." << endl;
        }
    }

    void ChargeBattery(int amount) {
        BatteryLevel += amount;
        if (BatteryLevel > 100) BatteryLevel = 100;
        cout << "Battery charged. Current battery level: " << BatteryLevel << "%" << endl;
    }
};


int main(){
    Car* myCar1 = new ManualCar("Toyota", "Corolla");
    Car* myCar2 = new ElectricCar("Tesla", "Model S");

    myCar1->StartEngine();
    myCar1->Accelerate();
    myCar1->Brake();
    myCar1->StopEngine();

    myCar2->StartEngine();
    myCar2->Accelerate();
    myCar2->Brake();
    myCar2->StopEngine();

    delete myCar1;
    delete myCar2;

return 0;
}