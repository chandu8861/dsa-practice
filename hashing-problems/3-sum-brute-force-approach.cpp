// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Brute force approach.
// Time complexity : O(n^3 * log(unique_triplets))
// Space Complexity : O(unique_triplets)

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){

    set<vector<int>> s;
    vector<vector<int>> ans;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){

                if (nums[i]+nums[j]+nums[k] == 0){
                    vector<int> triplest = {nums[i],nums[j],nums[k]};
                    sort (triplest.begin(), triplest.end());

                    if (s.find(triplest) == s.end()){
                        s.insert(triplest);
                        ans.push_back(triplest);
                    }
                }
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

// [ [ -1 0 1 ] [ -1 -1 2 ] ]