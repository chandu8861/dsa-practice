// Spriral Matrix 
// Given an m x n matrix, return all elements of the matrix in spiral order.

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

#include<iostream>
#include<vector>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix){

    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;

    int start_row = 0, start_column = 0, end_row = m-1, end_column = n-1;

    while (start_row <= end_row && start_column <= end_column){

        // TOP :
        for (int i = start_column; i <= end_column; i++){
            ans.push_back(matrix[start_row][i]);
        }

        // RIGHT :
        for (int i = start_row+1; i <= end_row; i++){
            ans.push_back(matrix[i][end_column]);
        }

        // BOTTOM :
        for (int i = end_column-1; i >= start_column; i--){

            // edge case : In case of odd m
            if (start_row == end_row) break;

            ans.push_back(matrix[end_row][i]);
        }

        // LEFT :
        for (int i = end_row-1; i >= start_row+1; i--){

            // edge case : In case of odd n
            if (start_column == end_column) break;

            ans.push_back(matrix[i][start_column]);
        }

        start_row++, start_column++, end_row--, end_column--;
    }

    return ans;
}

int main(){

    vector<vector<int>> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};

    vector<int> result = spiralOrder(matrix);

    cout << "[ ";
    for (int val : result){
        cout << val << " ";
    }
    cout << "]" << endl;

    return 0;
}

// [ 1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 14 13 12 ]