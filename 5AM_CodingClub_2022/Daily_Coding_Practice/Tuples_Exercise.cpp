/*
	Tuples
	Tuples extend the principles of a pair to a broader perspective. Find out more in this lesson.
	We'll cover the following
	std::make_tuple
*/
#define FORREF

#ifndef FORREF
using namespace std;
#include<iostream>
#include<tuple>
#include<string>


int main()
{
	// creating and initializing the tuple
	tuple<string/* name */, string/*contact*/, string/*email*/> tup1("Abinash Mishra", "(+91)9971003216", "abmishra1234@gmail.com");
	auto tup2 = make_tuple("Smita Mishra", "(+91)8076108051", "absmita.mishra@gmail.com");

	// now want to display the data from tuple
	cout << get<0>(tup1) << ", " << get<1>(tup1) << ", " << get<2>(tup1) << endl;

	// Now I want to update my emailid  into the tuple
	get<2>(tup1) = "abinash.km@samsung.com";

	cout << get<0>(tup1) << ", " << get<1>(tup1) << ", " << get<2>(tup1) << endl;

	// usage of comparator operator between the tuples
	cout << "reault of tup1 and tup2 compare : " << (tup1 < tup2) << endl;

	// I was saying earlier that tuple is big brother of pair
	auto pair1 = make_pair("Abinash Mishra", "SW Engineer");
	auto tup3 = pair1;

	cout << get<0>(tup3) << ", " << get<1>(tup3) << endl;



	return 0;
}

#endif // FORREF
