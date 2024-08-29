#include<iostream>
using namespace std;
 int findSecondLargestNo(int arr[],int n){
    int largest = -100000, SecondLargest = -100000;
    for(int i = 0; i < n;i++){
        if(arr[i] > largest){
            SecondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > SecondLargest && arr[i] != largest){
            SecondLargest = arr[i];
        }
    }
    return SecondLargest;
 }
int main(){
    int n ;
    cin >> n ;
    int arr[100];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int ans = findSecondLargestNo(arr,n);
    cout  << ans;
}