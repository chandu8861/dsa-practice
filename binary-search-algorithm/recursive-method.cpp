//  Binary Search : Recursive Method
// Time Complexity : O(logn)
// Space Complexity : O(logn)

#include<iostream>
#include<vector>
using namespace std;

int binarySearch (vector<int> arr, int target, int start, int end){

    if (start <= end){

        int mid = start + (end-start)/2;

        if (target < arr[mid]){
            return binarySearch (arr,target,start,mid-1);
        }

        else if (target > arr[mid]){
            return binarySearch (arr,target,mid+1,end);
        }

        else {
            return mid;
        }
    }
    return -1;
}

int main(){

    // Odd array :
    vector<int> arr1 = {-1,0,2,5,9,12,21};
    int target1 = 12;

    cout << binarySearch(arr1,target1,0,arr1.size()-1) << endl;
    // index : 5

    int target2 = 100;
    cout << binarySearch(arr1,target2,0,arr1.size()-1) << endl;
    // -1

    // Even array :
    vector<int> arr2 = {-10,0,10,20,30,40};
    int target3 = 0;

    cout << binarySearch(arr2,target3,0,arr2.size()-1) << endl;
    // index : 1

    int target4 = -3000;
    cout << binarySearch(arr2,target4,0,arr2.size()-1) << endl;
    // -1
}

// int binarySearchTail(const vector<int>& arr, int target, int start, int end) {
//     if (start > end) return -1; // Not found

//     int mid = start + (end - start) / 2;

//     if (arr[mid] == target) return mid; // Found

//     // The recursive call is the last thing we do (tail recursion)
//     return (target < arr[mid])
//         ? binarySearchTail(arr, target, start, mid - 1)
//         : binarySearchTail(arr, target, mid + 1, end);
// }

// Vector passed by const& → avoids copying.

// Recursive call happens immediately with no extra work after it.

// The return statement directly returns the recursive call’s result.

// This form can be optimized by the compiler into a loop-like form.