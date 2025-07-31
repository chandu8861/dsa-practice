// Find the Maximum Subarray Sum - By Brute Force approach
// Time Complexity : O(n^2)

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int maxSum = INT_MIN;
    for (int start = 0; start < n; start++){
        int curSum = 0; // to restart from new subarray with increment in start
        for (int end = start; end < n; end++){
            curSum += arr[end];
            maxSum = max(maxSum , curSum);
        }
    }

    cout << "Maximum Subarray Sum : " << maxSum << endl;

    return 0;

}