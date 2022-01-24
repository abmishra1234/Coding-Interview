/*
	In this slide we will showcase the composition relationship between the classes.
    - Suppose you have to build the Car
    - Car can be build with Engine, Tyre, Doors, and some more addition feature
*/
using namespace std;
#include<iostream>

#define FORREF
#ifndef FORREF
// Engine class 
class Engine {
    int capacity;

public:
    Engine() {
        capacity = 0;
    }

    Engine(int cap) {
        capacity = cap;
    }

    void Engine_details() {
        cout << "Engine details: " << capacity << endl;
    }
};

// Tyre Class
class Tyres {
    int No_of_tyres;

public:
    Tyres() {
        No_of_tyres = 0;
    }

    Tyres(int nt) {
        No_of_tyres = nt;
    }

    void Tyre_details() {
        cout << "Number of tyres: " << No_of_tyres << endl;
    }
};

// Door Class
class Doors {
    int No_of_doors;

public:
    Doors() {
        No_of_doors = 0;
    }

    Doors(int nod) {
        No_of_doors = nod;
    }

    void Door_details() {
        cout << "Number of Doors: " << No_of_doors << endl;
    }
};

// Car Class
class Car {
    Engine Eobj;
    Tyres Tobj;
    Doors Dobj;
    string color;

public:
    Car(Engine eng, Tyres tr, int dr, string col)
        : Eobj(eng), Tobj(tr), Dobj(dr) {

        color = col;
    }

    void Car_detail() {
        Eobj.Engine_details();
        Tobj.Tyre_details();
        Dobj.Door_details();
        cout << "Car color: " << color << endl;
    }
};

int main() {
    Engine Eobj(1600);
    Tyres Tobj(4);
    Doors Dobj(4);
    Car Cobj(Eobj, Tobj, 4, "Black");
    Cobj.Car_detail();
}

#endif // FORREF
