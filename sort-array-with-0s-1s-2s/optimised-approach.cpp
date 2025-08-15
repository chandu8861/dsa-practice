// Given an array nums with n objects colored Red white or blue sort them in place so that the objects of the same color are adjacent with the colors in the order red white and blue.
// We will use integers zero, one, and two to represent the color red, white, and blue respectively.

// Optimised approach : Using count we find number of 0s, 1s and 2s and overwrite the array
// Time Complexity : O(n) but with 2 passes

#include<iostream>
#include<vector>
using namespace std;

void sortArray (vector<int>& nums){

    int n = nums.size();
    int count0 = 0, count1 = 0, count2 = 0;

    for (int val : nums){

        if (val == 0) count0++;
        if (val == 1) count1++;
        if (val == 2) count2++;

    }

    int index = 0;

    for (int i = 0; i < count0; i++){
        nums[index++] = 0;
    }

    for (int i = 0; i < count1; i++){
        nums[index++] = 1;
    }

    for (int i = 0; i < count2; i++){
        nums[index++] = 2;
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