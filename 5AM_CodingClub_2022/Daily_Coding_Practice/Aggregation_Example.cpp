/*
	Aggregation
	- new way of linking different classes.
	- In aggregation, the lifetime of the owned object does not depend on the lifetime of the owner.


*/

#define FORREF
#ifndef FORREF

#include <iostream>
#include <string>
using namespace std;

class Country {
    string name;
    int population;

public:
    Country(string n, int p) {
        name = n;
        population = p;
    }
    string getName() {
        return name;
    }
};

class Person {
    string name;
    Country* country; // A pointer to a Country object

public:
    Person(string n, Country* c) {
        name = n;
        country = c;
    }

    void printDetails() {
        cout << "Name: " << name << endl;
        cout << "Country: " << country->getName() << endl;
    }
    ~Person()
    {
        cout << "Person class Destructor Called!!!" << endl;

    }
};

int main() {
    Country* country = new Country("Utopia", 1);
    {
        Person user("Darth Vader", country);
        user.printDetails();
    }
    // The user object's lifetime is over

    cout << country->getName() << endl; // The country object still exists!
}

#endif // FORREF