using namespace std;
#include <iostream>

#define FORREF
#ifndef FORREF
class A {};
class B {};

class MyClass {
public:
    MyClass() {}
    explicit MyClass(A) {}                // since C++98
    explicit operator B() { return B(); }   // new with C++11
};

void needMyClass(MyClass) {};
void needB(B) {};

struct MyBool {
    explicit operator bool() { return true; }
    int operator +(int v) { return v; }
    friend int operator *(int v, MyBool b);
    friend int operator /(int v, MyBool b);
};

int operator *(int v, MyBool b)
{
    return v;
}

int operator /(int v, MyBool b)
{
    return v;
}

int main() {
    // A -> MyClass
    A a;

    // explicit invocation
    MyClass myClass1(a); // copy constructor invoked here

    // implicit conversion from A to MyClass
    MyClass myClass2 = MyClass(a);
    needMyClass(MyClass(a));

    // MyClass -> B
    MyClass myCl;

    // explicit invocation
    B b1(myCl);
    // implicit conversion from MyClass to B
    B b2 = B(myCl);
    needB(B(myCl));

    // MyBool -> bool conversion
    MyBool myBool;
    if (myBool) {};
    int myNumber = (myBool) ? 1998 : 2011;
    // implict conversion
    int myNewNumber = myBool + myNumber;
    auto myTen = (20 * myBool - 10 * myBool) / myBool;

    std::cout << myTen << std::endl;

}
#endif // FORREF

