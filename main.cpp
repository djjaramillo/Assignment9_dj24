
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class GenericArray {
private:
    T* arr;
    int arraySize;

public:
    // Constructor
    GenericArray() {
        arr = nullptr;
        arraySize = 0;
    }

    // Destructor
    ~GenericArray() {
        delete[] arr;
    }

    // Add element to the end
    void addElement(T value) {
        T* newArray = new T[arraySize + 1];

        for (int i = 0; i < arraySize; i++) {
            newArray[i] = arr[i];
        }

        newArray[arraySize] = value;

        delete[] arr;
        arr = newArray;
        arraySize++;
    }

    // Return element at index
    T at(int index) const {
        if (index < 0 || index >= arraySize) {
            throw out_of_range("Invalid index");
        }
        return arr[index];
    }

    // Return array size
    int size() const {
        return arraySize;
    }

    // Return sum of elements
    T sum() const {
        T total = 0;

        for (int i = 0; i < arraySize; i++) {
            total += arr[i];
        }

        return total;
    }

    // Find maximum
    T max() const {
        if (arraySize == 0) {
            throw out_of_range("Array is empty");
        }

        T maximum = arr[0];

        for (int i = 1; i < arraySize; i++) {
            if (arr[i] > maximum) {
                maximum = arr[i];
            }
        }

        return maximum;
    }

    // Find minimum
    T min() const {
        if (arraySize == 0) {
            throw out_of_range("Array is empty");
        }

        T minimum = arr[0];

        for (int i = 1; i < arraySize; i++) {
            if (arr[i] < minimum) {
                minimum = arr[i];
            }
        }

        return minimum;
    }

    // Return a new sliced array
    // Uses inclusive indices: begin through end
    T* slice(int begin, int end) const {
        if (begin < 0 || end >= arraySize || begin > end) {
            throw out_of_range("Invalid slice bounds");
        }

        int sliceSize = end - begin + 1;
        T* slicedArray = new T[sliceSize];

        for (int i = 0; i < sliceSize; i++) {
            slicedArray[i] = arr[begin + i];
        }

        return slicedArray;
    }
};

int main() {
    GenericArray<int> int_array;

    // Add elements
    for (int i = 0; i < 15; i++) {
        int_array.addElement(i * 2);
    }

    cout << "Size of array is "
         << int_array.size() << endl;

    cout << "Sum of array is "
         << int_array.sum() << endl;

    cout << "Maximum and minimum of array is "
         << int_array.max() << "\t"
         << int_array.min() << endl;

    cout << "Element at index 3 is "
         << int_array.at(3) << endl;

    // Slice from index 5 to index 10
    int* sliced_array = int_array.slice(5, 10);

    cout << "Sliced array: ";

    for (int i = 0; i < 6; i++) {
        cout << sliced_array[i] << " ";
    }

    cout << endl;

    // Free memory used by sliced array
    delete[] sliced_array;

    return 0;
}
