// Queue : First in - First out structure.
#include<iostream>
#include<queue>
using namespace std;

int main(){

    // Initialisation of Queue :
    queue<int> q;

    // push is used to insert element into queue
    q.push(1);
    q.push(2);
    q.push(3);

    // front is used to fench the first element in queue :
    cout << q.front() << endl;
    // 1

    cout << q.size() << endl;
    // 3

    // swap is used to swap both size and elements between two queues.
    
    queue<int> q2;
    q2.swap(q);

    cout << q2.size() << endl;
    // 3
    cout << q.size() << endl;
    // 0

    while (!q2.empty()){
        cout << q2.front() << " ";
        q2.pop(); // removes first element
    }
    cout << endl;
    // 1 2 3

    return 0;
    
}