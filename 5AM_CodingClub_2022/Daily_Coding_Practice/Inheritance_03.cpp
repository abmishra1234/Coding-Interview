#include <iostream>
#include <assert.h>
#include <limits.h>
using namespace std;

#define FORREF

#ifndef FORREF

class DynamicArray {
    int* array;
    int capacity = 2;
    int size;

public:
    DynamicArray() {
        array = new int[capacity];
        size = 0;
        max = INT_MIN;
        min = INT_MAX;
        sum = 0;
    }

    void append(int element) {
        insertAt(element, size);
    }

    int length() {
        return size;
    }

    int get(int pos) {
        return array[pos];
    }

    ~DynamicArray() {
        delete[] array;
    }
    /*
        int max(): Returns the maximum element in the dynamic array.
        int min(): Returns the minimum element present in the dynamic array.
        int mean(): Finds the mean value from the elements in the array and returns it.
    */
    // Three additional api need to be implemeneted here




private:
    void insertAt(int element, int pos) {
        assert(0 <= pos && pos <= size);
        if (size == capacity) {
            resize();
        }
        for (int i = size; i > pos; i--) {
            array[i] = array[i - 1];
        }
        size++;
        array[pos] = element;
        if (element > max)
        {
            max = element;
        }

        if (element < min)
        {
            min = element;
        }

        sum += element;

    }

    void resize() {
        capacity *= 2;
        int* temp = new int[capacity];
        copy(array, array + size, temp);
        delete[] array;
        array = temp;
    }

    // putting three additional member variable to handle the max, min, mean in the given dynamic array
    int max, min, sum;

public:
    int getMax()
    {
        return max;
    }

    int getMin()
    {
        return min;
    }

    int getMean()
    {
        return sum / size;
    }
};

int main() {


    DynamicArray arr = DynamicArray();
    arr.append(2);
    arr.append(6);
    arr.append(4);
    arr.append(1);
    arr.append(3);

    cout << "Array: ";
    for (int i = 0; i < arr.length(); i++) {
        cout << arr.get(i) << " ";
    }
    cout << endl;

    cout << "Max = " << arr.getMax() << endl;
    cout << "Min = " << arr.getMin() << endl;
    cout << "Mean = " << arr.getMean() << endl;

    return 0;
}

#endif // FORREF

