/* We have already declared the input variable number at the backend.
int number;
Find whether the given number is palindrome or not, and then
print your output to the console
*/
// Write your code here

#if 0
using namespace std;
#include<iostream>




void IsPalindrome(int number)
{
	int backup = number;
	bool result = false;

	int sum = 0;

	while (number > 0)
	{
		sum = sum * 10 + (number % 10);
		number /= 10;
	}
	
	if (backup == sum)
		cout << "is palindrome";
	else
		cout << "not a palindrome";

}



int main()
{
	//I am expecting here an input of number
	IsPalindrome(2002);
	cout << endl;
	IsPalindrome(3112123);
	cout << endl;
	IsPalindrome(899998);
	cout << endl;
	IsPalindrome(12345);

	return 0;
}


#endif

