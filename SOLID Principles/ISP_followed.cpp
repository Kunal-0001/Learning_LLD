#include<iostream>
using namespace std;
 
class TwoDShape {
    public:
        virtual void area() = 0;
};

class ThreeDShape : public TwoDShape {
    public:
        virtual void volume() = 0;
};

class Square : public TwoDShape {
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
};

class Rectangle : public TwoDShape {
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
};

class Cube : public ThreeDShape {
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
rectangle->area();
cube->area();
cube->volume();


return 0;
}