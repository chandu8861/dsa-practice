// Container with most water
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the X axis forms a container such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// Brute force appoarch with Time Complexity : O(n^2)

#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height){

    int maxArea = 0;

    for (int i = 0; i < height.size(); i++){  // Left Boundary

        for (int j = i+1; j < height.size(); j++){  // Right Boundary

            int Height = min(height[i], height[j]);
            int Width = j - i;
            maxArea = max(maxArea, Height*Width);

        }
    }

    return maxArea;
}

int main(){

    int n;
    cout << "Enter the Length of the array : ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter heights of container side : ";
    for (int i = 0; i < height.size(); i++){
        cin >> height[i];
    }

    cout << "Container with Maximum area : " << maxArea(height) << endl;

    return 0;
}