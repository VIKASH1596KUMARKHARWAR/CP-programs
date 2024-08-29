#include<iostream>
# include<cmath>
using namespace std;
// example 371
 bool isArmstrong(int n){
 int origninal = n;
 int k =0; //track the count of digits in given no.
 int sum = 0;

    //Determine the number of digits in teh given integer n jiisko   check krna h
    int temp = n;
    while( temp !=0 ){
      temp /=10; // dgit_count krne ka sbse accha tarika :: remove the last digit,count variable++
      k++;
    }

    //determine the sum of the digits raised to the power of k 
    //original no. ko sequere rakhenge to chenck for further
     temp = n;
    while( temp !=0){
        int digit = temp % 10;//exracting digits from last
        sum +=pow(digit,k);
        temp /=10;
    }

    //check if sum is equal to original 
    return (sum == origninal);

 }
int main(){
    int n; 
    cout << "Enter the number" << endl;
    cin >> n;
    if(isArmstrong(n)){
        cout << n << "is An Armdtrong number." <<endl;
    }
    else{
                cout << n << "is not An  Armstrong number." <<endl;

    }
}