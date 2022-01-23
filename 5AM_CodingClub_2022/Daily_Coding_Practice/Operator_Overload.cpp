using namespace std;
#include<iostream>
/*
	C++ allows us to define the behavior of operators for our own data types. This is known as operator overloading.
	Operators vary in nature and therefore, require different operands. 
	The number of operands for a particular operator depends on:
	- the kind of operator (infix, prefix, etc.)
	- whether the operator is a method or function.
	In perator overloading, there are rules and while doing your custom operator overloading also you have to take care of
	these rules. #Rules are 
	Here are some of the important rules 
	1. We can't change the precedence of the operator
	2. Derived classes inheirt all the operator of their base classes except the assignment operator
	3. All operator other than the function call operator cannot have default argument
	4. operator can be called explicitely
*/

#define FORREF
#ifndef FORREF

#include <iostream>

class Account {

public:
	explicit Account(double b) : balance(b) {}

	Account& operator += (double b) {
		balance += b;
		return *this;
	}

	friend Account& operator += (Account& a, Account& b);
	friend std::ostream& operator << (std::ostream& os, const Account& a);

private:
	double balance;

};

Account& operator += (Account& a, Account& b) {
	a.balance += b.balance;
	return a;
}

std::ostream& operator << (std::ostream& os, const Account& a) {
	os << a.balance;
	return os;
}

int main() {

	std::cout << std::endl;

	Account acc1(100.0);
	Account acc2(100.0);
	Account acc3(100.0);

	acc1 += 50.0;
	acc1 += acc1;

	acc2 += 50.0;
	acc2 += acc2;

	acc3.operator += (50.0);
	//acc3.operator += (acc3);   ERROR

	std::cout << "acc1: " << acc1 << std::endl;
	std::cout << "acc2: " << acc2 << std::endl;

	std::cout << std::endl;

}
#endif // FORREF