/* A
BB
CCC
DDDD
*/
/*
#include<iostream>
using namespace std;
int main(){
int n;
cin >> n;
int row =1;
while(row <= n){
    int j=1 ;
    char startCharacter = 'A'+ row -1;
    while(j <= row){
        cout << startCharacter;
        j++;
    }
    cout << endl;
    row++;
} 
return 0;}
*/
/*Alt way*/
#include<iostream>
using namespace std;
int main(){
int n;
cin >> n;
int row =1;
char ch = 'A';
while(row <= n){
    int j=1 ;
    while(j <= row){
        cout << ch;
        j++;
        // ch++;
    }
    cout << endl;
    row++;
    ch++;
}}
