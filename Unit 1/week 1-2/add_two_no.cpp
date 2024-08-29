#include<iostream>
using namespace std;
int main(){
    int a=10;
    int b=23;
    int c=a+b;
    cout << "a="<<a << " " << "b="<< b << " " << "c =  a + b ="  << c << endl;
     
    char d='X';
    cout << "d=" << d << endl;

    float f=1.23;
    cout << "f=" << f << endl;  //4  BYTES

    double g=3.45;
    cout << "g=" << g << endl;  //8 BYTES    

    bool B=true;
    cout << "B=" << B << endl;  //1 BYTES

    int size_doubles=sizeof(g);
    cout << "size_doubles=" << size_doubles << endl;  

    int l=sizeof(long);
    cout << "l=" << l << endl;
}