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
        int star = 1;
        while (star <= rows){
            cout << "*";
            star = star + 1;
        }
        cout << endl;
        rows = rows + 1;
    }
    return 0; 
}

/*  *
   **
  ***
 ****
***** 

*/