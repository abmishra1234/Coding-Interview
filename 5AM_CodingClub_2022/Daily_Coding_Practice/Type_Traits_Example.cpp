/*
The type traits library helps us optimize our code.
The type traits library enables you to check, compare and modify types at compile time
There are two reasons for using the type traits library:
Optimization and Correctness.

1. Optimization, because the introspection capabilities of the type traits library 
make it possible to choose the faster code automatically.
2. Correctness, because you can specify requirements for your code, which is checked at compile time.
The type traits library and static_assert are a powerful pair


*/

//#define FORREF

#ifndef FORREF
using namespace std;
#include<iostream>
#include<type_traits>

template <typename T> T fac(T a) {
	static_assert(std::is_integral<T> ::value, "T is not integeral");
}

int main()
{
	fac(10);
	fac(12.1);

	return 0;
}



#endif // FORREF

