// Find the index at which the largest and smallest elements are present in an array

#include<iostream>
#include<algorithm>

using namespace std;
int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int LargestIndex = 0;
    int SmallestIndex = 0;

    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[LargestIndex]) {
            LargestIndex = i;
        }
        if(arr[i] < arr[SmallestIndex]) {
            SmallestIndex = i;
        }
    }

    cout << "Largest element is at index: " << LargestIndex << endl;
    cout << "Smallest element is at index: " << SmallestIndex << endl;

    cout << "Largest element is: " << arr[LargestIndex] << endl;
    cout << "Smallest element is: " << arr[SmallestIndex] << endl;

    // LargestIndex = max(arr, arr + n) - arr;
    // SmallestIndex = min(arr, arr + n) - arr;

    return 0;
}
