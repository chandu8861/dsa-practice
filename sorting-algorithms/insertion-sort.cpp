// Insertion Sort : Time Complexity o(n^2)
// Principle : Assume that the first element of the array is already sorted.
// For each next element, compare it with the elements in the sorted part of the array.
// Shift elements that are greater than the current element to the right,
// and insert the current element at its correct position.

#include<iostream>
using namespace std;

void insertion_Sort(int arr[], int n){

    for (int i = 1; i < n; i++){ // we are start with second element assuming first element is sorted.

        int curr = arr[i];
        int prev = i-1;

        // Shift larger elements to the right

        // for descending order :
        // while (prev >= 0 && arr[prev] < curr)

        while (prev >= 0 && arr[prev] > curr){ // To check if the previous is greater than cuurent

            arr[prev+1] = arr[prev]; // overwriting current with previous
            prev--; // To exit the infinite loop 
        }

        arr[prev+1] = curr;
        // prev-- moves the pointer leftward through the sorted section.
        // When the loop ends, prev points to the index just before the correct insertion spot.
        // That’s why we insert at arr[prev + 1].
    }
}

void printArray (int arr[], int n){

    cout << "[ ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "]";
    cout << endl;
}

int main(){

    int arr[5] = {4,1,5,2,3};

    insertion_Sort(arr,5);
    printArray(arr,5);

    // [ 1 2 3 4 5 ]
    return 0;
}