// Implementation of reverse in vector 

#include<iostream>
#include<vector>
using namespace std;

void reverseVector(vector<int>& nums){

    int start = 0, end = nums.size() - 1;
    // Using size_t prevents issues when working with large vectors because it matches the return type of vector::size().
    // size_t start = 0, end = nums.size() - 1;

    while(start < end){

        swap(nums[start],nums[end]);
        start++;
        end--;

    }
}

int main(){

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> vec(n);

    cout << "Enter " << n << " Values : ";
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    reverseVector(vec);

    cout << "Reverse Vector : ";
    for (int val : vec){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}