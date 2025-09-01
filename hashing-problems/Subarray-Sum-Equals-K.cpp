// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Brute force approach
// Time Complexity : O(n^2)
// Space Complexity : O(1)

#include<iostream>
#include<vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {

    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = i; j < n; j++){
            sum += nums[j];
            if (sum == k) count++;
        }
    }

    return count;
}

int main(){

    vector<int> vec = {1,2,3,4,5,6};

    int result = subarraySum(vec,9);

    cout << "Total number of subarrays whose sum is equal to target are : " << result << endl;

    return 0;
}
// Total number of subarrays whose sum is equal to target are : 2