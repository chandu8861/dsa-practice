#include<iostream>
using namespace std;

long long int Factorial (int n){
    if (n == 0){
        return 1;
    }
    return n * Factorial(n-1);
}

int main(){
    int n;
    cout << "Enter the number to find its factorial (n < 20) : ";
    cin >> n;

    cout << "Factorial : " << Factorial(n) << endl;
    return 0;
}

// Enter the number to find its factorial (n < 20) : 20
// Factorial : 2432902008176640000