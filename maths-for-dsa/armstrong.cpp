#include<iostream>
#include<math.h>
using namespace std;

bool isArmstrong(int n){

    int copy_n = n;
    int dig = 0;
    double armstrong_number = 0;
    int length = to_string(n).length();

    while (n > 0){
        dig = n % 10;
        armstrong_number += round(pow(dig, length));
        n = n / 10;
    }

    return copy_n == armstrong_number;
}

int main(){

    int num;
    cout << "Enter a number to check if it's armstrong or not : ";
    cin >> num;

    if (isArmstrong(num)){
        cout << num << " is armstrong number." << endl;
    } else {
        cout << num << " is not an armstrong number." << endl;
    }

    return 0;
}

// Enter a number to check if it's armstrong or not : 153
// 153 is armstrong number.

// Enter a number to check if it's armstrong or not : 1
// 1 is armstrong number.

// Enter a number to check if it's armstrong or not : 11
// 11 is not an armstrong number.

// Enter a number to check if it's armstrong or not : 9474
// 9474 is armstrong number.