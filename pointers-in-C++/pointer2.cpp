// NULL Pointer :
// A Pointer that doesnot point to any memory location.

#include<iostream>
using namespace std;


// Pass by reference using pointer
void change(int *ptr){
    *ptr = 20; // changing the value of the pointer (*ptr)
}

// Pass by reference using alias : Here instead of creating a new variable
// we will make change in the main variable using address of Opreator
void change2(int &b){
    b = 30;
}

int main(){

    int* ptr;
    cout << ptr << endl;
    // 0x401a3b : some random memory location

    int* ptr1 = NULL;     // int* ptr1 = nullptr;
    cout << ptr1 << endl; //  in modern C++, nullptr is preferred over NULL because it’s type-safe:
    // 0 : NO memory alloted.

    int a = 10;
    change(&a); // address of a
    cout << "Value of a (after changing) : " << a << endl;
    // Value of a (after changing) : 20

    int c = 100;
    change2(c);
    cout << "Value of c (after changing) : " << c << endl;
    // Value of c (after changing) : 30

    // Array Pointer :
    // array_name => arr : is a pointer which points to the first element of the array

    int arr[] = {1,2,3,4,5};
    cout << arr << endl; // 0x61feec
    cout << *arr << endl; // 1

    return 0;
}