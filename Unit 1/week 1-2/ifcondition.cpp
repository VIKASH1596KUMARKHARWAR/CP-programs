#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout << "Enter the number a and b" <<endl;
    cin >>a >>b;

    /*if(a==b){
        cout << "Hey these are equal" <<endl;
    }else{
        if(a<b){
            cout << "a is smaler " <<endl;
        }else{
            cout << "a is smaller" <<endl;
        }
    }*/

    if(a==b){
        cout << "Hey these are equal" <<endl;
    }else if(a<b){
        cout << "a is smaler " <<endl;
    }else{
        cout << "a is smaller" <<endl;
    }

} 