#include<iostream>
using namespace std;
int main(){
    int ror = 15 | 30;
    int rand = 15 & 30;
    int rnot =  ~15;
    int rxor= 15^30;
    int rls = 15 << 2;
    int rrs = 15 >> 2;

    cout << ror <<endl;
    cout << rand <<endl;
    cout << rnot <<endl;
    cout << rxor <<endl;
    cout << rls <<endl;
    cout << rrs <<endl;

    //increment and decrement operators
    int a = 10;
    cout << ++a <<endl;
    cout<< a++ <<endl;
    cout<< a-- <<endl;
    cout<< --a <<endl;

    
    // int x = 15;
    // int y = x++;
    // int z = ++x;
    // cout << y << " " << z;

    int x = 10;
    int y = 20;
    if(x++ > 10 && ++y > 20 ){
    cout << "Inside if ";
    } else{
    cout << "Inside else ";
    }
    cout << x << ""  << y;

    
    return 0;

}