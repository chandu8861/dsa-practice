// Binary Search 
// Time Complexity : O(logn)
// Space Complexity : O(logn)

#include<iostream>
#include<vector>
using namespace std;

// Helper function :
int binarySearch (vector<int> arr, int target, int start, int end){
    int mid = start + (end - start)/2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) return binarySearch (arr, target, start, mid-1);
    else  return binarySearch (arr, target, mid+1, end);
    return -1;
}

// Given function :
int search (vector<int> arr, int target){
    return binarySearch(arr, target, 0, arr.size()-1);
}

int main(){
    vector<int> vec = {-1,0,3,5,9,12};
    cout << search(vec, 9);
    return 0;
}
// 4