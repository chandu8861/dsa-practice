// Given an array nums with n objects colored Red white or blue sort them in place so that the objects of the same color are adjacent with the colors in the order red white and blue.
// We will use integers zero, one, and two to represent the color red, white, and blue respectively.

// Brute Force Approach : Using in-built sort() function.
// Time Complexity : O(nlog(n))

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortArray(vector<int>& nums){
    sort(nums.begin(),nums.end());
}

void printArray(vector<int>&nums){
    cout << "[ ";
    for (int val : nums){
        cout << val << " ";
    }
    cout << "]";
    cout << endl;
}

int main(){

    vector<int> arr = {1,0,0,2,1,2,1,2,0,0};
    sortArray(arr);
    printArray(arr);

    // [ 0 0 0 0 1 1 1 2 2 2 ]
    
    return 0;
}