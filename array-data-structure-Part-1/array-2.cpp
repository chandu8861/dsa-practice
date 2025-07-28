#include<iostream>
using namespace std;

int main(){

    int size = 5; // size of the array
    int marks[size]; // declaration of array containing five elements

    cout << "Input marks for " << size << " students:" << endl;
    // input marks for each element of the array

    for (int i=0; i<size; i++){
        cout << "Enter the marks of student " << i+1 << " : ";
        cin >> marks[i]; // input marks for each element
    }

    cout<< "\nMarks of Students are :" << endl;
    // output marks for each element of the array

    for (int i=0; i<size; i++){
        cout << "Marks of Student " << i+1 << " : " << marks[i] << endl; // output marks for each element
    }

    return 0;
}

// This code takes input for the marks of 5 students and then outputs those marks.
// It uses an array to store the marks and loops to input and output the values.

// Example input and output:

// Input marks for 5 students:
// Enter the marks of student 1 : 97
// Enter the marks of student 2 : 100
// Enter the marks of student 3 : 96
// Enter the marks of student 4 : 95
// Enter the marks of student 5 : 94

// Marks of Students are :
// Marks of Student 1 : 97
// Marks of Student 2 : 100
// Marks of Student 3 : 96
// Marks of Student 4 : 95
// Marks of Student 5 : 94
