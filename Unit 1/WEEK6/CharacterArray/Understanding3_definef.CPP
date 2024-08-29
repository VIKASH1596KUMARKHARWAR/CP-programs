#include <iostream>
using namespace std;
#include<cstring>
int main(){
             //length - strlen(arr_name)
    /*char input[100];
    cin >> input;
    int len = strlen(input);
    cout << "length of the array is: " << len <<endl;*/    


        /* String comparison - strcmp(ai,a2)*/
   /*char input1[100],input2[100];
    cout <<"enter str1: "; 

    cin >> input1;
    cout <<"enter str2: " ;
    cin >> input2;

    if(strcmp(input1,input2)==0){
        cout << "true" << endl;
    }
    else{
        cout << " false " <<endl;
    }*/ 

        //STRING COPY-strcpy(DESTINATION,SOURCE)  and strncpy(arr1,arr2,n)
        char input1[100] = "abcde";
        char input2[100]="hello";
        cout  <<"Before copying: "  << endl;
        cout << "input1:" << input1   <<endl;
        cout << "input2:" << input2  <<endl;

        // strcpy(input1,input2);
        // strcpy(input1,"Hello");
         strncpy(input1,input2,3);

        cout<< "After Copying " << endl;
        cout <<"input1: " << input1 << endl; 
        cout <<"input2: " << input2;



}