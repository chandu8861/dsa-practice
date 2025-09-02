// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, 
// such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.

// Given n, calculate F(n).

// Recursion : Time Complexity : O(2^n) and space Complexity : O(n)

#include<iostream>
using namespace std;

long long Fibonacci (int n){

    if (n == 0 || n == 1){
        return n;
    }

    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main(){
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    cout << "Fibonacci Number : " << Fibonacci(n) << endl;

    return 0;
}

// Enter the value of n : 8
// Fibonacci Number : 21