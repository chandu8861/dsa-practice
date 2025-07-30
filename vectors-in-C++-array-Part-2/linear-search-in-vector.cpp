// Implementation of Linear Search using vector

#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>& nums, int target) {

    // size_t is an unsigned integer type used for sizes and indexing.
    // It ensures compatibility with the size() function which returns size_t.
    
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i;   // return index if found
        }
    }
    return -1;   // return -1 if not found
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> vec(n);

    cout << "Enter " << n << " Values : ";
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int target;
    cout << "Enter the element to find : ";
    cin >> target;

    int result = linearSearch(vec, target);

    if (result == -1) {
        cout << "Element not found." << endl;
    } else {
        cout << "Element found at index : " << result << endl;
    }

    return 0;
}
