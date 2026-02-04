#include<iostream>
using namespace std;
 
class Shape {
public:
    virtual void area() = 0;
    virtual void volume() = 0;
};

class Square : public Shape {
    private:
        int side;
    public:
        Square(int side){
            this->side=side;
        }

        void area() override {
            int area = side*side;
            cout<<"Area of square is "<<area<<endl;
        }

        void volume() override {
            throw logic_error("Volume not applicable for square");
        }
};

class Rectangle: public Shape {
    private:
        int length;
        int width;
    public:
        Rectangle(int length, int width){
            this->length = length;
            this->width = width;
        }

        void area() override {
            int area = length * width;
            cout<<"Area of rectangle is "<<area<<endl;
        }

        void volume() override {
            throw logic_error("Volume not applicable for rectangle");
        }
};

class Cube : public Shape
{
private:
    int side;
public:
    Cube(int side){
        this->side = side;
    };

    void area() override {
        int area = 6 * side * side;
        cout<<"Area of cube is "<<area<<endl;
    }

    void volume() override {
        int volume = side*side*side;
        cout<<"Volume of cube is "<<volume<<endl;
    }
};


int main(){
Square* square = new Square(5);
Rectangle* rectangle = new Rectangle(4,5);
Cube* cube = new Cube(5);

square->area();
try
{
    square->volume();
}
catch(const logic_error& e)
{
    cout << e.what() << endl;
}


rectangle->area();
try
{
    rectangle->volume();
}
catch(const logic_error& e)
{
    cout << e.what() << endl;
}


cube->area();
cube->volume();
return 0;
}