// Painter's Partition Problem : 
// Given are N boards of length of each given in the form of array, and M painters. such that each paint takes one unit of time to paint one unit of board.
// The task is to find the minimum time to paint all the boards under the constraints that any painter will only paint continuous sections of the boards

// So here is the given scenario you are given an array of length of the board Which are to be painted by M painters Each painter should at least get a board And all the boards should be painted.   

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// To check whether all painters can complete the task in maximum alllowed time:

bool isPossible (vector<int>& boards, int n, int m, int maxAllowedTime){

    int painters = 1, time = 0; // we are assuming time and length as one

    for (int i = 0; i < n; i++){

        if (boards[i] > maxAllowedTime){
            return false;  // if the ith board is taken more time than average time(maximum alllowed time)
        }                  // then m painters cannot complete this.

        // To find how much painters are required to complete the task 
        // each painter can paint boards only within the max time.
        if (time + boards[i] <= maxAllowedTime){
            time += boards[i];
        }

        // if a painter has reached the limit, we will increase painters
        // and start allocating him the time where the previous one left
        else {
            painters++;
            time = boards[i];
        }
    }

    // if the total painters required to paint all boards are equal or less the allowed painters
    // then we return true or else we return false
    return painters <= m ? true : false;
}

int paintersPartition (vector<int>& boards, int n, int m){

    // To apply binary search we need to have a sorted array but the given array is not sorted
    // So we create a range which is sorted to apply binary search.

    // first we will get the best case where we will find the minimum time to paint all boards.
    // Best Case (hypotetically) : We will allot painters to all boards (n=m) so the minimum time to paint all boards
    // will be the maximum time of taken by that single painter who is doing painting at the largest board
    // because we need all boards to be painted, we have to wait for him to complete painting.

    // Worst Case (hypotetically) : We will allot a single painter to paint all borads (m=1).
    // time taken by him is sum of lengths of all boards (1 unit of lenght = i unit of time).

    int start = INT_MIN, end, ans = -1;

    // Range of binary search :

    for (int i = 0; i < n; i++){

        // best case (minimum time taken)

        start = max(start,boards[i]);

        // worst case (maximum time taken) 

        end += boards[i];
    }

    if (m > n){
        return -1; // if the number of painters are greator than boards, then the given condition is violated.
    }

    while (start <= end){

        int mid = start + (end-start)/2;

        // mid is the average time.
        // if m painters can complete painting n boards at mid time then answer is mid;
        // but we must check whether they can do the same for more less time
        // because the array is sorted, less value lies in left half 
        // so reduce the search space by moving end to mid - 1 (focusing on left half only)

        if (isPossible(boards,n,m,mid)){
            ans = mid;
            end = mid - 1;
        }

        // if the more than m painters are needed to paint n boards for given average time
        // then, we increase the search space by moving start to mid + 1
        // this way we are increasing the average time to check whether they can complete
        // the task with m people but more time

        else {
            start = mid + 1;
        }

    }

    return ans;
}

int main(){

    vector<int> boards = {40,30,10,20};
    // m is number of painters
    // n is number of boards (size of array)
    // boards[i] is the lenght of board at ith index

    // Minimum Time :
    cout << paintersPartition(boards,4,2) << endl;
    // 60
    
    cout << paintersPartition(boards,4,4) << endl;
    // 40

    cout << paintersPartition(boards,4,6) << endl;
    // -1 : Not found

    return 0;
}

// bool isPossible(vector<int>& boards, int n, int m, int maxAllowedTime) {
//     int painters = 1, time = 0;

//     for (int len : boards) {
//         if (len > maxAllowedTime) return false;

//         if (time + len <= maxAllowedTime) {
//             time += len;
//         } else {
//             painters++;
//             time = len;
//             if (painters > m) return false;
//         }
//     }
//     return true;
// }