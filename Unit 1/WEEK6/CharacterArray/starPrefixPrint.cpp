#include<iostream> 
using namespace std;
#include<cstring>

void printPrefix(char input[]){
    //i represent the end index of my prefix
    for(int i = 0 ;input[i] != '\0';i++){
            //j represent the start index of my prefix
        for(int j = 0 ; j <= i;j++){
                cout << input[j];
        }
        cout << endl;
    }
}

 int main(){
        char input1[]  = "abcd";
        printPrefix(input1);
 }