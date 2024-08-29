
#include<iostream>
using namespace std;
int main(){
    int *p = new int;
    *p = 10;
    cout << *p;

cout << "DYNAMIC ALLOCATION OF ARRAYS "<<  endl;

    int* pa =   new int[50];//yeh to hamara hamesha shi hain...constant size ka array

    int n; 
    cout<<"enter the size of the array: "<<endl;
    cin >> n ;
    int *pa2 = new int[n];
    pa2[0]=10; 
    cout << pa2[0]; 

}