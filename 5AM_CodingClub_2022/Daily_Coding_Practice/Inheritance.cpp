#include <iostream>
#include <string>
using namespace std;

// Write classes code here
// Base class
class Animal {
private:
	string name;
	string sound;
public:
	Animal()
	{
		name = "";
		sound = "";
	}
	Animal(string n, string s) : name(s), sound(s) {}

	void Animal_Details()
	{
		cout << "Name = " << name << endl;
		cout << "sound = " << sound << endl;
	}
};

class Dog : public Animal
{
private:
	string family;
public:
	Dog(string n, string s, string f) : Animal(n, s), family(f) {}
	void Dog_detail()
	{
		Animal_Details();
		cout << "family = " << family << endl;

	}
};

class Sheep : public Animal
{
private:
	string color;
public:
	Sheep(string n, string s, string c) : Animal(n, s), color(c) {}

	void Dog_detail()
	{
		Animal_Details();
		cout << "color = " << color << endl;

	}
};




int main() {
	// Make classes objects here
}