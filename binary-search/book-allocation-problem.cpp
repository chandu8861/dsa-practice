// There are N books each ith book has A[i] number of pages
// You had to allocate books to M number of students so that the maximum number of pages allocated to a student is minimum.
// * Each book should be allocated to a student.
// * Each student has to be allocated at least one book.
// * Allotment should be in contiguous order.

// Calculate and return that maximum possible number.
// Return -1 if a valid assignment is not possible.

#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>& arr,int n,int m,int maxPages){

    int students = 1, pages = 0;

    for (int i = 0; i < n; i++){

        if (arr[i] > maxPages){
            return false;
        }

        if (pages + arr[i] <= maxPages){
            pages += arr[i];
        }

        else {
            students++;
            pages = arr[i];
        }
    }

    return students > m ? false : true;

}

int book_Allocation(vector<int>& arr,int n,int m){

    if (m > n) return -1;
    // because number of students cannot be greater the number of books

    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    
    int ans = -1;
    int start = 0, end = sum; // range of possible answer

    while (start <= end){

        int mid = start + (end-start)/2;

        if (isValid(arr, n, m, mid)){
            ans = mid;
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }

    return ans;
}

int main(){

    vector<int> arr = {2,1,3,4};
    vector<int> arr2 = {15,17,20};

    cout << book_Allocation(arr,4,2) << endl;

    cout << book_Allocation(arr2,3,2) << endl;
 
    cout << book_Allocation(arr,4,5) << endl; // Number of Students > Number of Books

    return 0;
}