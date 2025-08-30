// Two Sum : optimised solution using hashing (unordered map or set)
// Time Complexity : O(n)
// Space Complexity : O(1)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    
    int n = nums.size();
    unordered_map<int, int> m;
    vector<int> ans;

    for (int i = 0; i < n; i++){

        int first = nums[i];
        int second = target - first;

        if (m.find(second) != m.end()){
            ans.push_back(i);
            ans.push_back(m[second]);
            break;
        }

        m[first] = i;
    }

    return ans;
}

int main() {
    vector<int> nums = {2,7,11,15};
    vector<int> result = twoSum(nums, 9);

    cout << "Indices of two numbers whose sum is equal to target are : ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// Indices of two numbers whose sum is equal to target are : 1 0