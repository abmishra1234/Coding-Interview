/*
	C++ takes reference functionality one step higher by introducing reference wrappers!
	std::reference_wrapper objects supports two additional usecases
	1. You can use them in containers of the Standard Template Library.
	std::vector<std::reference_wrapper<int>> myIntRefVector
	2. You can copy instances of classes, which have std::reference_wrapper objects. That is in general not possible with references.
*/
#define FORREF

#ifndef FORREF
using namespace std;
#include<iostream>
#include<functional>

// normal method 
void foo() {
	std::cout << "Invoked" << std::endl;
}

int main() {
	typedef void callableUnit();
	std::reference_wrapper<callableUnit> refWrap(foo);

	refWrap(); // Invoked
	return 0;
}
#endif // !FORREF

