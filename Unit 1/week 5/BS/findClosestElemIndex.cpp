#include<iostream>
using namespace std;




int binarySearchClosest(int nums[], int left, int right, int target) {
    
    int closestIndex = -1;
    int closestDifference = 1000000;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int currentDifference = abs(nums[mid] - target);

        if (currentDifference < closestDifference || (currentDifference == closestDifference && nums[mid] < nums[closestIndex])) {
            closestDifference = currentDifference;
            closestIndex = mid;
        }

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return closestIndex;
}

int main() {
    int n;
    cout <<"Enter size : ";
    cin>>n;
    int arr[100];
    cout <<"Enter the Array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int left = 0;
    int right =n-1;
    int target;
    cout <<"Enter Target:  ";
    cin>>target;
    int ans = binarySearchClosest(arr, 0, n-1, target);
    cout<< "the closest index  to  target is "<<ans;
    return 0;
}