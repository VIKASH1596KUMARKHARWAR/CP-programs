#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int i= 1;
    while (i <=n){
        int j=1;
        int p =i;
        while(j<=i){
            cout << p;
            p++;
            j++;
        }
    cout << endl;
    i++;    
    }

}
/*
For n=5
1
23
345
4567
56789*/