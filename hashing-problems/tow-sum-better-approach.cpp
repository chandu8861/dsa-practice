// Two Sum : better solution (2 pointer approach)
// Time Complexity : O(nlogn)
// Space Complexity : O(n)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();

    // Step 1: Copy nums
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());

    int start = 0, end = n-1;
    int val1 = -1, val2 = -1;

    // Step 2: Two-pointer search on sorted copy
    while (start < end) {
        int sum = sortedNums[start] + sortedNums[end];

        if (sum == target) {
            val1 = sortedNums[start];
            val2 = sortedNums[end];
            break;
        } else if (sum > target) {
            end--;
        } else {
            start++;
        }
    }

    // Step 3: Find original indices
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (nums[i] == val1 || nums[i] == val2) {
            ans.push_back(i);
            if (ans.size() == 2) break;
        }
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
