#include<iostream>
using namespace std;
void selection_sort(int input[],int n){
    for(int i =0;i< n-1 ; i++){
// i=zero to i < n-1, bcz as per theory we need only n-1 rounds and there are n round in i=0 to i< n 

        //finding the min 
        int min = input[i];
        int minIndex=i;
        for (int j = i+1; j < n; j++){
            if(input[j] < min){
                min=input[j];
                minIndex = j;
            }
        }
        //swap
        int temp= input[i];
        input[i]=input[minIndex];
        input[minIndex]=temp;

    }
}


int main(){
    int input[]={3,1,6,9,0,4};
    selection_sort(input,6);
    for(int i = 0 ;i <6;i++){
        cout << input[i] << " "; 
    }
}