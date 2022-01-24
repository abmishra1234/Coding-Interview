/*
Functional Programming
	With std::bind you can easily create new functions from existing ones.
	In order to bind them to a variable and invoke them later, you have std::function.

*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<functional>

double divMe(double a, double b)
{
	return (a / b);
}

int main()
{
	function<double(double, double)> mydiv1 = bind(divMe, placeholders::_1, placeholders::_2);
	function<double(double)> mydiv2 = bind(divMe, 2000, placeholders::_1);

	cout << "myDiv1 method, expecting return value 100 : " << mydiv1(2000, 20) << endl;
	cout << "myDiv2 method, expecting return value 100 : " << mydiv2(20) << endl;

}


#endif // FORREF
