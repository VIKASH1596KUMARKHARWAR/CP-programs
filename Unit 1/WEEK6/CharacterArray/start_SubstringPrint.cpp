#include<iostream>
#include<cstring>
using namespace std;

 void substringPrint(char str[]){
    int n =strlen(str);
    for (int start = 0; start < n ;start++){
        for (int end =start; end < n ;end++){
            //print the substring fron str[start] to str[end]
            for (int k = start;k <= end;k++){
                    cout << str[k];
            }
            cout << endl;
        }
    }
 }


int main(){
    int size = 1e6;
    char str[size];
    cin >> str;
    substringPrint(str);
}
