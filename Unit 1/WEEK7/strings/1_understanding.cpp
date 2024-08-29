#include<iostream>
using namespace std;
int main(){
/*  string line1,line2;
        cout<< "INPUT LINE1:  ";

    getline(cin,line1);
    cout<< "INPUT LINE2:  ";
    getline(cin,line2);

    // cout << "line1 : "<< line1<< endl<< "line2 : " <<line2;
    cout << line1  <<line2;
*/

    string word ;

    int n;
    cin >> n;
    cin.ignore(1);
    getline(cin,word);
    cout <<"output: "<< n <<endl<< word;

}