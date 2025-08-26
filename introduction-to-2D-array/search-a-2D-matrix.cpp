// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return the index of the target.

// You must write a solution in O(log(m * n)) time complexity.

#include<iostream>
#include<vector>
using namespace std;

pair<int, int> searchRow(vector<vector<int>>& matrix, int target, int row){

    int n = matrix[0].size();

    int start = 0, end = n-1;

    while (start <= end){

        int mid = start + (end - start)/2;

        if (target == matrix[row][mid]){
            return {row,mid};
        }
        else if (target > matrix[row][mid]){
            start = mid +1;
        } 
        else {
            end = mid - 1;
        }
    }

    return {-1,-1};
}
pair<int, int> searchMatrix (vector<vector<int>>& matrix, int target){

    int m = matrix.size(); // size of rows
    int n = matrix[0].size(); // size of columns

    int startRow = 0, endRow = m-1;

    // search the row containing target :

    while (startRow  <= endRow){

        int midRow = startRow + (endRow - startRow)/2;

        if (target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
            return searchRow(matrix, target, midRow);
        } else if (target > matrix[midRow][n-1]){
            startRow = midRow + 1;
        } else {
            endRow = midRow - 1;
        }
    }

    return {-1,-1};
}

int main(){

    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    pair<int, int> result = searchMatrix(matrix,3);

    if (result.first == -1){
        cout << "Target not found." << endl;
    }
    else{
        cout << "Target found at cell : " << result.first << "," << result.second << endl;
    }

    // Target found at cell : 0,1

    return 0;
}

// pair<int,int> searchMatrix(vector<vector<int>>& matrix, int target) {
//     int m = matrix.size();
//     int n = matrix[0].size();

//     int start = 0, end = m * n - 1;

//     while (start <= end) {
//         int mid = start + (end - start) / 2;

//         // Convert 1D index -> 2D indices
//         int row = mid / n;
//         int col = mid % n;

//         if (matrix[row][col] == target) {
//             return {row, col};
//         }
//         else if (matrix[row][col] < target) {
//             start = mid + 1;
//         }
//         else {
//             end = mid - 1;
//         }
//     }
//     return {-1, -1};
// }