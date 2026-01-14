#include<iostream>
using namespace std;

class Car{
    public:
        string Brand;
        string Model;
        int CurrentSpeed;
        int CurrentGear;
        bool IsEngineOn;

        Car(string brand, string model){
            this->Brand = brand;
            this->Model = model;
            CurrentSpeed = 0;
            CurrentGear = 0;
            IsEngineOn = false;
        }

        void StartEngine(){
            IsEngineOn = true;
            cout << "Engine started" << endl;
        }

        void StopEngine(){
            IsEngineOn = false;
            cout << "Engine stopped" << endl;
        }

        void Accelerate(int increment){
            if(IsEngineOn){
                CurrentSpeed += increment;
                cout << "Accelerating. Current speed: " << CurrentSpeed << " km/h" << endl;
            }
            else{
                cout << "Start the engine first!" << endl;
            }
        }

        void Accelerate(){
            if(IsEngineOn){
                CurrentSpeed += 10;
                cout << "Accelerating. Current speed: " << CurrentSpeed << " km/h" << endl;
            }
            else{
                cout << "Start the engine first!" << endl;
            }
        }

        void Brake(int decrement){
            if(IsEngineOn){
                CurrentSpeed -= decrement;
                if(CurrentSpeed < 0) CurrentSpeed = 0;
                cout << "Braking. Current speed: " << CurrentSpeed << " km/h" << endl;
            }
            else{
                cout << "Start the engine first!" << endl;
            }
        }
};

int main(){
    Car myCar("Toyota", "Corolla");
    myCar.StartEngine();
    myCar.Accelerate();
    myCar.Accelerate(20);
    myCar.Brake(5);
    myCar.StopEngine();

return 0;
}