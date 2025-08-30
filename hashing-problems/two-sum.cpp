// Two Sum : brute force approach
// Time Complexity : O(n^2)
// Space Complexity : O(1)

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum (vector<int>& nums, int target){

    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (nums[i]+nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}

int main(){

    vector<int> nums = {2,7,11,15};
    vector<int> result = twoSum(nums,9);

    cout << "Indices of two numbers whose sum is equal to target are : ";
    for (int val : result){
        cout << val << " ";
    }
    cout << endl;

    // Indices of two numbers whose sum is equal to target are : 0 1 

    return 0;
}