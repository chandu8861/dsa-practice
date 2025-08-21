// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
// it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

#include<iostream>
#include<string>
using namespace std;

// It's given that the characters in string should be only alphanumberic i,e the characters must lie between :
// 0-9 , a-z, A-Z;
bool isAlphaNumeric (char ch){

    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
        return true;
    }

    return false;
}

bool isPalindrome (string str){

    int start = 0, end = str.size()-1;

    while (start < end){

        // Skip non-alphanumeric characters
        if ( !isAlphaNumeric ( str[start] ) ) {
            start++; continue;
        }

        if ( !isAlphaNumeric ( str[end] ) ) {
            end--; continue;
        }

        if ( tolower(str[start]) != tolower(str[end]) ) return false;
        start++;
        end--;
    }

    return true;
}

int main (){

    string str;

    cout << "Enter a string to check whether it is palindrome or not : ";
    getline(cin , str);

    cout << (isPalindrome(str) ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}

// Enter a string to check whether it is palindrome or not : "A man, a plan, a canal: Panama"
// Palindrome

// Enter a string to check whether it is palindrome or not : "race a car"
// Not Palindrome

// Enter a string to check whether it is palindrome or not : ""
// Palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
        while(start < end){
            if (!isalnum(s[start])) {start++;continue;}
            if (!isalnum(s[end])) {end--;continue;}
            if (tolower(s[start]) != tolower(s[end])) return false;
            start++;
            end--;
        }
        return true;
    }
};