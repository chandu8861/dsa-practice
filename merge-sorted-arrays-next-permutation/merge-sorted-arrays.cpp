// You're given two integer arrays nums1 and nums2, Sorted in non decreasing order, and two integers m and n, 
// Representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non decreasing order.
// The final sorted array should not be returned By the function, but instead be stored inside the array nums1.
// To accommodate this, nums1 Has a length of M + N, where the first M elements denote the elements that should be merged,
// and the last n elements are set to 0 and should be ignored.
// nums2 has a lenght of n.

#include<iostream>
#include<vector>
using namespace std;

void mergeSortedArrays(vector<int>& nums1, int m, vector<int>& nums2, int n){

    // i is the index of the last element stored manually in nums1, not the size of nums1
    // size of nums1 is m+1.
    int i = m-1, j = n-1, index = m+n-1; // index points to the last index of nums1 (which is filled with zeros)

    // Because both arrays are sorted, we will start comparing in reverse order.
    // we will find the largest element in both arrays and sorted the largest at the end of nums1.

    while ( i >= 0 && j >= 0){

        if (nums1[i] > nums2[j]){
            nums1[index] = nums1[i];
            i--;
        }

        else {
            nums1[index] = nums2[j];
            j--;
        }

        index--;
    }

    // Add a second while loop to handle leftover elements in nums2 :

    while (j >= 0){
        nums1[index] = nums2[j];
        j--;
        index--;
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

int main(){

    vector<int> arr1 = {1,2,3,0,0,0};
    vector<int> arr2 = {2,5,6};

    mergeSortedArrays(arr1, 3, arr2, 3);
    printArray(arr1);

    // [ 1 2 2 3 5 6 ]

    return 0;
}