// Pair : used to store two different datatypes.
// it comes under C+6 utility module

#include<iostream>
#include<vector>
using namespace std;

int main(){

    // Intialisation of pair :
    // Syntax : pair <datatype1, datatype2> pair_name;

    pair<int, int> p = {1, 2};
    pair<char, int> p2 = {'a', 10};

    cout << p.first << endl; // 1
    cout << p.second << endl; // 2
    cout << p2.first << endl; // a
    cout << p2.second << endl; // 10

    pair < int , pair < char , string > > p3 = { 34 , { 'z' , "Hello" }};

    cout << p3.first << endl; // 34
    cout << p3.second.first << endl; // z
    cout << p3.second.second << endl; // Hello

    // Pair-in-Vector :

    vector<pair<int,int>> vec = {{1,2},{3,4},{5,6}};
    
    for (pair<int,int> val : vec){
        cout << val.first << " " << val.second << endl;
    }
    // 1 2
    // 3 4
    // 5 6

    for (auto val : vec){
        cout << val.first << " " << val.second << endl;
    }
    // 1 2
    // 3 4
    // 5 6

    // for pairs, when we do push back, we create a pair and it just inserts it.
    vec.push_back({2,4}); 
    // 2 4

    // using emplace_back, we don't need to create pair, we just need to pass the values/
    vec.emplace_back(2,4);
    // 2 4
}