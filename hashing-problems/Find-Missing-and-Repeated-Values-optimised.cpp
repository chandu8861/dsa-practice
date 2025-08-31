// Mathematical Logic :
// actualSum = expectSum + a - b => a - b = diff1;
// actualSquareSum = expectedSquareSum + a^2 - b^a => a^2 - b^2 = diff2;
// a + b = diff2 / diff1;
// a = (diff2 / diff1 + diff1) / 2;
// b = a - diff1;

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

vector<int> findMissingAndRepeatingValues (vector<vector<int>>& grid){

    int n = grid.size();
    long long N = 1LL * n * n, actualSum = 0, actualSquareSum = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            actualSum += grid[i][j];
            actualSquareSum += 1LL * grid[i][j] * grid[i][j];
        }
    }

    long long expectedSum = 1LL * N * (N+1) / 2, expectSquareSum = 1LL * N * (N+1) * (2*N+1) / 6;
    long long diff1 = actualSum - expectedSum;
    long long diff2 = actualSquareSum - expectSquareSum;

    int a = (diff2 / diff1 + diff1) / 2;
    int b = a - diff1;

    return {a,b};
}

int main(){

    vector<vector<int>> matrix = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> result = findMissingAndRepeatingValues(matrix);
    cout << "Missing value : " << result[1] << endl;
    cout << "Repeating value : " << result[0] << endl;

    return 0;
}

// Missing value : 5
// Repeating value : 9