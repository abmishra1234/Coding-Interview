/*
	Functors : Functors are very similar to lambda functions.
	We can say that lambdas actually create anonymous functors.

	functors are used frequently in STL algorithms as arguments.
	These functors can then be applied to the data being passed to the STL functions.

	std::add, std::transform, and std::reduce are just a few of the functions that can use functors and apply them to data.

	1. A functor that takes a single argument is a unary functor.
	2. A functor that takes two arguments is a binary functor.
*/
#include <algorithm>
#include <iostream>
#include <vector>

#define FORREF
#ifndef FORREF
class SumMe {
public:

	SumMe() : sum(0) {};

	void operator()(int x) {
		sum += x;
	}

	int getSum() const {
		return sum;
	}
private:
	int sum;
};

int main() {

	std::cout << std::endl;

	std::vector<int> intVec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// Use a lambda function here and class sumMe is no longer needed
	SumMe sumMe = std::for_each(intVec.begin(), intVec.end(), SumMe());
	std::cout << "sumMe.getSum(): " << sumMe.getSum() << std::endl;

	std::cout << std::endl;

}
#endif // FORREF

