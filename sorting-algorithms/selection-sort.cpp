// Selection Sort : Time Complexity O(n^2)
// For the given unsorted array first we will Find the index at which the smallest value exists and swap it with the first element
// And next we will move on to the next index and repeat the same process for the unsorted array this way we will increase the sorted elements
// and reduce unsorted elements.

#include<iostream>
using namespace std;

void selectionSort (int arr[], int n){

    for (int i = 0; i < n-1; i++){

        int smallestIndex = i;

        for (int j = i+1; j < n; j++){

            if (arr[j] < arr[smallestIndex]){
                smallestIndex = j;
            }

        }

        swap( arr[i] , arr[smallestIndex]);
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

    int arr[6] = {12,0,-24,56,100,90};

    selectionSort(arr,6);
    printArray(arr,6);
    // [ -24 0 12 56 90 100 ]

    return 0;
}