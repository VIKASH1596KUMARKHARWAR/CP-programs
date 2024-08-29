#include<iostream>
using namespace std;
int binarySearch(int nums[], int left, int right, int target) {
    
      // Write your code !!!!
     while(left<=right){
         int mid = left +(right-left)/2;//mid should always be within the while loop
             if(nums[mid]== target){
                 return mid;
            }
            else if(nums[mid] < target){
                 left = mid+1;
             }
             else
             right= mid-1;
         }
         return -1;//if target not found

    } 
      

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int left = 0;
    int right =n-1;
    int target;
    cin>>target;


    int ans = binarySearch(arr, 0, n-1, target);


    cout<<ans;




    return 0;
}