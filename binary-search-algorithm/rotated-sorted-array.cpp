// Find target in a rotated sorted array :
// normal sorted array : [1,2,3,4,5,6]
// rotated sorted array : [3,4,5,6,1,2] / [5,6,1,2,3,4]

#include<iostream>
#include<vector>
using namespace std;

int binarySearch_RSA(vector<int> &nums,int target){
    int start = 0, end = nums.size()-1;

    while (start <= end){

        int mid = start + (end-start)/2;

        if (nums[mid]==target){
            return mid;
        }
        
        // Left side is sorted 
        if (nums[start] <= nums[mid]){
            
            // target is in left side 
            if (nums[start] <= target && target <= nums[mid]){
                end = mid-1;
            }
            // target is in right side
            else {
                start = mid+1;
            }
        }

        // Right side is sorted
        else {

            // target is in right side
            if (nums[mid] <= target && target <= nums[end]){
                start = mid+1;
            }
            // target is in left side 
            else {
                end = mid-1;
            }
        }
    }
    return -1;
}

int main(){

    vector<int> arr = {4,5,6,1,2,3};
    int target = 5;
    int target2 = 0;

    cout << binarySearch_RSA(arr,target) << endl;
    // index : 1

    cout << binarySearch_RSA(arr,target2) << endl;
    // Not found : -1

    return 0;
}