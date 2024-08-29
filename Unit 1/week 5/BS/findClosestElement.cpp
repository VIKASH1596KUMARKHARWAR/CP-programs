#include <bits/stdc++.h>
using namespace std;

// Function to get the closest value between two given values
int getClosest(int val1, int val2, int target) {
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}

// Function to find the closest element to the target in the array
int findClosest(int arr[], int n, int target) {
    // Handle edge cases
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];

    // Binary search to find the closest element
    int i = 0, j = n - 1, mid;
    while (i <= j) {
        mid = (i + j) / 2;

        // If the target is exactly at mid
        if (arr[mid] == target)
            return arr[mid];

        // If target is less than array element, search in the left half
        if (target < arr[mid]) {
            // If target is greater than the previous element, find the closest
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(arr[mid - 1], arr[mid], target);
            j = mid - 1;
        }
        // If target is greater than the mid element, search in the right half
        else {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(arr[mid], arr[mid + 1], target);
            i = mid + 1;
        }
    }

    // If we reach here, then target is the closest to arr[mid]
    return arr[mid];
}

// Driver code
int main() {
    int arr[] = { 1, 2, 4, 5, 6, 6, 8, 8, 9,12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 11;
    cout << findClosest(arr, n, target);
    return 0;
}
