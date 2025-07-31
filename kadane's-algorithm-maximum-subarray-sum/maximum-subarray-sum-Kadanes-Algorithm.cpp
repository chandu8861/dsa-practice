// To find Maximum subarray sum : Kadane's Algorithm 
// Kadane's Algorithm: Iterates through the array while keeping track of the current sum and maximum sum found so far. 
// If current sum becomes negative, it is reset to 0. This ensures we only consider subarrays with positive contribution. 
// Time Complexity: O(n)

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

    int currSum = 0, maxSum = INT_MIN;
    for (int i = 0; i < n; i++){

        currSum += arr[i];
        maxSum = max(maxSum, currSum);

        if (currSum < 0){
            currSum = 0;
        }

    }

    cout << "Maximum Subarray Sum : " << maxSum << endl;

    return 0;

}