#include <iostream>
#include<climits>
using namespace std;

int main() {
    int n;

    // Read the number of elements in the array
    cin >> n;

    // Declare an array of size n
    int arr[n];

    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Assume the first element is the minimum initially
    int minElement =INT_MAX;

    // Iterate through the array to find the minimum element
    for (int i = 1; i < n; i++) {
        // Update minElement if the current element is smaller
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    // Print the minimum element
    cout <<  minElement << endl;

    return 0;
}
