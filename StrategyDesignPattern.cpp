#include<iostream>
using namespace std;
 
class Talkable {
    public:
        virtual void talk() = 0;
};

class Talk : public Talkable {
    public:
        void talk() override {
            cout<<"This robot can talk"<<endl;
        }
};

class NoTalk : public Talkable {
    public: 
        void talk() override {
            cout<<"This robot can not talk"<<endl;
        }
};

class Flyable {
    public:
        virtual void fly() = 0;
};

class Fly : public Flyable {
    public:
        void fly() override {
            cout<<"This robot can fly"<<endl;
        }
};

class NoFly : public Flyable {
    public:
        void fly() override {
            cout<<"This robot cannot fly"<<endl;
        }
};

class Walkable {
    public:
        virtual void walk() = 0;
};

class Walk : public Walkable {
    public:
        void walk() override {
            cout<<"This robot can walk"<<endl;
        }
};

class NoWalk : public Walkable {
    public:
        void walk() override {
            cout<<"This robot cannot walk"<<endl;
        }
};

class Robot {
    private:
        Walkable* walkBehaviour;
        Talkable* talkBehaviour;
        Flyable* FlyBehaviour;
    public:
        Robot(Walkable* walk, Talkable* talk, Flyable* fly){
            this->walkBehaviour=walk;
            this->talkBehaviour=talk;
            this->FlyBehaviour=fly;
        }

        void walk(){
            walkBehaviour->walk();
        }

        void talk(){
            talkBehaviour->talk();
        }

        void fly(){
            FlyBehaviour->fly();
        }

        virtual void projection() = 0;
};

class CompanionRobot: public Robot {
    public:
        CompanionRobot(Walkable* w, Talkable* t, Flyable* f) : Robot(w,t,f) {}

        void projection() override {
            cout<<"This is a companion Robot...";
        }
};

class WorkerRobot : public Robot {
    public:
        WorkerRobot(Walkable* w, Talkable* t, Flyable* f) : Robot(w,t,f) {}

        void projection() override {
            cout<<"This is a worker Robot...";
        }
};

int main(){

Robot* companion = new CompanionRobot(new Walk(), new Talk(), new NoFly());
companion->projection();
companion->walk();
companion->talk();
companion->fly();

Robot* worker = new WorkerRobot(new Walk(), new Talk(), new Fly());
worker->projection();
worker->walk();
worker->talk();
worker->fly();

return 0;
}