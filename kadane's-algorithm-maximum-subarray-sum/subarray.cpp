// TO print all subarrays 
// Time complexity : O(n^3)

#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int start = 0; start < n; start++){
        for (int end = start; end < n; end++){
            for (int i = start; i <= end; i++){
                cout << arr[i];
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}