// slow and fast approach 
// space complexity : O(1);

#include<iostream>
#include<vector>
using namespace std;

int findDuplicate (vector<int>& nums){
    int slow = nums[0], fast = nums[0];

    do {
        slow = nums[slow]; // +1
        fast = nums[nums[fast]]; // +2
    } while (slow != fast);

    slow = nums[0];

    while (slow != fast){
        slow = nums[slow]; // +1
        fast = nums[fast]; // +1
    }

    return slow; // return fast;
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
        
    cout << "Duplicate element : " << findDuplicate(vec) << endl;
   
    return 0;
}

// Enter the size of vector : 6
// Enter the values of vector : 1 2 4 5 2 9
// Duplicate element : 2

// Enter the size of vector : 5
// Enter the values of vector : 3 3 3 3 3 
// Duplicate element : 3