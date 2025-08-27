// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

#include<iostream>
#include<vector>
using namespace std;

pair<int, int> searchMatrix (vector<vector<int>>& matrix, int target){

    int row = 0, column = matrix[0].size()-1;

    while (column >= 0 && row < matrix.size()){

        if (target == matrix[row][column]){
            return {row,column};
        }

        else if (target <  matrix[row][column]){
            column--;
        }

        else {
            row++;
        }
    }
    return {-1,-1};
}

// works only when the matrix is globally sorted row by row

// pair<int, int> binarySearch_Matrix (vector<vector<int>>& matrix, int target){

//     int m = matrix.size(), n = matrix[0].size();
//     int start = 0, end = m * n -1;

//     while (start <= end){

//         int mid = start + (end - start)/2;
//         int row = mid / n;
//         int column = mid % n;

//         if (target == matrix[row][column]) return {row,column};
//         else if (target > matrix[row][column]) start = mid + 1;
//         else end = mid - 1;
//     }

//     return {-1,-1};
// }

int main(){

    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    pair<int, int> result = searchMatrix(matrix, 5);

    if (result.first == -1){
        cout << "Target not found." << endl;
    }
    else{
        cout << "Target found at cell : " << result.first << "," << result.second << endl;
    }
    // Target found at cell : 1,1
    
    return 0;
}