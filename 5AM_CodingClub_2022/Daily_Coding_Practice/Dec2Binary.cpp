/*
    Challenge 3: Convert Decimal Number to Binary
*/

using namespace std;
#if 0
#include<iostream>

int main()
{
    int decimal = 5;
    int binary = 0;
    int rem = 0;
    int product = 1;
    do
    {
        rem = decimal % 2;
        binary += rem * product;
        decimal = decimal / 2;
        product *= 10;
    } while (decimal > 0);

    cout << "binary = " << binary << endl;
    return 0;
}

#endif // if 0