// Basic Functions in vector include :
// size(), push_back(), pop_back(), front(), back(), at()

#include<iostream>
#include<vector>
using namespace std;

int main(){

    // size function : it is used to fench the size of vector

    vector<int> vec;
    cout << vec.size() << endl;
    // 0

    vector<char> vec1 = {'a','b','c','d','e','f'};
    cout << vec1.size() << endl;
    // 6

    // push_back function : It is used to push a value to vector at last index

    vector<int> vec2 = {1,2,3,4,5};
    vec2.push_back(6);
    vec2.push_back(7);

    for (int val : vec2){
        cout << val << " ";
    }
    cout << endl;
    // 1 2 3 4 5 6 7

    // pop_back function : It is used to pop (delete) the value at the last index of the vector

    vec2.pop_back();
    vec2.pop_back();

    for (int val : vec2){
        cout << val << " ";
    }
    cout << endl;
    // 1 2 3 4 5

    // front function : It is used to get the first element in the vector
    cout << vec2.front() << endl;
    // 1

    // back function : It is used to get the last element int he vector
    cout << vec2.back() << endl;
    // 5

    // at function : It is used to get the value at a particular index
    // same as vector_name[index]

    cout << vec2.at(1) << endl;
}