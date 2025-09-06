// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

#include<iostream>
#include<vector>
using namespace std;

void getPermutations (vector<int>& nums, int index, vector<vector<int>>& ans){

    if (index == nums.size()){
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++){

        swap (nums[index], nums[i]);

        getPermutations (nums, index+1, ans);

        swap (nums[index], nums[i]); // Backtracking

    }

}

vector<vector<int>> permute (vector<int>& nums){

    vector<vector<int>> ans;

    getPermutations (nums, 0, ans);

    return ans;

}

int main(){

    vector<int> vec = {1,2,3};

    vector<vector<int>> result = permute(vec);

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

// [ [ 1 2 3 ] [ 1 3 2 ] [ 2 1 3 ] [ 2 3 1 ] [ 3 2 1 ] [ 3 1 2 ] ]