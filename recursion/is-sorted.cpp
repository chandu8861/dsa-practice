// Find if the array id sorted or not 
// Time Complexity : O(n)
// Space Complexity : O(n)

#include<iostream>
#include<vector>
using namespace std;

bool isSorted (vector<int> arr, int n){

    if (n == 0 || n == 1) return true;

    return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}

int main(){

    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    vector<int> vec(n);

    cout << "Enter the elements of array : ";
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }

    if (isSorted(vec,n)){
        cout << "Given array is sorted. " << endl;
    } else {
        cout << "Given array is not sorted. " << endl;
    }

    return 0;
}

// Enter the size of array : 5
// Enter the elements of array : 1 2 3 4 5
// Given array is sorted. 

// Enter the size of array : 6
// Enter the elements of array : 1 3 2 5 7 4
// Given array is not sorted.