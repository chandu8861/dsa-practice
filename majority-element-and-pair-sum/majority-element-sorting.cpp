// To find the majority element in vector/array - Optimised approach (sorting)
// frequency of the element must be greater than n/2
// Time Complexity  : O(nlog(n))

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int majorityElement(vector<int>& nums){

    int n = nums.size();

    sort(nums.begin(), nums.end()); // USed to sort elements in an array
    // Time complexity : O(nlog(n))

    int frequency = 1, ans = nums[0];

    for ( int i = 1; i < n; i++){
        if (nums[i] == nums[i-1]){
            frequency++;
        }
        else{
            frequency = 1;
            ans = nums[i];
        }

        if (frequency > n/2){
            return ans;
        }
    }
    
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> vec(n);

    cout << "Enter " << n << " Values : ";
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int result = majorityElement(vec);
    if (result == -1){
        cout << "No majority element whose frequency greater than " << n/2 << " appears in the array. " << endl;
    }
    else {
        cout << "Majority element whose frequency greater than " << n/2 << " is : " << result << endl;
    }

    return 0;

}

// Enter the number of elements : 7
// Enter 7 Values : 1 2 3 2 2 2 4
// Majority element whose frequency greater than 3 is : 2