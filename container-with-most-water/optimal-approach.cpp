// Container with most water
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the X axis forms a container such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// Optimal approach - 2 Pointer Approach.

#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height){

    // Here left and right are the pointer (start and end)
    int left = 0, right = height.size()-1, maxWater = 0;

    while (left < right){

        int Height = min(height[left], height[right]);
        int width = right - left;
        maxWater = max(maxWater, width*Height);

        height[left] < height[right] ? left++ : right--;

    }

    return maxWater;
}

int main(){

    int n;
    cout << "Enter the number of vertical lines (length of the array): ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the height of each vertical line separated by space:\n";
    for (int i = 0; i < height.size(); i++){
        cout << "Height of line at position " << i << ": ";
        cin >> height[i];
    }

    cout << "Container with Maximum area to store water : " << maxArea(height) << endl;

    return 0;
}

// Enter the number of vertical lines (length of the array): 9
// Enter the height of each vertical line separated by space:
// Height of line at position 0: 1
// Height of line at position 1: 8
// Height of line at position 2: 6
// Height of line at position 3: 2
// Height of line at position 4: 5
// Height of line at position 5: 4
// Height of line at position 6: 8
// Height of line at position 7: 3
// Height of line at position 8: 7
// Container with Maximum area to store water : 49