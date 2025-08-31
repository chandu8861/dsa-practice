// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicate j

            int k = j + 1, l = n - 1;

            while (k < l) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if (sum < target) k++;
                else if (sum > target) l--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++, l--;

                    // skip duplicates for k
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    // skip duplicates for l
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> vec = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSum(vec, target);

    cout << "[ ";
    for (auto &quad : result) {
        cout << "[ ";
        for (int num : quad) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;

    return 0;
}
// [ [ -2 -1 1 2 ] [ -2 0 0 2 ] [ -1 0 0 1 ] ]