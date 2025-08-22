// Reverse Words in a String

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. 
// The returned string should only have a single space separating the words. Do not include any extra spaces.

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string reverseWords(string s){

    int n = s.size();

    // Reverse entire string :
    reverse(s.begin(), s.end());

    string sentence = "";

    // Reverse individual words :
    for (int i = 0; i < n; i++){
        string word = "";

        // separate each word from string : 
        while (i < n && s[i] != ' '){
            word += s[i];
            i++;
        }

        // reverse the separated word :
        reverse(word.begin(), word.end());

        // add space after each word :
        if (word.length() > 0){
            sentence += " " + word;
        }
    }

    // return string with reverse ordered of words and remove first space by passing string for index 1 :
    return sentence.substr(1);
}

int main(){

    string str;
    cout << "Enter the string : ";
    getline(cin, str);

    cout << "String after reversing the order of words : " << reverseWords(str) << endl;

    return 0;
}

// Enter the string : My name is Chandu
// String after reversing the order of words : Chandu is name My