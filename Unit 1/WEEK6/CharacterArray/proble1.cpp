#include <iostream>
#include <cstring>
using namespace std;

int main() {
   char str[100];
   char str2[100];
   cin.getline(str,90,'o');
   cin.getline(str2,100);
   cout<<str<<" "<<str2;
}