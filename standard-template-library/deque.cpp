// Deque : Double Ended Queue.
// Deque is internally implement using dynamic array.
// Because we are using arrays we can access random memory unlike list.

#include<iostream>
#include<list>
#include<deque>
using namespace std;

int main(){

    // Intialisation of deque :
    // deque<data_type> deque_name;

    deque<int> d = {1,2,3,4,5};

    for (int val : d){
        cout << val << " ";
    }
    cout << endl;
    // 1 2 3 4 5 

    cout << d[0] << endl;
    // 1

    list<int> l = {1,2,3,4,5};

    // cout << l[0] << endl;
    //  error: no match for 'operator[]' (operand types are 'std::__cxx11::list<int>' and 'int')

    d.push_back(100);
    // 1 2 3 4 5 100

    d.push_front(0);
    // 0 1 2 3 4 5 100

    // we can use all functions which are applicable to list and vector to ddeque.

    return 0;
}