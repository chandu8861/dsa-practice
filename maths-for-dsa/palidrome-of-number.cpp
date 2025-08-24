// Palindrome Number  
// Given an integer x, return true if x is a palindrome, and false otherwise.

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome (int n){

    string num = to_string(n);
    string copy_n = num;
    reverse(copy_n.begin(), copy_n.end());

    if (n < 0) return false;

    return num == copy_n;
}

int main(){

    int num;
    cout << "Enter a positive integer : ";
    cin >> num;

    cout << "Given number " << num << (isPalindrome(num) ? " is Palindrome" : " is not Palindrome") << endl;
    
    return 0;
}

// Enter a positive integer : 535
// Given number 535 is Palindrome

// Enter a positive integer : 15324
// Given number 15324 is not Palindrome