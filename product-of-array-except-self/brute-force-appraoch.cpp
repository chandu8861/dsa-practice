// Given an integer array nums,return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in 32-bit integer
// You must write an algorithm without using the division operation.

#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {

    vector<int> answer(nums.size()); // vector<int> answer(n,1)....(1)

    for (int i = 0; i < nums.size(); i++){
        
        int product = 1;   // no need if we do step (1)

        for (int j = 0; j < nums.size(); j++){

            if (i != j){
                product *= nums[j]; // ans[i] *= numms[j]
            }

        }

        answer[i] = product;
    }

    return answer;
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