// stack : Last in First out structure (Non - Sequencial structure)
#include<iostream>
#include<stack>
using namespace std;

int main(){

    // Initialisation of stack :
    // stack <data_type> stack_name;

    stack<int> s;

    // push is used to insert element into stack
    s.push(1);
    s.push(2);
    s.push(3);

    // top is used to fench the topmost element :
    cout << s.top() << endl;
    // 3

    cout << s.size() << endl;
    // 3

    // swap is used to swap both size and elements between two stacks.
    
    stack<int> s2;
    s2.swap(s);

    cout << s2.size() << endl;
    // 3
    cout << s.size() << endl;
    // 0

    while (!s2.empty()){
        cout << s2.top() << " ";
        s2.pop(); // removes topmost element
    }
    cout << endl;
    // 3 2 1 

    return 0;
}