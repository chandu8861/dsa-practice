// Priority Queue : Here the largest value is given more priority.
// It's basically a binary tree and the values are stored as ascending or descending order

#include<iostream>
#include<queue>
using namespace std;

int main(){

    // MAXHEAP : The topmost element is greater (descending order)

    priority_queue<int> p;
    p.push(5);
    p.push(3);
    p.push(10);
    p.push(4);

    while (!p.empty()){
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;
    // 10 5 4 3 

    // MINHEAP : The topmost element is smaller (ascending order)

    priority_queue<int, vector<int> , greater<int>> q;
    q.push(5);
    q.push(12);
    q.push(4);
    q.push(0);
    q.push(10);

    while (!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    // 0 4 5 10 12 

    // Note : push and pop takes O(logn) time, while top takes O(1) time.

    return 0;
}