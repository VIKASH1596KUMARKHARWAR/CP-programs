#include<iostream>
#include<vector>
using namespace std;
int main(){
    // vector <int> v={3,5,4,89,6,2};
    // vector<int> :: iterator it =v.begin();

    vector<string> v={ "hello","world"};
    auto it =v.begin();//at first we have v as int and the in mid we change it to string  

    cout<<*it<<endl;
    cout<<*(it+1);
}