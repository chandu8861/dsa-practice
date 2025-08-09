// Pointers :
// Special variables that stores the memory address of other variables.

#include<iostream>
using namespace std;

int main(){

    // Initialisation of Pointers :
    int a = 10;
    
    int *ptr = &a; // & => address of Operator
    // * => Dereference Operator : Used to get the value at that address

    // Synatx : data_type *pointer_name = &variable;

    cout << ptr << endl;
    // 0x61ff0c : address of a.

    cout << *ptr << endl;
    // 10 : value of a.

    cout << &a << endl;
    // 0x61ff0c : address of a.

    cout << *(&a) << endl;
    // 10 : value of a.

    cout << &ptr << endl;
    // 0x61ff08 : address of ptr

    cout << *(&ptr) << endl;
    // 0x61ff0c

    // Pointer to Pointer :
    // Syntax : data_type **new_pointer_name = &pointer_name;

    int **ptr2 = &ptr;

    cout << ptr2 << endl;
    // 0x61ff08 : address of ptr

    cout << *ptr2 << endl;
    // 0x61ff0c : value of ptr2 (address of a)
    cout << **ptr2 << endl;
    // 10

    cout << &ptr << endl;
    // 0x61ff08 : address of ptr 

    cout << *(&ptr) << endl;
    // 0x61ff0c 
    cout << **(&ptr) << endl;
    // 10

    cout << &ptr2 << endl;
    // 0x61ff04 : address of ptr2

    cout << *(&ptr2) << endl;
    // 0x61ff08
    cout << **(&ptr2) << endl;
    // 0x61ff0c : value of ptr => address of a
}