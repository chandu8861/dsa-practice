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
    // 6

    cout << book_Allocation(arr2,3,2) << endl;
    // 32
 
    cout << book_Allocation(arr,4,5) << endl; // Number of Students > Number of Books
    // -1

    return 0;
}
 
// Optimised approach

// #include <iostream>
// #include <vector>
// #include <algorithm> // for max_element
// using namespace std;

// // Helper function to check if we can allocate books
// bool isValid(vector<int>& books, int n, int m, int maxPages) {
//     int students = 1; // start with first student
//     int pages = 0;    // pages allocated to current student

//     for (int i = 0; i < n; i++) {
//         // If a single book has more pages than allowed maxPages → not possible
//         if (books[i] > maxPages) {
//             return false;
//         }

//         // If current student can take this book without exceeding maxPages
//         if (pages + books[i] <= maxPages) {
//             pages += books[i];
//         }
//         // Otherwise, give book to next student
//         else {
//             students++;
//             pages = books[i]; // start count for next student
//         }
//     }

//     // If we used more students than available, it's invalid
//     return students <= m;
// }

// // Main function to find the minimum maximum pages
// int book_Allocation(vector<int>& books, int n, int m) {
//     // If students are more than books, impossible
//     if (m > n) return -1;

//     // Step 1: Find search range
//     int start = *max_element(books.begin(), books.end()); // at least the biggest book
//     int end = 0;
//     for (int pages : books) end += pages; // at most sum of all pages

//     int ans = -1;

//     // Step 2: Binary Search
//     while (start <= end) {
//         int mid = start + (end - start) / 2;

//         if (isValid(books, n, m, mid)) {
//             ans = mid;       // mid is a possible answer
//             end = mid - 1;   // try smaller maximum
//         } else {
//             start = mid + 1; // need bigger maximum
//         }
//     }

//     return ans;
// }

// int main() {
//     vector<int> arr = {2, 1, 3, 4};
//     vector<int> arr2 = {15, 17, 20};

//     cout << book_Allocation(arr, 4, 2) << endl;  // Expected: 5
//     cout << book_Allocation(arr2, 3, 2) << endl; // Expected: 32
//     cout << book_Allocation(arr, 4, 5) << endl;  // Expected: -1

//     return 0;
// }