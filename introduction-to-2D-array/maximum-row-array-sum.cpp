#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int maxRowSum (int matrix[][3], int rows, int columns){

    int maxRowSum = INT_MIN;

    for (int i = 0; i < rows; i++){
        int sum = 0;

        for (int j = 0; j < columns; j++){
            sum += matrix[i][j];
        }

        maxRowSum = max(maxRowSum, sum);
    }

    return maxRowSum;
}

int maxColumnSum (int matrix[][3], int rows, int columns){

    int maxColumnSum = INT_MIN;

    for (int i = 0; i < columns; i++){
        int sum = 0;

        for (int j = 0; j < rows; j++){
            sum += matrix[j][i];
        }

        maxColumnSum = max(maxColumnSum, sum);
    }

    return maxColumnSum;
}

int main(){

    int matrix[4][3] = {{1,2,3},{4,3,6},{7,8,9},{10,11,12}};

    cout << "The maximum row sum : " << maxRowSum(matrix,4,3) << endl;

    cout << "The maximum column sum : " << maxColumnSum(matrix,4,3) << endl;

    return 0;
}