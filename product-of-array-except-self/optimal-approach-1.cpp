// Given an integer array nums,return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in 32-bit integer
// You must write an algorithm without using the division operation.

// Optimal Approach - Time Complexity => O(n), Space Complexity => O(n)

#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){

    int n = nums.size();
    vector<int> ans(n,1);
    vector<int> prefix(n,1); // Prefix : product of all elements before ith element
    vector<int> suffix(n,1); // Suffix : product of all elements after ith element

    // Prefix :
    for (int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] * nums[i-1];
    }

    // Suffix :
    for (int i = n-2; i >= 0; i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    // Answer :
    for (int i = 0; i < n; i++){
        ans[i] = prefix[i]*suffix[i];
    }

    return ans;

}

int main() {

    int n;
    cout << "Enter the Lenght of array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the values of array : ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> result = productExceptSelf(arr);

    cout << "Array containig product of elements(Except Self) : ";
    for (int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}