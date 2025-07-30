// Given a non-integer array of integers "nums", every element appears twice except one. Find that single integer
// LeetCode :: Level: Easy, Problem Number: 136

#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums){

    int ans = 0;
    for (int val : nums){
        ans ^= val;
    } 

    return ans;
}

// Logic : Usage of bitwise XOR Operator
// In case of bitwise XOR Operator when the Same element is passed it will return 0
// like n^n = 0 but n^0 = n

// Truth Table :
// 1 ^ 1 = 0
// 0 ^ 0 = 0
// 1 ^ 0 = 1
// 0 ^ 1 = 1

int main(){

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> vec(n);

    cout << "Enter " << n << " Values : ";
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }

    int result = singleNumber(vec);

    cout << "Single number : " << result << endl;

    return 0;
}

// Output :

// Enter the number of elements : 5
// Enter 5 Values : 4 1 2 2 1
// Single number : 4

// 4 = 100, 1 = 001, 2 = 010
// 100 ^ 001 = 101
// 101 ^ 010 = 111
// 111 ^ 010 = 101
// 101 ^ 001 = 100 => 4