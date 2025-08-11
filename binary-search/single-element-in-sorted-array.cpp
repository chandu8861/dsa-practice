// In a given sorted array, every elements appears twice except one element which appears exactly ones
// Example => [1,1,2,2,3,3,4,5,5,6,6]
// Note : in normal duplicate array the size of array is even, but in this case the size of array is odd(Extra single element)

#include<iostream>
#include<vector>
using namespace std;

int single_Non_Duplicate(vector<int>& arr){

    int left = 1, right = arr.size()-2;

    while (left <= right){

        int mid = left + (right-left)/2;

        // Condition to check single number 
        if (arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]) return mid;

        if (mid % 2 == 0){
            // if the mid index is even then both left and right side are even

            if (arr[mid-1] == arr[mid]){

                // if the preceeding element of mid is duplicate of mid then left side becomes odd 
                // and the single element lies there
                right = mid-1;
            }

            else {
                left = mid+1;
            }

        }

        else { // mid index is odd and left and right half are odd

            if (arr[mid-1] == arr[mid]){

                // if the preceeding element of mid is duplicate of mid then right side becomes odd
                // and the single element lies there
                left = mid+1;
            }

            else {
                right = mid-1;
            }

        }
    }
    return -1;
}

int main(){

    vector<int> arr1 = {1,1,2,3,3,4,4,8,8}; // mid is even
    vector<int> arr2 = {3,3,7,7,10,11,11}; // mid is odd

    cout << single_Non_Duplicate(arr1) << endl;
    // 2

    cout << single_Non_Duplicate(arr2) << endl;
    // 4

    return 0;
}


// Optimised appraoch 

// int single_Non_Duplicate(vector<int>& arr) {
//     int left = 0, right = arr.size() - 1;

//     while (left < right) {
//         int mid = left + (right - left) / 2;
//         if (mid % 2 == 1) mid--; // make sure mid is even

//         if (arr[mid] == arr[mid + 1]) {
//             left = mid + 2; // single element is on the right
//         } else {
//             right = mid; // single element is at mid or on the left
//         }
//     }
//     return arr[left];
// }


// Initial:
// left = 0, right = 8

// Iteration 1:
// mid = (0 + 8) / 2 = 4 → even already
// arr[mid] = 3, arr[mid+1] = 4 → not equal → move right = mid = 4

// Iteration 2:
// left = 0, right = 4
// mid = (0 + 4) / 2 = 2 → even already
// arr[mid] = 2, arr[mid+1] = 3 → not equal → move right = mid = 2

// Iteration 3:
// left = 0, right = 2
// mid = (0 + 2) / 2 = 1 → odd, so mid-- → mid = 0
// arr[mid] = 1, arr[mid+1] = 1 → equal → move left = mid + 2 = 2

// Now:
// left = 2, right = 2 → loop ends

// Return:
// arr[left] = arr[2] = 2

// ✅ Output: 2