#include<iostream>
using namespace std;

pair<int, int> linearSearch (int matrix[][3], int rows, int columns, int key){

    for (int i = 0; i < rows; i++){

        for (int j = 0; j < columns; j++){

            if (matrix[i][j] == key){
                return {i,j};
            }
        }
    }

    return {-1,-1};
}

int main (){

    int matrix[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

    pair<int, int> result = linearSearch(matrix,4,3,9);

    if (result.first == -1){
        cout << "Target not found." << endl;
    } else {
        cout << "Target found at cell : " << result.first << "," << result.second << endl;
    }
    // Target found at cell : 2,2
    
    return 0;
}