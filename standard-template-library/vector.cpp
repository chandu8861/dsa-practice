#include<iostream>
#include<vector>
using namespace std;

// Iterators : These are similar to pointers which point to the memory address of an element
// Types :
// vec.begin() : points to the address of starting element.
// vec.end() : points to nth index (usually contains soe garbage value or 0).
// vec.rbegin() [Reverse begin] : Used to backward loops.
// vec.rend() [Reverse end].

int main() {

    vector<int> vec = {1,2,3,4,5};
    cout << *(vec.begin()) << endl;
    // returns the value : 1
    cout << *(vec.end()) << endl;
    // 17432768 : some garbage value
    cout << *(vec.rbegin()) << endl;
    // 5
    cout << *(vec.rend()) << endl;
    // 201388393

    // Initialisation of iterators

    // Syntax : vector<data_type> :: iterator iterator_name;

    vector<int> :: iterator itr;
    for (itr = vec.begin(); itr != vec.end(); itr++){
        cout << *(itr) << " ";
    }
    cout << endl;
    // 1 2 3 4 5

    vector<int> :: reverse_iterator itr1;
    for (itr1 = vec.rbegin(); itr1 != vec.rend(); itr1++){
        cout << *(itr1) << " ";
    }
    cout << endl;
    // 5 4 3 2 1

    // for (vector<int> :: iterator itr = vec.begin(); itr != vec.end(); itr++){
    //     cout << *(itr) << " ";
    // }
    // cout << endl;

    // In Modern C++ : we use "auto" which will automatically identity which type of variable we are using.
    for (auto itr3 = vec.begin(); itr3 != vec.end(); itr3++){
        cout << *(itr3) << " ";
    }
    cout << endl;
    // 1 2 3 4 5

    // Vector functions :
    // erase : used to erase a particular value using iterator.
    vec.erase(vec.begin());
    // 2 3 4 5
    vec.erase(vec.begin() + 1, vec.begin() + 3);
    // 2 5
    // In vec.erase (start, end) => start is included but end is not included.

    // insert : used to insert a particular value using iterator.
    // Syntax : vec.insert( position , value)
    vec.insert(vec.begin()+1, 100);
    // 2 100 5

    // clear : used to delete all elements but capacity remains same.
    vec.clear();
    cout << vec.size() << endl; // 0
    cout << vec.capacity() << endl; // 5

    // empty : used to check whether the vector is empty.
    // if empty return => 1
    // else return => 0
    cout << vec.empty() << endl;
    // 1 => True

    return 0;
}