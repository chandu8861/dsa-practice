// Return pair in sorted array whose sum is equal to target
// Utilising "soretd array" : 2 - pointer approach
// Time complexity : O(n)

#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> nums,int target){

    vector<int> ans;
    int n = nums.size();
    int i = 0, j = n -1;
    while (i < j){   // because if i and j meet at same point we will not get pair.
        int pairSum = nums[i] + nums[j];
        // there can be onlt three conditions :
        if (pairSum < target){
            i++;
        } else if (pairSum > target){
            j--;
        }else { // pairSum == target
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    } 
    return ans;
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
    cout << "Enter the target (which is equal to sum of two elements in sorted array) to find : ";
    cin >> target;

    vector<int> ans = pairSum(vec, target);

    if (!ans.empty()) {
        cout << "The pair of elements whose sum is equal to " << target << " are: ";
        cout << "( " << vec[ans[0]] << " , " << vec[ans[1]] << " ) ";
        cout << "at index : ( " << ans[0] << " , " << ans[1] << " )" << endl;
    } else {
        cout << "No such pair found." << endl;
    }

    return 0;

}

// Enter the number of elements : 6
// Enter 6 Values : 1 4 9 11 15 22
// Enter the target (which is equal to sum of two elements in sorted array) to find : 20
// The pair of elements whose sum is equal to 20 are: ( 9 , 11 ) at index : ( 2 , 3 )