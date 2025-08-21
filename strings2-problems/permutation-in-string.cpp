// permuatation in string :

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

// Constraints:
// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isFrequencySame (int frequency1[], int frequency2[]){

    for (int i = 0; i < 26; i++){

        if (frequency1[i] != frequency2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2){

    int frequency[26] = {0}; // Initialising all indices (alhpabets) with 0;

    for (int i = 0; i < s1.length(); i++){

        frequency[s1[i] - 'a']++; // when we subtract any lower case with a will we get its index
    }

    int window_size = s1.length();
    
    for (int i = 0; i < s2.length(); i++){

        int window_index = 0, index = i;
        int window_frequency[26] = {0};

        // sliding window :
        while (window_index < window_size && index < s2.length()){

            window_frequency[s2[index] - 'a']++;
            index++;
            window_index++;

            if (isFrequencySame(window_frequency , frequency)){
                return true;
            }
        }
    }
    return false;
}

int main(){

    string s1;
    string s2;

    cout << "Enter the substring whose permutation you want to find in the mainstring : ";
    cin >> s1;

    cout << "Enter the mainstring : ";
    cin >> s2;

    cout << (checkInclusion (s1, s2) ? "true" : "false") << endl;

    return 0;
}

// Enter the substring whose permutation you want to find in the mainstring : ab
// Enter the mainstring : eidbaooo
// true

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> count1(26,0), count2(26,0);

        for (int i = 0; i < s1.size(); i++){
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        for (int i = 0; i <= s2.size() - s1.size(); i++){

            if (count1 == count2) return true;

            if (i + s1.size() < s2.size()){
                count2[s2[i] - 'a']--;
                count2[s2[i + s1.size()] - 'a']++;
            }
        }
        return false;
    }
};