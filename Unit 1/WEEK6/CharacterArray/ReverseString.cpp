#include<iostream>
using namespace std;
int length( char arr[]){
    int count =0;
    for (int i = 0;arr[i] !=0;i++ ){
        count++;
    }
    return count ;
  }

 void  reverseString(char arr[]){
    int len  = length(arr);
    int i =0,j = len-1;
    while( i < j){
        int temp= arr[i] ;
        arr[i] =arr[j];
        arr[j] = temp;
        i++;
        j--;
    }   
 }
  
int main(){
    char input[100];
    cin.getline(input,100);
    reverseString(input);
    cout << input ;
}