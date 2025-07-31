// To find the majority element in vector/array - Moore's voting Algorithm
// frequency of the element must be greater than n/2
// Time Complexity  : O(n)

// Principle: If an element occurs more than n/2 times, it will always remain the last standing candidate.
// The algorithm cancels out different elements in pairs, so the majority element (if any) survives in the end.
// Final candidate is then verified (if needed) to ensure it meets the majority condition.

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums){

    int frequency = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++){

        if (frequency == 0){
            ans = nums[i];
        }

        if (ans == nums[i]){
            frequency++;
        }
        else {
            frequency--;
        }

    }

    return ans;

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

// Enter the number of elements : 12
// Enter 12 Values : 1 9 7 9 9 8 9 6 9 9 5 9    
// Majority element whose frequency greater than 6 is : 9