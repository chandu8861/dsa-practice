#include<iostream>
#include<algorithm>
using namespace std;

// time complexity : O(min(a,b))

int gcd(int a, int b){

    int gcd;

    // edge cases :

    if (a==0 && b==0) return 0;
    if (a==0) return b;
    if (b==0) return a;
    if (a==b) return b;

    for (int i = 1; i <= min(a,b); i++){
        if (a % i == 0 && b % i == 0){
            gcd = i;
        }
    }
    return gcd;
}

// better solution :
// Euclid's algorithm :
// we have to find gcd(a,b) :
// if a > b, gcd(a-b, b)
// if b > a, gcd(a, b-a)

int gcd_1(int a, int b){

    int gcd;

    // edge cases :

    if (a==0 && b==0) return 0;
    if (a==0) return b;
    if (b==0) return a;
    if (a==b) return b;

    while (a > 0 && b > 0){

        if (a == b) return b;

        if (a > b){
            a = a - b;
        }

        if (b > a){
            b = b - a;
        }

        gcd = max(a,b);
    }
    return gcd;
}

// optimised solution : Euclid Algorithm in less steps
// instead of repeated subtraction we can use modular division to get remainder of largest value :

int gcd_2(int a, int b){

    // edge cases :

    if (a==0 && b==0) return 0;
    if (a==0) return b;
    if (b==0) return a;

    while (a > 0 && b > 0){

        if (a > b){
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return (a==0) ? b : a;
}

int main(){

    int a, b;
    cout << "Enter two numbers to find greatest common divisor : ";
    cin >> a >> b;

    cout << "GCD of " << a << " and " << b << " is " << gcd_2(a,b) << endl;

    return 0;
}

// Enter two numbers to find greatest common divisor : 5 10
// GCD of 5 and 10 is 5

// Enter two numbers to find greatest common divisor : 0 21
// GCD of 0 and 21 is 21

// Enter two numbers to find greatest common divisor : 100 0
// GCD of 100 and 0 is 100

// Enter two numbers to find greatest common divisor : 0 0
// GCD of 0 and 0 is 0

// Enter two numbers to find greatest common divisor : 2 3
// GCD of 2 and 3 is 1