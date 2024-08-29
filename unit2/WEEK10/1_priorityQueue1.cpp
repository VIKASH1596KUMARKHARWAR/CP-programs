#include <iostream>
#include <climits>
using namespace std;

#include "priorityQueue1.h"

int main()
{
    PriorityQueue pq;

    pq.insert(5);
    pq.insert(1);
    pq.insert(3);
    pq.insert(34);
    pq.insert(35);
    pq.insert(13);

    while (!pq.isEmpty())
    {
        cout << pq.removeMin() << " ";
    }

    int choice;
    cin >> choice;

    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // insert
            int element;
            cin >> element;
            pq.insert(element);
            break;
        case 2: // getMin
            cout << pq.getMin() << "\n";
            break;
        case 3: // removeMax
            cout << pq.removeMin() << "\n";
            break;
        case 4: // size
            cout << pq.getSize() << "\n";
            break;
        case 5: // isEmpty
            cout << (pq.isEmpty() ? "true\n" : "false\n");
        default:
            return 0;
        }

        cin >> choice;
    }
}