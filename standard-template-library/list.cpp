// List : doubly linked list - means we can do operations from both front and back

#include<iostream>
#include<list>
using namespace std;

int main(){

    // Intialisation of List :
    // Syntax : list<data_type> list_name;
    list<int> l = {1,2,3,4,5};

    for (int val : l){
        cout << val << " ";
    }
    cout << endl;
    // 1 2 3 4 5 

    // But you cannot access random memory in list :
     // cout << l[2] << endl;
    // no match for 'operator[]' (operand types are 'std::__cxx11::list<int>' and 'int')

    list<int> List;

    // push_back() : used to push elements at the end of list.
    List.push_back(5); // 5
    List.push_back(6); // 5 6

    // push_front() : used to push element at the starting of list.
    List.push_front(3); // 3 5 6
    List.push_front(1); // 1 3 5 6

    // pop_back() : used to remove last element.
    List.pop_back(); // 1 3 5

    // pop_front() : used to remove first element.
    List.pop_front(); // 3 5

    // Just like in vector, we can use size, front, back, erase, begin, rbegin, end, rend, clear, insert in LIST.

    return 0;
}