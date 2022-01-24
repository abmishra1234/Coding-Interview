using namespace std;
#include<iostream>
#include<algorithm>
/*
	This family of functions allows us to find the minimum and maximum in a set of data.
*/
#define FORREF

#ifndef FORREF

int main()
{
	cout << "std::min usage for finding the min value from 2011, 2014 : " << std::min(2011, 2014) << std::endl;
	cout << "std::min usage for finding the min value from {12, 3,-4, 5,78, -9} : " << std::min({ 12, 3,-4, 5,78, -9 }) << std::endl;

	// next task is to check , the min and max value from the set of the data
	pair<int, int> res = std::minmax({ 12, 3,-4, 5,78, -9 });
	cout << "min = " << res.first << ",  max = " << res.second << endl;

	return 0;
}
#endif // FORREF

