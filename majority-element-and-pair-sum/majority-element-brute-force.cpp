// To find the majority element in vector/array - Brute force approach 
// frequency of the element must be greater than n/2
// Time Complexity  : O(n^2)

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums){

    int n = nums.size();
    
    for (int val : nums){
        int frequency = 0;
        for (int elem : nums){
            if (elem == val){
                frequency++;
            }
        }
        if (frequency > n/2 ){
            return val;
        }
    }
    return -1;
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

    int result = majorityElement(vec);
    if (result == -1){
        cout << "No majority element whose frequency greater than " << n/2 << " appears in the array. " << endl;
    }
    else {
        cout << "Majority element whose frequency greater than " << n/2 << " is : " << result << endl;
    }

    return 0;

}