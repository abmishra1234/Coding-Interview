using namespace std;
#include<iostream>
#include <utility>
#include <vector>

/*
	primary goal here is - how the std::move utility proves more efficient than copying.
	let's understand that what are the primary advantage of move semantics over copy sementics
	1. In copy sementics, it is possible that while copying your system went to out of memory state
	   but in move semantics this could not be the case, because in move sementics, no new memory required.
	   memory moved to new pointer
	2. What will happen with source, after move semantics. Source of the move operation is in a valid state but unspecified
	Let's learn using some example in code
*/
#define FORREF
#ifndef FORREF

int main()
{
	// Example using vector
	vector<int> myBigVec(10000000, 2022);
	std::vector<int> newVec;
	newVec = myBigVec; // copy sementics
	newVec = std::move(myBigVec); // move sementics

	// Example using string
	string str1 = "abcd";
	string str2 = "efgh";

	cout << "str1 = " << str1 << ", str2 = " << str2 << endl;
	str1 = str2; // copy sementics
	cout << "str1 = " << str1 << ", str2 = " << str2 << endl;

	str1 = "abcd";
	str2 = "efgh";

	cout << "str1 = " << str1 << ", str2 = " << str2 << endl;
	str2 = std::move(str1);
	cout << "str1 = " << str1 << ", str2 = " << str2 << endl;

	return 0;
}

#endif // FORREF

