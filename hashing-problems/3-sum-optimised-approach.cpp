// Optimised solution : two pointer approach
// Time Complexity  : O(nlogn + n^2)
// Space complexity : O(unique_triplets)

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){

    int n = nums.size();
    vector<vector<int>> ans;
    sort (nums.begin(), nums.end());

    for (int i = 0; i < n; i++){
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int j = i+1, k = n-1;

        while (j < k){
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0) j++;
            else if (sum > 0) k--;
            else {
                ans.push_back({nums[i],nums[j],nums[k]});
                j++,k--;
                while (j < k && nums[j] == nums[j-1]) j++;
            }
        }

    }

    return ans;
}

int main(){

    vector<int> vec = {-1,0,1,2,-1,-4};

    vector<vector<int>> result = threeSum(vec);

    cout << "[ ";
    for (int i = 0; i < result.size(); i++){
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;

    return 0;
}
// [ [ -1 -1 2 ] [ -1 0 1 ] ]