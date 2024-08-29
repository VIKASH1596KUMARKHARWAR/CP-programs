#include <iostream>
using namespace std;

void printArray(int input[], int n) {
    for (int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {  // Corrected condition
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int kthSmallest(int arr[], int n, int k) {
    // Sort the array using bubble sort
    bubbleSort(arr, n);

    // Return the k-th smallest element
    return arr[k - 1];
}

int main() {
    int n;
    cin >> n;
    int input[100];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int k;
    cout << "element the k to find the kth smallest element:  ";
    cin >> k;
    
    int kth_smallest = kthSmallest(input, n, k);
    cout << "Sorted array: ";
    printArray(input, n);
    cout << "The " << k << "-th smallest element is: " << kth_smallest << endl;

    return 0;
}
