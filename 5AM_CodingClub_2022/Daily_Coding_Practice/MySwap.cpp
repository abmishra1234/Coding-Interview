using namespace std;
#include<iostream>
#include <utility>

#define FORREF
#ifndef FORREF
template <typename T>
inline void myswap(T& a, T& b) {
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	int f = 10;
	int s = 25;

	int* fp = &f;
	int* sp = &s;

	cout << *fp << ", " << *sp << endl;
	myswap<int*>(fp, sp);
	cout << *fp << ", " << *sp << endl;

	return 0;
}

#endif // FORREF

