#include<iostream>
using namespace std;

int diagonalSum (int matrix[][5], int rows, int columns){

    if (rows != columns) return -1;

    int sum = 0, n = rows; // rows == columns

    for (int i = 0; i < n; i++){

        sum += matrix[i][i]; // primary diagonal

        if (i != n-1-i) {  // avoid double-counting center
            sum += matrix[i][n-1-i]; // secondary diagonal
        }

    }

    return sum;
}

int main(){

    int matrix[5][5] = {{1,3,12,14,15},{23,20,1033,102,193},{20,949,33,233,235},{56,58,64,73,81},{98,85,5236,54,56}};

    if (diagonalSum(matrix,5,5) == -1){
        cout << "Diagonal sum is only defined for square matrices." << endl;
    } else {
        cout << "Diagonal sum of given matrix : " << diagonalSum(matrix,5,5)  << endl;
    }
    // Diagonal sum of given matrix : 456
    return 0;
}