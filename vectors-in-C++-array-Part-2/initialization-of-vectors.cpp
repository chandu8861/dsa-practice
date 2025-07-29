// Initialisation of the vectors 
// Vectors are similar to array but here size is not declared
// vectors work of Dynamic Storage

#include<iostream>
#include<vector>
using namespace std;

int main(){

    //Initialisation : Syntax : vector<data_type> vector_name;

    vector<int> vec;

    // Initially it's size would be zero
    // If we try to access any element we will get segmentation error
    // Because we are trying to access the stroage that has not yet established

    vector<int> vec1 = {1,2,3,4,5};
    cout << vec1[0] << endl; // 1

    vector<int> vec2(3,2); // Syntax : vector<int> vector_name(size_of_vector,value_at_all_index)
    cout << vec2[0] << endl; 
    cout << vec2[1] << endl;
    cout << vec2[2] << endl;
    // 2
    // 2
    // 2

    vector<char> vec3 = {'a','b','c','d','e'};

    // for each loop :

    for ( char val : vec3){  // Syntax : for ( data_type variable_name : vector_name)

        // here val is a variable that points out to the value at an index not the index itself 
        // Like our regular for loop

        cout << val << endl;

    }

    // a
    // b
    // c
    // d
    // e

    return 0;
}