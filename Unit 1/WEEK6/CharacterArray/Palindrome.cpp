#include<iostream>
#include<cstring>
using namespace std;

bool isAlphaNumeric(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

char toLower(char ch){
    if(ch>='A' && ch <='Z'){
        return ch+32;//change to the lower case
    }
    return ch;
}

bool check_palindrome(char str[]){
    int left = 0;
    int right = strlen(str)-1;
    while(left< right){
                // Move left pointer to the next alphanumeric character
        while(left < right && !isAlphaNumeric(str[left])){
             left++;
        }
                // Move right pointer to the previous alphanumeric character
        while(left < right && !isAlphaNumeric(str[right])){
             right--;
        }

        // Compare the characters, after converting them to lowercase
        if (toLower(str[left]) != toLower(str[right])) {
            return false;
        }
        left++;
        right--;

    }
    return true;
}

int main(){
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (check_palindrome(str) ? "true" : "false");
}
