// Better solution 
// Time Complexity : O(n^2 * log(unique_triplets))
// Space Complexity : O(unique_triplets + n)

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){

    int n = nums.size();
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < n; i++){

        set<int> s;
        int target = -nums[i];

        for (int j = i+1; j < n; j++){
            int third = target - nums[j];

            if (s.find(third) != s.end()){

                vector<int> triplest = {nums[i], nums[j], third};
                sort(triplest.begin(), triplest.end());

                uniqueTriplets.insert(triplest);
            }
            s.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
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