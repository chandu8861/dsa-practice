#include<iostream>
using namespace std;

// for any problem related to extract individual digits from given number(base 10).
// first we find the reminder of the number using modular division to get last number.
// next we divide by 10 to remove unit place and repeat the process until number becomes 0.
// in between the loop we can add, count, print individual digits of number.

// Time Complexity will be log(n) (base 10) due to n%10.
// it can vary depending on which number we are using to do modular division like log(n) (base 2),log(n) (base 3),...etc

// function to print digits in number :

void printDigits(int n){

    int dig = 0;

    while (n > 0){
        dig = n % 10;
        cout << dig << " ";
        n = n / 10;
    }
    cout << endl;

}

// function to count digits in number :

void countDigits(int n){

    int dig = 0, count  = 0;

    while (n > 0){
        dig = n % 10;
        count++;
        n = n / 10;
    }

    cout << count << endl;
}

// function to sum of digits in number :

void sumofDigits(int n){

    int dig = 0, sum = 0;

    while (n > 0){
        dig = n % 10;
        sum += dig;
        n = n / 10;
    }

    cout << sum << endl;
}

int main() {

    int n = 123456;

    printDigits(n);
    // 6 5 4 3 2 1 

    countDigits(n);
    // 6

    sumofDigits(n);
    // 6
    
    return 0;
}