// Optimal solution
// Time Complexity : O(n)
// Space Complexity : O(n)

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int subarraySum(vector<int>& nums, int k){

    int n = nums.size();
    vector<int> prefixSum(n,0);
    unordered_map<int, int> m;
    int count = 0;

    for (int i = 0; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }

    for (int j = 0; j < n; j++){

        if (prefixSum[j] == k) count++;

        int val = prefixSum[j] - k;
        if (m.find(val) != m.end()) count += m[val];
        if (m.find(prefixSum[j]) == m.end()) m[prefixSum[j]] = 0;

        m[prefixSum[j]]++;
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

// int subarraySum(vector<int>& nums, int k){

//     unordered_map<int, int> m; // stores prefixSum frequency
//     int prefixSum = 0, count = 0;

//     for (int num : nums){
//         prefixSum += num;

//         if (prefixSum == k) count++;

//         if (m.find(prefixSum - k) != m.end())
//             count += m[prefixSum - k];

//         m[prefixSum]++;
//     }

//     return count;
// }

