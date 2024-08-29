#include<iostream>
using namespace std;

bool isPallindrome(int n){
    if (n <=0){
        return false;
    }

    int original = n;
    int reversed = 0;
     while(n !=0){
        int digit =  n% 10;//extact last digit
         reversed = reversed*10 + digit;
         n = n/10;// remove the last digit
     }
     return original == reversed;
}
int main (){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if(isPallindrome(n)){
        cout << n << " is a pallindrome";
    }else{
        cout << n << " is not a pallindrome";
    }
    return 0;
}
