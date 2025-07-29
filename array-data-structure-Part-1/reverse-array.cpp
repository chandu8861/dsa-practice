// Reverse of an array 
// Approach : 2 - Pointer approach
// Time Complexity : O(n)

#include<iostream>
using namespace std;

void reverseArray(int arr[],int size){

    int start = 0, end  = size-1;

    while (start < end){  
        // Loop until the two pointers meet
        // Swap the elements at the start and end pointers 
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

}

int main(){

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: ";

    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    reverseArray(arr, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}

// Output :

// Enter the size of the array: 5
// Enter the elements of the array: 1 2 3 4 5
// Reversed array: 5 4 3 2 1 

// Enter the size of the array: 6
// Enter the elements of the array: 12 13 -1 0 4 13
// Reversed array: 13 4 0 -1 13 12 