/*0  for n =4 

****
***
**
*


conclusion : the number of columns are n - i + 1  
0*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int row = 1;
    while (row <= n){
        int col = 1;
        while (col <= n - row  + 1){
            cout << "*";
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}