// dec order
// assume an element being at an index i
// K sorted array  means uska hr element aapni jgh se  k-1 position left ya k-1 position right hi keval ja shakta
// ex 10 12 15 6 9 for k =3

#include <iostream>
#include <queue>
using namespace std;

void KSortedArrray(int input[], int n, int k)
{
    priority_queue<int> pq; // by default max pq aata h --> #decreasing order
    // creating heap
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }
    int index = 0;
    // sorted array ke kon se index pe jana h

    for (int i = k; i < n; i++)
    {
        input[index++] = pq.top();
        pq.pop();

        // Insert the current element into the heap
        pq.push(input[i]);
    }

    while (!pq.empty())
    {
        input[index++] = pq.top();
        pq.pop();
    }
}

int main()
{
    int arr[] = {10, 12, 15, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    KSortedArrray(arr, n, k);

    // Print the sorted array in descending order
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
