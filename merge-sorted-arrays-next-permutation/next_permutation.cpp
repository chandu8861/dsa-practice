// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
// More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, 
// then the next permutation of that array is the permutation that follows it in the sorted container. 
// If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

// Solution :

// Step 1 : find pivot => its an element that follows the condition ( A[i] < A[i+1]), when we check from backwards of the array.
// Example : A = [1,2,4,5,3] here pivot is 4 but 3 cannot be pivot because we cannot check for the last element.

// Step 2 : swap pivot element which is just greater than it from backwards.
// A = [1,2,4,5,3] => [1,2,5,4,3]
// A = [1,2,3,6,5,4] here pivot is 3 => [1,2,4,6,5,3]

// Step 3 : reverse all elements after pivot in ascending order
// A = [1,2,4,6,5,3] => [1,2,4,3,5,6]

// This we can find the next largest combination of the given array.

// NOTE : According to given question if there no pivot (usually for descending order array) : REVERSE IT.

// TIME COMPLEXITY : O(n) and SPACE COMPLEXITY : O(1) 

// SIMPLEST ANSWER : using library function
// next_permutation(vec.begin(),vec.end()); => in main() function

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation (vector<int>& nums){

    // Intialising pivot :
    int pivot = -1;
    int n = nums.size();

    // Find Pivot :
    for (int i = n-2; i >= 0; i--){ // we are start with n-2 to check for condition

        if (nums[i] < nums[i+1]){
            pivot = i;
            break;
        }
        // if no pivot is found return => -1
    }

    // Reverse the array into ascending order:
    if (pivot == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    // Swap pivot and it's just largest number:
    for (int i = n-1; i >= 0; i--){

        if (nums[pivot] < nums[i]){
            swap (nums[pivot],nums[i]);
            break;
        }
    }

    // Reverse : pivot+1 => n-1
    // reverse(nums.begin() + pivot+1, nums.end())
    int i = pivot+1, j = n-1;
    while (i < j){
        swap(nums[i++], nums[j--]);
    }

}

void printArray(vector<int>&nums){
    cout << "[ ";
    for (int val : nums){
        cout << val << " ";
    }
    cout << "]";
    cout << endl;
}

int main() {
    
    vector<int> vec = {1,2,3,6,5,4};
    nextPermutation(vec);
    printArray(vec);

    // Next possible largest combination :
    // [ 1 2 4 3 5 6 ]

    return 0;
}