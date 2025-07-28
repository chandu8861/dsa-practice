// Find Smallest and Largest in an Array
#include <iostream> 
#include <climits> // For INT_MAX and INT_MIN
#include <algorithm> // For std::max and std::min
using namespace std;

int main() {
    int size = 6;
    int nums[size] = {21,1,3,-12,-25,100};

    //Smallest Nmber :

    int smallest = INT_MAX; // Initialize to maximum possible integer : INT_MAX = +oo

    for (int i = 0; i < size; i++) {
        if (nums[i] < smallest) {
            smallest = nums[i];
        }

        //OR
        //smallest = min(smallest, nums[i]);
    }

    //Largest Number :

    int largest = INT_MIN; // Initialize to minimum possible integer : INT_MIN = -oo

    for (int i = 0; i < size; i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }

        //OR
        //largest = max(largest, nums[i]);
    }

    cout << "Smallest Number: " << smallest << endl;
    cout << "Largest Number: " << largest << endl;

    return 0;
}

// Output:
// Smallest Number: -25
// Largest Number: 100    