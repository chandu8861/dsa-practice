// Given an array nums with n objects colored Red white or blue sort them in place so that the objects of the same color are adjacent with the colors in the order red white and blue.
// We will use integers zero, one, and two to represent the color red, white, and blue respectively.

// Optimal Approach : Dutch National flag Algorithm.
// Time Complexity : O(n)
// Space Complexity : O(1)

// We will have Three pointers : low, mid and high

// Assume the array into four parts (paritions).
// First Parition : Only 0's (0 -> low-1).
// Second Parition : Only 1's (low -> mid-1)
// Third Parition : Only 2's (high -> n-1)

// Fourth Parition : (mid -> high) : Intially is the unsorted array given but after going through the algortihm it reduces to zero.

#include<iostream>
#include<vector>
using namespace std;

void sortArray (vector<int>& nums){

    int n = nums.size();
    int low = 0, mid = 0, high = n-1;

    while (mid <= high){

        if (nums[mid] == 0){
            swap(nums[mid],nums[low]);
            mid++;
            low++;
        }

        else if (nums[mid] == 1){
            mid++;
        }

        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
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