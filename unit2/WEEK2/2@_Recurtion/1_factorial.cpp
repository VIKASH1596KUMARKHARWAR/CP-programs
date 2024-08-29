#include<iostream>
using namespace std;

/* int factorial(int n){
    // cout <<n ;
    int smallOutput = factorial(n-1);
    return  n*smallOutput;
 }//segmentation fault bcz infinte loop which drains all the memory to allocate the all n for all the instance fo factorial calls
 */ 


int factorial(int n){
    cout<<n<<endl; //calls
    if(n == 0 ){
         return 1;
         //whenever require for n=0 factorial will be return to 1 :: setting fact(0) as 1 
    }
    int smallOutput = factorial(n-1);
     return n*smallOutput;
}

int main(){
     int n ;
      cin>> n;
       int output = factorial(n);
      cout<<"factorilal is"<< output;
}