#include <iostream>
#include <algorithm>
using namespace std;

// Function to partition the array and return the pivot index

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

// Function to count pairs with sum equal to num
int countPairsWithSum(int arr[], int n, int num)
{
    // Sort the array using Quicksort
    quick_sort(arr, 0, n - 1);

    // Initialize pointers
    int left = 0;
    int right = n - 1;
    int countPairs = 0;

    // Two-pointer technique
    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == num)
        {
            // Found a pair
            countPairs++;
            left++;
            right--;
        }
        else if (sum < num)
        {
            // Move left pointer to increase sum
            left++;
        }
        else
        {
            // Move right pointer to decrease sum
            right--;
        }
    }

    return countPairs;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        int num;
        cin >> num;

        int result = countPairsWithSum(arr, n, num);
        cout << result << endl;
    }

    return 0;
}
/*// Function to merge two sorted halves of array
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;     // Size of left subarray
    int n2 = high - mid;        // Size of right subarray

    // Create temporary arrays
    int left[n1], right[n2];

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < n1; ++i)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; ++j)
        right[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[low..high]
    int i = 0;     // Initial index of left subarray
    int j = 0;     // Initial index of right subarray
    int k = low;   // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copy the remaining elements of left[], if any
    while (i < n1) {
        arr[k++] = left[i++];
    }

    // Copy the remaining elements of right[], if any
    while (j < n2) {
        arr[k++] = right[j++];
    }
}

// Function to implement Merge Sort
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;   // Calculate middle index

        // Recursively sort two halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}
*/