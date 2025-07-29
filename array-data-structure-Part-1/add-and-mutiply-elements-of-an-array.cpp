// Find the Sum and Product of Elements in an Array

#include <iostream>
using namespace std;    

int addNumber(int arr[],int size) {

    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i]; // Add each element to the sum
    }
    return sum;
}

int multiplyNumber(int arr[], int size) {

    int product = 1;
    for (int i = 0; i < size; i++){
        product *= arr[i]; // Multiply each element to the product
    }
    return product;
}

int main() {

    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array : ";

    for (int i = 0; i < size; i++){
        cin >> arr[i]; 
    }

    cout << "Sum of Elements of an array : " << addNumber(arr, size) << endl;
    cout << "Product of Elements of an array : " << multiplyNumber(arr, size) << endl;

    return 0;
}

// Output :

// Enter the size of the array : 5
// Enter the elements of the array : 1 2 3 4 5
// Sum of Elements of an array : 15
// Product of Elements of an array : 120