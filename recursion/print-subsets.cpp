#include<iostream>
#include<vector>
using namespace std;

void getAllSubsets(vector<vector<int>>& allSubsets, vector<int>& nums, int i, vector<int>& ans){
    if (i == nums.size()) {
        allSubsets.push_back(ans);
        return;
    }

    ans.push_back(nums[i]);
    getAllSubsets(allSubsets, nums, i+1, ans);

    ans.pop_back();
    getAllSubsets(allSubsets, nums, i+1, ans);
}

vector<vector<int>> subsets (vector<int>& nums){
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getAllSubsets(allSubsets, nums, 0 , ans);

    return allSubsets;
}

int main(){

    vector<int> vec = {1,2,3};

    vector<vector<int>> result = subsets(vec);

    cout << "[ ";
    for (int i = 0; i < result.size(); i++){
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << "] ";
    }
    cout << "]";

    return 0;
}

// [ [ 1 2 3 ] [ 1 2 ] [ 1 3 ] [ 1 ] [ 2 3 ] [ 2 ] [ 3 ] [ ] ]