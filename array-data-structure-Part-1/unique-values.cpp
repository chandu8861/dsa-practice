// To find the unique values in an array
// Nested loops

#include<iostream>
using namespace std;

int main(){

    int size;
    cout << "Enter the size of an array : ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array : ";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << "Unique Element(s) in the array : ";
    for (int i = 0; i < size; i++){
        int j;
        for ( j = 0; j < size; j++){
            if (i!=j && arr[i]==arr[j]){
                break;           // brak when duplicate at different index is encountered
            }
        }
        if (j==size){
            // inner loop completed fully without break => unique
            cout << arr[i] << " ";
        }
    }

    cout << endl;

    return 0;
}

// Output :

// Enter the size of an array : 5
// Enter the elements of the array : 1 3 1 2 4
// Unique Element(s) in the array : 3 2 4

// Enter the size of an array : 5
// Enter the elements of the array : 1 2 3 4 5
// Unique Element(s) in the array : 1 2 3 4 5 