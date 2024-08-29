#include<iostream>
using namespace std;
int binarySearch(int arr[],int size,int target){
    int start = 0; int end = size-1;
    while(start <= end){
    int mid= start+(end-size)/2;
        if(arr[mid]==target){
                return mid;
        }else if(arr[mid]>target){ 
            end = mid-1;
        }else{
            start = mid+1;
        }       
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    int input[100];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    int value;
    cin >> value;

    cout << binarySearch(input,n,value) << endl;
}