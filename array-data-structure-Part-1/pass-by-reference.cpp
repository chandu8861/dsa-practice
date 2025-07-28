// Pass-by-reference
// Example : Doubling the elements of an array

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

    changearr(arr, n);

    cout << "In Main function : " << endl;

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}