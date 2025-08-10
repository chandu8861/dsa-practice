// Binary Search : Iterative Method
// Time Complexity : O(logn)
// Here reduced the search space by half => n,n/2,n/4,n/8,.....,1
// => n/2^0, n/2^1, n/2^2, n/2^3,....,n/2^k
// n/2^k = 1 => n = 2^k => log2(n) = k
// =>> log(n) = k; where n is the size of array
// k is the number of operations needed to find target

// Binary Search is only effective in case of sorted array

#include<iostream>
#include<vector>
using namespace std;

int binarySearch (vector<int> arr, int target){

    int start = 0, end = arr.size()-1;

    while (start <= end){ // Worst case scenario where the target is in the extreme ends of array

        int mid = start + (end-start)/2;
        // which is same as (start+end)/2 but the above is useful when both start and end are INT_MAX

        if (target < arr[mid]){
            end = mid-1;
        }

        else if (target > arr[mid]){
            start = mid+1;
        }

        else {
            return mid;
        }

    }
    return -1; // target is not in the array
}

int main(){

    // Odd array :
    vector<int> arr1 = {-1,0,2,5,9,12,21};
    int target1 = 12;

    cout << binarySearch(arr1,target1) << endl;
    // index : 5

    int target2 = 100;
    cout << binarySearch(arr1,target2) << endl;
    // -1

    // Even array :
    vector<int> arr2 = {-10,0,10,20,30,40};
    int target3 = 0;

    cout << binarySearch(arr2,target3) << endl;
    // index : 1

    int target4 = -3000;
    cout << binarySearch(arr2,target4) << endl;
    // -1
}