#include<iostream>
using namespace std;

long long int sumOfNumbers(int n){

    if (n == 1){
        return 1;
    }

    return n + sumOfNumbers(n-1);
}

int main(){

    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    cout << "Sum : " << sumOfNumbers(n) << endl;

    return 0;
}

// Enter the value of n : 9999
// Sum : 49995000