#include<iostream>
using namespace std;

int main(){

    // Pointer Arithmetic 
    // When we do arithmetic operations on pointers we are modifying the address of the pointer not the value of the pointer.

    // Increment(++) :

    int a = 100;
    int *ptr = &a;

    cout << ptr << endl; // 0x61ff08 => address of a
    ptr++; 
    // Increasing the size of ptr by 4-bit
    // increment depends on data type
    // so for int we can increase the size of pointer by 4 bit

    // cout << *ptr << endl;
    // When you dereference it (*ptr), you’re accessing memory you don’t own → undefined behavior.

    cout << ptr << endl;
    // 0x61ff0c 
    // 8 => c (which is 12 in hexadecimal)

    // Decrement(--) :

    int b = 200;
    int *ptr2 = &b;

    cout << ptr2 << endl; // 0x61ff00 
    ptr2--;
    cout << ptr2 << endl; // 0x61fefc 

    // Add Number :
    int c = 10;
    int *ptr3 = &c;

    cout << ptr3 << endl;
    // 0x61fef8
    ptr3 = ptr3 + 2;
    cout << ptr3 << endl;
    // 0x61ff00 => here 8-bit is added (2-int)

    // Subtract Number :
    int d = 20;
    int* ptr4 = &d;

    cout << ptr4 << endl;
    // 0x61fef0
    ptr4 = ptr4 - 10;
    cout << ptr4 << endl;
    // 0x61fec8 => subtract 80-bit (10-int)

    int arr[] = {1,2,3,4,5};
    cout << *arr << endl; // 1
    cout << *(arr+1) << endl; // 2
    cout << *(arr+2) << endl; // 3
    
    return 0;
}