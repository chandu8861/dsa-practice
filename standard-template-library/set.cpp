// Set : Contains unique elements in sorted order

#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

int main() {

    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    for (int val : s){
        cout << val << " ";
    }
    cout << endl;
    // 1 2 3 4 5 

    s.insert(4);
    s.insert(5);

    // Duplicate elements are not repeated 
    cout << s.size() << endl;
    // 5
    for (int val : s){
        cout << val << " ";
    }
    cout << endl;
    // 1 2 3 4 5 

    cout << *(s.lower_bound(4)) << endl; // 4 : returns the value which is not less than key.
    cout << *(s.upper_bound(4)) << endl; // 5 : returns the value just greater than key.

    // s.upper_bound(5) and s.upper_bound(6) both return s.end() (since no element > 5 exists).
    // s.end() is an iterator that points one past the last element in memory layout.
    // In MSVC’s std::set implementation, that past-the-end iterator often still internally holds a pointer into the tree structure where the last node (5) is stored.
    // When you dereference it (*s.end()), instead of crashing, it ends up returning that “last element” value (5).

    // cout << *(s.upper_bound(5)) << endl; // 5
    // cout << *(s.upper_bound(6)) << endl; // 5
    
    cout << *(s.upper_bound(0)) << endl; // 1
    cout << *(s.lower_bound(0)) << endl; // 1

    multiset<int> s2;
    // allows for duplication of elements
    s2.insert(1);
    s2.insert(1);
    s2.insert(1);
    s2.insert(1);
    s2.insert(1);

    for (int val : s2){
        cout << val << " ";
    }
    cout << endl;
    // 1 1 1 1 1

    unordered_multiset<int> s3;
    // random arrangement
    s3.insert(2);
    s3.insert(4);
    s3.insert(2);
    s3.insert(5);
    s3.insert(10);

    for (int val : s3){
        cout << val << " ";
    }
    cout << endl;
    // 10 2 2 4 5 

    return 0;
}