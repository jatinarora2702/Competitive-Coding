#include <iostream>
#include <memory>
#include <array> // for array stl only

using namespace std;

int main() {
    // static array init (explicit size given)
    int arr1[5] = {1, 2, 3, 4, 5};

    // static array init (size can be omitted, if all values given)
    int arr2[] = {1, 2, 3, 4, 5};

    // static-style init of a dynamic array (with raw pointers)
    int* arr3 = new int[5]{1, 2, 3, 4, 5};
    
    // array traversal (similar to vector)
    for (int val: arr1) {
        cout << val << " ";
    }
    cout << "\n";

    // STL Array
    array<int, 5> arr4 = {-1, -2, -3, -4, -5};
    for (int val: arr4) {
        cout << val << " ";
    }
    cout << "\n";
    
    // dynamic-size array creation
    int x = 5;
    unique_ptr<int[]> ptr1(new int[x]);
    std::copy(begin(arr1), end(arr1), ptr1.get());
    cout << ptr1[2] << "\n";    //3

    // // creating a unique ptr for static array is bad code
    // unique_ptr<int[]> ptr1(arr1);

    // dynamic-size array creation (another way, uses make_unique)
    unique_ptr<int[]> ptr2 = make_unique<int[]>(x);
    std::copy(begin(arr2), end(arr2), ptr2.get());
    cout << ptr2[2] << "\n";    //3
    
    // // NOTE: you cannot use range-based for loop for
    // // iterating over dynamic array (because it does
    // // not have 'begin' and 'end' defined)
    // for (int val: ptr2) {
        // will not work
    // }

    // static-style init of a dynamic array (smart pointer way)
    unique_ptr<int[]> ptr3(new int[5]{6, 7, 8, 9, 10});
    for(int i = 0; i < 5; i++) {
        cout << ptr3[i] << " ";
    }
    cout << "\n";
    
    // STL array are static. Unusual to manage them
    // dynamically using a smart ptr. But, its possible.
    unique_ptr<array<int, 5>> ptr4 = make_unique<array<int, 5>>(
        array<int, 5>{{10, 20, 30, 40, 50}});
    for (int val: *ptr4) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}