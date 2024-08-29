#include <iostream>
using namespace std;

int partion(int a[], int si, int ei)
{
    int count_smalller_elements = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (a[i] <= a[si])
        {
            count_smalller_elements++;
        }
    }

    int temp = a[si + count_smalller_elements];
    a[si + count_smalller_elements] = a[si];
    a[si] = temp; // pivot element ko shi jgh rkha

    int partionIndex = si + count_smalller_elements;
    int x = a[partionIndex];

    int i = si;
    int j = ei;

    while (i < partionIndex && j > partionIndex)
    {
        if (a[i] <= x)
        {
            i++;
        }
        else if (a[j] > x)
        {
            j--;
        }
        else
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    return partionIndex;
}

void quick_sort(int a[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int partitionIndex = partion(a, si, ei);
    quick_sort(a, si, partitionIndex - 1);
    quick_sort(a, partitionIndex + 1, ei);
}

int main()
{
    int a[] = {5, 2, 7, 8, 1, 3, 9};
    quick_sort(a, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << endl;
    }
}