// Return pair in sorted array whose sum is equal to target
// Time complexity : O(n^2)

#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> nums,int target){

    vector<int> ans;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if(nums[i]+nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
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

    cout << "The pair of elements whose sum is equal " << target << " are  : ";
    cout << "( " << vec[ans[0]] << " , " << vec[ans[1]] << " ) " << " at index : " << "( " << ans[0] << " , " << ans[1] << " ) " << endl;

    return 0;

}

// Output :
// Enter the number of elements : 6
// Enter 6 Values : 1 2 3 4 5 6 
// Enter the target (which is equal to sum of two elements in sorted array) to find : 7
// The pair of elements whose sum is equal 7 are  : ( 1 , 6 )  at index : ( 0 , 5 ) 