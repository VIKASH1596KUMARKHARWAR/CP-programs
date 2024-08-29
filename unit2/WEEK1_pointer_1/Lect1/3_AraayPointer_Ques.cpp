//Ques.1 Given an array of length N, you need to find and return the sum of all elements of the array using the concept of pointer arithmetic and pointers.

#include<iostream>
using namespace std;

int sum(int *ar , int n)//int ar[] bhi chlega insted int *ar bcz arrray name itsef is a behaving like pointer 
{
    int summ=0;
    for(int i= 0; i < n;i++){
        summ += *(ar+i); 
    }
    return  summ;
}


int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int ans = sum(ar,n);
    cout<<ans;
}

/*
int sum(int *ar , int n)
{
    int summ=0;
    for(int i= 0; i < n;i++){
        summ +=ar[i];// yeh bhi chalega instead of this *(ar+i) 
    }
    return  summ;
}
*/