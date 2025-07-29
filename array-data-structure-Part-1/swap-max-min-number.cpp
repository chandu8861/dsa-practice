// To Swap MAX and MIN Number in an array

#include<iostream>
using namespace std;

void swapMaxAndMinNumber(int arr[], int size){

    int maxIndex = 0,minIndex = 0;
    for (int i = 0; i < size; i++){

        if (arr[maxIndex] < arr[i]){
            maxIndex = i;
        }

        if (arr[minIndex] > arr[i]){
            minIndex = i;
        }
    }

    swap(arr[maxIndex],arr[minIndex]);

}

int main(){

    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array : ";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    swapMaxAndMinNumber(arr,size);

    cout << "The array after swapping max and min number : ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Output :

// Enter the size of the array : 5
// Enter the elements of the array : 1 2 3 4 5
// The array after swapping max and min number : 5 2 3 4 1 

// Enter the size of the array : 6
// Enter the elements of the array : 0 -2 4 5 10 3
// The array after swapping max and min number : 0 10 4 5 -2 3 