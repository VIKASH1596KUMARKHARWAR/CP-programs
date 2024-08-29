#include<iostream>
using namespace std;

void insertion_Sort(int arr[], int n){
    for(int i =1;i<n;i++){
        int current = arr[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(current < arr[j]){
                arr[j+1]=arr[j];
            }else{
                break;
            }
        }
        arr[j+1]=current;
        //here j=-1 hone k baad aaya h aur ek jo different case tha wo bhi handel ho rha..by replacing it by its own value at its own place
    }
}

void printArray(int input[],int n ){
    for(int i =0;i<n;i++){
        cout << input[i] <<" ";
    }
    cout<< endl;
}

int main(){
    int n ;
    cin>>n;
    int input[100];
    for(int i = 0;i <n;i++){
        cin >> input[i];
    }
    insertion_Sort(input,n);
    printArray(input,n);
}   