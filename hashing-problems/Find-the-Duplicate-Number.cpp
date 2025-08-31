// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int findDuplicate(vector<int>& nums){

    unordered_set<int> s;

    for (int i = 0; i < nums.size(); i++){
        if (s.find(nums[i]) != s.end()) return nums[i];
        s.insert(nums[i]);
    }

    return -1;
}

int main(){

    int n;
    cout << "Enter the size of vector : ";
    cin >> n;

    vector<int> vec(n);

    cout << "Enter the values of vector : ";
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }

    if (findDuplicate(vec) == -1){
        cout << "Not duplicate element found in vector." << endl;
    } else {
        cout << "Duplicate element : " << findDuplicate(vec) << endl;
    }

    return 0;
}

// Enter the size of vector : 5
// Enter the values of vector : 3 3 3 3 3 
// Duplicate element : 3

// Enter the size of vector : 4
// Enter the values of vector : 1 2 3 4
// Not duplicate element found in vector.

// Enter the size of vector : 6
// Enter the values of vector : 1 2 4 5 2 9
// Duplicate element : 2