#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void reverseString (vector<char>& str){

    int start = 0, end = str.size()-1;
    
    while (start < end){

        swap(str[start++], str[end--]);
    }
}

int main(){

    vector<char> str = {'C','h','a','n','d','u'};
    reverseString(str);

    for (char ch : str){
        cout << ch ;
    }
    cout << endl;
    // udnahC

    string str2 = "Chandu S";
    reverse(str2.begin(), str2.end());
    cout << str2 << endl;
    // S udnahC

    return 0;
}