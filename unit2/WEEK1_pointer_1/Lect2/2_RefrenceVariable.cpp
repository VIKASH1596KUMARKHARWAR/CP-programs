#include <iostream>
using namespace  std;
int main(){
    cout << " example1: "<< endl;
    int i= 10;
    int& j = i;
    i++;
    cout<<"chanegs made in i: "<<i<<endl;
    cout<<"After RefrenceING J: "<<j<<endl;//After making j as refrence varible -changes made in i reflect in j: 

    cout << " example2: "<< endl;
    //continuion...
    int k = 100;
    j = k;
    cout <<" changes were  made in j but i is:  "<< i<< endl; 

}