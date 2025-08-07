// Given an integer array nums,return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in 32-bit integer
// You must write an algorithm without using the division operation.

// Optimal Approach - Time Complexity => O(n), Space Complexity => O(1)

#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){

    int n = nums.size();
    vector<int> ans(n,1);
    
    // Prefix :
    for (int i = 1; i < n; i++){
        ans[i] = ans[i-1]*nums[i-1]; // Directly updating the prefix value into answer
    }

    // Suffix :
    int suffix = 1;
    for (int i = n-2; i >= 0; i--){
        suffix *= nums[i+1]; // calculates the suffix of ith element
        ans[i] *= suffix;   // multiplies the suffix with prefix
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