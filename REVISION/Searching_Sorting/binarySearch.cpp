#include<iostream>
using namespace std;

void printArray(int nums[],int size){
    for(int i = 0;i < size ; i++){
        cout << nums[i] << " ";
    }
}
int binarySearchRev(int arr[],int left ,int right,int target){
    while(left <= right){
        int mid = left + (right - left)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid]<target){
            left=mid +1;
        }
        else{
        right=mid-1;
        } 
    }
    return -1;//target element not found in the given array
}


int main(){
    int n ;
        cout << "Enter the size of the array: " <<endl;

    cin >>n ;
    int input[100];
    cout << "Enter the element to array in ascending order: " <<endl;
    
    for (int i=0; i<n;i++){
        cin >>input[i];
    }
    int target;
    cout << "Enter the element to search: " <<endl;
    cin >> target;
    int left =0;
    int right= n-1;

    int index = binarySearchRev(input, 0, n - 1, target);
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    cout << "Array elements: ";
        printArray(input, n);
return 0;
}