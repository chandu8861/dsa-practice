// Remove All Occurrences of a Substring

// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.
// A substring is a contiguous sequence of characters in a string

#include<iostream>
#include<string>
using namespace std;

string removeOccurrences (string s, string part){
    
    while (s.find(part) < s.length()){

        int start = s.find(part), end = part.length();

        s.erase(start, end);
    }

    return s;
}

int main() {

    string str, part;

    cout << "Enter a string (with occurances) : ";
    getline(cin, str);
    cout << "Enter a substring that you want to remove : ";
    getline(cin, part);

    cout << "String : " << removeOccurrences(str,part) << endl;

    return 0;
}

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.length() > 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};