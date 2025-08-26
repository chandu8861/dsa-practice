// 2D Array or Matrix :

#include<iostream>
using namespace std;

int main(){

    // Initialisation of 2D array :
    // Syntax : data_type array_name [rows] [columns];

    int matrix[100][200];

    // assigning values :

    int matrix2[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

    cout << matrix2[3][2] << endl; // third row - second element;
    // 12

    matrix2[3][2] = 18;

    cout << matrix2[3][2] << endl;
    // 18

    int matrix3[4][3];
    int rows = 4;
    int columns = 3;

    // Input :

    cout << "Enter the values of Matrix : " << endl;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cin >> matrix3[i][j];
        }
    }

    // Output :

    cout << "Entered Matrix is : " << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << matrix3[i][j] << "\t";
        }
        cout << endl;
    }

    // Entered Matrix is :
    // 1       2       3
    // 4       5       6
    // 7       8       9
    // 10      11      12


    return 0;
}