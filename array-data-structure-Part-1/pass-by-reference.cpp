// Pass-by-reference
// Example : Doubling the elements of an array

// In call-by-reference, the calling function gets the address of called function instead of a copy of the function
// so any changes made to the parameter in the called function will affect the original variable in the calling function.

#include<iostream>
using namespace std;

// Function to double the elements of the array
// Void function modifies the array but does not return anything

void changearr(int arr[], int size){
    for(int i=0; i<size; i++){
        arr[i] = 2*arr[i];
    }
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "In Called Function : " << endl;

    changearr(arr, n); // Call the function to double the elements

    cout << "In Main function : " << endl; // Display the modified array

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}

// Output:
// Enter the number of elements in the array: 3
// Enter the elements of the array: 2 3 4
// In Called Function : 
// In Main function : 
// 4
// 6
// 8