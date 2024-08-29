#include<iostream>
using namespace std;
int main(){
    int N;
    cout << "Enter the  Nth number of fibonacci number you want ";
    cin >>N;
    if(N<=0){
    }else if(N==1 || N ==2){
        cout << N << endl;
    }else {
        int first_Number = 1;        
        int second_Number = 1;        
        int fib_Number = 1;
        for(int i = 3; i <= N; i++){
            fib_Number = first_Number + second_Number;
            first_Number = second_Number;
            second_Number = fib_Number;
        }
        cout << fib_Number << endl;
    }
    return   0;
}