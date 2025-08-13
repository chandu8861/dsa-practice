// Bubble sort : Time Complexity : O(n^2)
// Working principle : Swaps the adjacent elements till (n-1) iteration to get ascending order (sorted array)
// Optimized with early termination when no swaps occur.

#include<iostream>
#include<vector>
using namespace std;

void bubbleSort (int arr[], int n){
    
    for (int i = 0; i < n; i++){

        bool isSwap = false; // because bubble sort works till (n-1) iterations even when array is sorted
        // using this we can avoid unnecessary swapping

        for (int j = 0; j < n-i-1; j++){
            
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSwap = true; // if there is swapping, continue sorting
            }

        }

        if (!isSwap){ // if there is no sorting (swapping) return the array
            return ;
        }
    }
}

void printArray (int arr[], int n){

    cout << '[';
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << ']';
    cout << endl;
}

int main(){

    int arr1[7] = {4,6,12,14,-1,0,20};

    bubbleSort(arr1,7);
    printArray(arr1,7);
    // [-1 0 4 6 12 14 20 ]

    return 0;
}