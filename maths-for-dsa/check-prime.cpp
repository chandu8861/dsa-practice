#include<iostream>
#include<string>
using namespace std;

string isPrime(int n){

    if (n <= 1) return "NOT PRIME";
    for (int i = 2; i*i <= n; i++){
        if (n%i == 0) return "NOT PRIME";
    }

    return "PRIME";
}

int main (){

    int n;
    cout << "Enter an integer (greater than 1) : ";
    cin >> n;
    cout << "Enter integer " << n << " is " << isPrime(n) << endl;
    return 0;
}

// Enter an integer (greater than 1) : 5
// Enter integer 5 is PRIME

// Enter an integer (greater than 1) : 10
// Enter integer 10 is NOT PRIME

// Enter an integer (greater than 1) : -1
// Enter integer -1 is NOT PRIME

// nter an integer (greater than 1) : 1
// Enter integer 1 is NOT PRIME