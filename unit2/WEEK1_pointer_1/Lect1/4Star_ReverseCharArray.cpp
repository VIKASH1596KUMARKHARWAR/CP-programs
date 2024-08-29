/*You are given a string 'str' consisting of lower case alphabets. You have to find the reverse of the string.

For example:
 If the given string is: str = "abcde". You have to print the string "edcba".*/

#include<iostream>
using namespace std;
#include <cstring> 
void func(char *str) 
{
    int n= strlen(str);
    int start=0;
    int end=n-1;
    while(start< end){
        char temp= str[start];
         str[start] = str[end];
         str[end]=temp;
         start++;
         end--;
    }
    //write your code here
}

int main()
{
    char ch[100001];
    int t;
    cin>>t;
    while(t--)
    {
        cin>>ch;
        func(ch);
        cout<<ch;
	cout<<endl;
    }
}