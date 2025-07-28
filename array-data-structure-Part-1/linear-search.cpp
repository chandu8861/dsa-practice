// Linear Search : Algorithm to search for a specific element in an array
#include <iostream>
using namespace std;    

// Linear Search uses simple for loop to find a particular element in an array.
// It returns the index of the element if found, otherwise returns -1.

int LinearSearch(int arr[],int size){

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    for(int i = 0; i < size; i++){
        if (arr[i] == target){
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found

}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int result = LinearSearch(arr, size); 
    // if result is not declared then we have to use LinearSearch(arr, size) twice but it results in entering the target twice

    if (result == -1){
        cout << "Enter element not found in the array." << endl;
    }
    else{
        cout << "Element found at index " << result << endl;
    }

    return 0;
}

// Output :

// Enter the size of the array: 4
// Enter the elements of the array: 1 2 3 4
// Enter the element to search: 2
// Element found at index 1