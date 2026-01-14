#include<iostream>
using namespace std;
 
class Car {
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int CurrentSpeed;
    public:
        Car(string brand, string model) {
            this->brand = brand;
            this->model = model;
            this->isEngineOn = false;
            this->CurrentSpeed = 0;
        }

        void StartEngine() {
            isEngineOn = true;
            cout << "Engine started." << endl;
        }

        void StopEngine() {
            isEngineOn = false;
            cout << "Engine stopped." << endl;
        }

        virtual void Accelerate(int increment) = 0;
        virtual void Accelerate() = 0;
        virtual void Brake() = 0;

        virtual ~Car() {}
};

class ManualCar : public Car {

    private:
        int currentGear;

    public:
        ManualCar(string brand, string model) : Car(brand, model) {
            this->currentGear = 1;
        }

        void Accelerate(int increment) override {
            if (isEngineOn) {
                CurrentSpeed += increment;
                cout << "ManualCar accelerating. Current speed: " << CurrentSpeed << endl;
            } else {
                cout << "ManualCar engine is not started yet!" << endl;
            }
        }

        void Accelerate() override {
            if (isEngineOn) {
                CurrentSpeed += 5;
                cout << "ManualCar accelerating. Current speed: " << CurrentSpeed << endl;
            } else {
                cout << "ManualCar engine is not started yet!" << endl;
            }
        }

        void Brake() override {
            if (isEngineOn) {
                CurrentSpeed -= 5;
                cout << "ManualCar braking. Current speed: " << CurrentSpeed << endl;
            } else {
                cout << "ManualCar engine is not started yet!" << endl;
            }
        }
};

class ElectricCar: public Car {
    private:
        int batteryLevel;

    public:
        ElectricCar(string brand, string model) : Car(brand, model) {
            this->batteryLevel = 100;
        }

        void Accelerate(int increment) override {
            if (isEngineOn && batteryLevel > 0) {
                CurrentSpeed += increment;
                batteryLevel -= increment / 10;
                cout << "ElectricCar accelerating. Current speed: " << CurrentSpeed << ", Battery level: " << batteryLevel << "%" << endl;
            } else {
                cout << "ElectricCar engine is not started or battery is low!" << endl;
            }
        }

        void Accelerate() override {
            if (isEngineOn && batteryLevel > 0) {
                CurrentSpeed += 10;
                batteryLevel -= 1;
                cout << "ElectricCar accelerating. Current speed: " << CurrentSpeed << ", Battery level: " << batteryLevel << "%" << endl;
            } else {
                cout << "ElectricCar engine is not started or battery is low!" << endl;
            }
        }

        void Brake() override {
            if (isEngineOn) {
                CurrentSpeed -= 10;
                cout << "ElectricCar braking. Current speed: " << CurrentSpeed << endl;
            } else {
                cout << "ElectricCar engine is not started yet!" << endl;
            }
        }
};

int main() {
    Car* myManualCar = new ManualCar("Toyota", "Corolla");
    myManualCar->StartEngine();
    myManualCar->Accelerate(20);
    myManualCar->Brake();

    Car* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->StartEngine();
    myElectricCar->Accelerate(30);
    myElectricCar->Brake();

    delete myManualCar;
    delete myElectricCar;

return 0;
}