/* 
     1
    121
   12321
  1234321  

logic = for the remaining protions of this (decreasing side) we put the j= i-1 and iterate till j = 1 
*/

#include<iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int rows = 1;
    while(rows <= num){
        int space = 1;
        while(space <= num - rows){
            cout << " ";
            space++;
        }
        int j = 1;
        while (j <= rows){
            cout << j ;
            j = j + 1;
        }
        j = rows  - 1;
        while(j >=1){
            cout << j;
            j = j - 1;
        }
        cout << endl;
        rows = rows + 1;
    }
    return 0; 
}

