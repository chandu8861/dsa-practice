// Implement power (x,n), which calculates x raised to the power n, (i.e, x^n)
// Binary Exponentiation: Efficiently calculates x^n in O(log n) time.
// If exponent is negative, convert x to 1/x and make exponent positive.
// Multiply x to result only when current exponent bit is set (odd).

#include<iostream>
using namespace std;

double expPow(double x,int n){

    int binForm = n; // use int64_t 0r long long binForm
    // We use int64_t (or long long) to safely handle the edge case when n == INT_MIN (-2^31).
    // Negating INT_MIN causes overflow in 32-bit int because +2^31 is out of range for signed int.
    // int64_t ensures the negation and all further calculations are safe.

    double ans = 1; 

    // Corner cases : 

    if (n == 0) return 1.0;
    if (x == 1) return 1.0;
    if (x == 0) return 0.0;
    if (x == -1 && (n%2 == 0)) return 1.0;
    if (x == -1 && (n%2 != 0)) return -1.0;

    // if n is negative integer

    if (n < 0){
        x = (1.0/x);
        binForm = -binForm;
    }

    while (binForm > 0){

        if(binForm % 2 == 1){
            ans *= x;
        }

        x *= x;
        binForm /= 2;

    }

    return ans;
}

int main(){

    double x;
    int n;
    cout << "Enter base number : ";
    cin >> x;
    cout << "Enter exponent number : ";
    cin >> n;

    double result = expPow(x,n);

    cout << x << " raised to the power "<< n << " : " << result << endl;

    return 0;
}