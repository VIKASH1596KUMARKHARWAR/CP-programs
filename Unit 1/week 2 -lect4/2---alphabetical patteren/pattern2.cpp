/* pattern 
A
BC
CDE
DEFG
*/

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
        startCharacter++;
        j++;
    }
    cout << endl;
    row++;
} 
return 0;}
