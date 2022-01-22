#include <iostream>
using namespace std;

#define FORREF
#ifndef FORREF
// A simple Shape interface which provides a method to get the Shape's area
class Shape {
public:
    virtual float getArea() = 0;
};

// A Rectangle is a Shape with a specific width and height
class Rectangle : public Shape {   // derived form Shape class
private:
    float width;
    float height;

public:
    Rectangle(float wid, float heigh) {
        width = wid;
        height = heigh;
    }
    float getArea() {
        return width * height;
    }
};

// A Circle is a Shape with a specific radius
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float rad) {
        radius = rad;
    }
    float getArea() {
        return 3.14159f * radius * radius;
    }
};

// A Square is a Shape with a specific length
class Square : public Shape {
private:
    float length;

public:
    Square(float len) {
        length = len;
    }
    float getArea() {
        return length * length;
    }
};

int main() {
    Shape* shape[3];   // Referencing Shape class to Rectangle object
    //Shape * shape1 = new Shape(); //Instantiating the shape object

    Rectangle r(2, 6);    // Creating Rectangle object
    shape[0] = &r;   // Referencing Shape class to Rectangle object

    Circle c(5);    // Creating Circle object
    shape[1] = &c;   // Referencing Shape class to Circle object

    Square s(10);   // Creating Square object
    shape[2] = &s;     // Referencing Shape class to Circle object

    for (int i = 0; i < 3; i++)
        cout << shape[i]->getArea() << endl;
}

#endif // FORREF


