// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n^2]. 
// Each integer appears exactly once except a which appears twice and b which is missing. 
// The task is to find the repeating and missing numbers a and b.

// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

vector<int> findMissingAndRepeatingValues (vector<vector<int>>& grid){

    vector<int> ans;
    int n = grid.size();
    unordered_set<int> s;
    int a,b;

    int actualSum = 0, expectedSum = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            actualSum += grid[i][j];

            // to find repeating value :
            if (s.find(grid[i][j]) != s.end()){
                a = grid[i][j];
                ans.push_back(a);
            }

            s.insert(grid[i][j]);
        }
    }

    expectedSum = (n*n) * (n*n + 1)/2;
    b = expectedSum + a - actualSum;
    ans.push_back(b);

    return ans;
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