// Peak index in the mountain array /
// here in array, first the elements keep increasing and at the peak value it starts decreasing
// Example => [0,3,8,9,4,1]
// here peak value is at index 3

#include<iostream>
#include<vector>
using namespace std;

int peak_Index_In_Mountain_array (vector<int>& arr){

    int start = 1, end = arr.size()-2; // because the start and end element cannot be mid 
    // if they become mid then there is not mountain array

    while (start <= end){

        int mid = start + (end-start)/2;
        if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid;
        // peak value will greater than both preceeding and succeding value

        if (arr[mid-1] < arr[mid]){
            start = mid+1; // if the condition is true then mid lies in increasing side but the mid in opposite sie
            // so move start to the value after mid
        }

        else {
            end = mid-1; 
        }

    }

    return -1;
}

int main(){

    vector<int> nums = {0,3,6,8,12,6,3};
    vector<int> nums2 = {3,9,5,3,0};
    vector<int> nums3 = {10,9,8,7,6,5};

    cout << peak_Index_In_Mountain_array(nums) << endl;
    // index : 4
    cout << peak_Index_In_Mountain_array(nums2) << endl;
    // index : 1
    cout << peak_Index_In_Mountain_array(nums3) << endl;
    // -1 : because give array is not mountain array

    return 0;
}