using namespace std;
#include<iostream>
/*
	C++ allows us to define the behavior of operators for our own data types. This is known as operator overloading.
	Operators vary in nature and therefore, require different operands. 
	The number of operands for a particular operator depends on:
	- the kind of operator (infix, prefix, etc.)
	- whether the operator is a method or function.
*/

//#define FORREF
#ifndef FORREF

class A
{
private:
	float balance;
protected:
public:
	A() = default;
	A(float init_bal) : balance(init_bal) {}
	// += operator should be overloaded for the current my custom class
	A& operator += (float amount)
	{
		balance += amount;
		return *this;
	}
	void printBalance()
	{
		cout << "balance = " << balance << endl;
	}
};



int main()
{
	A a(1000);
	a += 100;
	a.printBalance(); // output should be 1100
	return 0;
}
#endif // FORREF