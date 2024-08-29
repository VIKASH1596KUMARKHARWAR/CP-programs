#include <iostream>
using namespace std;

// Merge function: merges two sorted halves of array a[]
void merge(int a[], int si, int ei)
{
    int mid = (si + ei) / 2; // Calculate mid index

    int *temp = new int[ei - si + 1]; // Temporary array to store merged result
    int i = si;                       // Starting index of left subarray
    int j = mid + 1;                  // Starting index of right subarray
    int k = 0;                        // Index for temp array

    // Merge two halves into temp array
    while (i <= mid && j <= ei)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++]; // Place smaller element from left subarray
        }
        else
        {
            temp[k++] = a[j++]; // Place smaller element from right subarray
        }
    }

    // Copy remaining elements of left subarray to temp array
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }

    // Copy remaining elements of right subarray to temp array
    while (j <= ei)
    {
        temp[k++] = a[j++];
    }

    // Copy sorted elements from temp array back to original array a[]
    int m = 0;
    while (m < k)
    {
        a[si + m] = temp[m];
        m++;
    }

    delete[] temp; // Free the dynamically allocated memory
}

// Merge sort function: recursively divides the array into halves and sorts them
void merge_sort(int input[], int si, int ei)
{
    if (si >= ei)
        return; // Base case: return if single element or invalid segment

    int midIndex = (si + ei) / 2; // Calculate mid index

    // Recursively sort left half
    merge_sort(input, si, midIndex);
    // Recursively sort right half
    merge_sort(input, midIndex + 1, ei);
    // Merge sorted halves
    merge(input, si, ei);
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(arr, 0, 9); // Call merge_sort with array and initial indices

    // Print sorted array
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
