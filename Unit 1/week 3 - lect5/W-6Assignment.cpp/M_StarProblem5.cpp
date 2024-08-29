/*Given a decimal number (integer N), convert it into binary and print.

Note for C++ coders:
Do not use the inbuilt implementation of "pow" function. The implementation of that function is done for 'double's and it may fail when used for 'int's, 'long's, or 'long long's. Implement your own "pow" function to work for non-float data types. 
The given input number could be large, so the corresponding binary number can exceed the integer range. So you may want to take the answer as long for CPP and Java. 
*/
#include<iostream>
#include <string>
using namespace std;

long long custom_pow(int base, int exponent){
    long long result = 1;
    while (exponent > 0){
        if(exponent %2 == 1){
            result *= base;
        }
        base *=base;
        exponent/=2 ;
    }
    return result;
}
 int main(){
     long long N ;
     cin>>N;
     if (   N == 0 ){
        cout << "0" << endl;
        return 0;
     }
     string binary ="";
     while (N > 0){
        int remainder=N%2;
         binary = to_string(remainder)  + binary;
         N/=2;
     }
     cout << binary << endl;
     return 0;
 }