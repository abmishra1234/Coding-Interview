/*
* Lambda function example
* 
* Capturing local variables
* The difference between the usage of lambda & normal functions boils down two two points
* 1. We can't overload lambda's
* 2. A lambda function can capture local variables
* 
* Let's understnd this by exampe in code
*/
using namespace std;
#include <iostream>
#include <functional>

#define FORREF
#ifndef FORREF

std::function<int(int)> makeLambda(int a) {
    return [a](int b) { return a + b; };
}

int main() {

    auto add5 = makeLambda(5);
    auto add10 = makeLambda(10);

    auto res = add5(10) == add10(5);
    cout << "both are same ? res = " << res << endl;
    
    return 0;
}
#endif // FORREF

