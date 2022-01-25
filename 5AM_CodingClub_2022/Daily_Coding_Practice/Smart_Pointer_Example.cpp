/*
	Smart pointers.
	Importance of smart pointer because it is giving you interface to handle memory menagement efficiently.
	one of the common and sloppy mistake usually developer is doing in c++, is memory leaks. This leaks eventually 
	acuumulating and your service or application reached the state where no memory is available for your service.
	
	Earlier we have std::auto_ptr, which is deprecated now.
	We will learn in this example about std::unique_ptr, std::shared_ptr, std::weak_ptr

	The smart pointers manage their resource according to the RAII idiom.
	So the resource is automatically released if the smart pointer goes out of scope.

	This means for the smart pointer that the memory is allocated in the constructor and deallocated in the destructor.

	std::auto_ptr	C++98	Ownes exclusively the resource, and move while copying
	std::unique_ptr C++11	Ownes exclusively the resource. can't be copied
	std::shared_ptr c++11	Has a reference counter for the shared variable.Deletes the resource, if the reference counter is 0.
	std::weak_ptr	C++11	Helps to break cycles of std::shared_ptr. Doesn’t modify the reference counter.
*/

using namespace std;

#include <iostream>
#include <memory>

//#define FORREF

#ifndef FORREF
//============================
struct MyInt
{
private:
	int i_;
public:
	MyInt(int i) : i_(i) {}
	~MyInt() {
		cout << "Good Bye from " << i_ << endl;
	}
};
//============================
struct MyStruct
{
private:
	int val;
	static int count;

public:
	MyStruct() : val(count) {
		cout << static_cast<void*>(this) << "Hello from " << val << endl;
		++count;
	}

	~MyStruct() {
		cout << static_cast<void*>(this) << "Good Bye " << val << endl;
		--count;
	}
};

int MyStruct::count = 0;

//============================

int main() {
	/*demonstarting the auto_ptr*/
	std::auto_ptr<int> ap1(new int(2011));
	std::auto_ptr<int> ap2 = ap1; // OK

	/*demonstrating the unique_ptr*/

	std::unique_ptr<int> up1(new int(2011));
	//std::unique_ptr<int> up2 = up1;            // ERROR
	std::unique_ptr<int> up3 = std::move(up1); // OK

	/*
		These are the methods of std::unique_ptr:
		get	- Returns a pointer to the resource.
		get_deleter	- Returns the delete function.
		release	- Returns a pointer to the resource and releases it.
		reset - Resets the resource.
		swap - Swaps the resources.
	*/
	unique_ptr<MyInt> uniquePtr1{ new MyInt(1998) };
	cout << uniquePtr1.get() << endl;

	unique_ptr<MyInt> uniquePtr2 = std::move(uniquePtr1);
	cout << uniquePtr1.get() << endl;
	cout << uniquePtr2.get() << endl;

	{
		unique_ptr<MyInt> localPtr{ new MyInt(2003) };
	}

	uniquePtr2.reset(new MyInt(2011));
	MyInt* delPtr = uniquePtr2.release();
	delete delPtr;

	unique_ptr<MyInt> uniquePtr3{ new MyInt(2017) };
	unique_ptr<MyInt> uniquePtr4{ new MyInt(2022) };

	cout << uniquePtr3.get() << endl;
	cout << uniquePtr4.get() << endl;
	swap(uniquePtr3, uniquePtr4);
	cout << uniquePtr3.get() << endl;
	cout << uniquePtr4.get() << endl;

	// std::unique_ptr has a specialisation for arrays:
	{
		unique_ptr<MyStruct[]>myUniqueArray(new MyStruct[3]);
	}
	return 0;
}
#endif // FORREF

