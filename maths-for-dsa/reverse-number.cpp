// Reverse integer 

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

#include<iostream>
#include<climits>
using namespace std;

int reverseInteger (int n){

    int reverse_number = 0;

    while (n != 0){
        int dig = n % 10;
        n = n / 10;

        // Check for overflow before multiplying
        if (reverse_number > INT_MAX / 10 || reverse_number == INT_MAX / 10 && dig > 7) return 0;
        if (reverse_number < INT_MIN / 10 || reverse_number == INT_MIN / 10 && dig < -8) return 0;

        reverse_number = (reverse_number * 10) + dig;
    }

    return reverse_number;
}

int main(){

    int num;
    cout << "Enter a number : ";
    cin >> num;

    cout << "Reverse of " << num << " is " << reverseInteger(num) << endl;

    return 0;
}

// Enter a number : 123456
// Reverse of 123456 is 654321