#include <iostream>
#include <queue>
using namespace std;

// by Default its MAX PQ
int main()
{
    priority_queue<int> pq;

    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);

    cout << "Size: " << pq.size() << endl;
    cout << "Top: " << pq.top() << endl;
    cout << "IsEmpty?: " << pq.empty() << endl;
}