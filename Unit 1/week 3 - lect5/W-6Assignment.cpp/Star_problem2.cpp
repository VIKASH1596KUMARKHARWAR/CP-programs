/* 
        == tems of AP == 
Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
Sample Input 1 :
10
Sample Output 1 :
5 11 14 17 23 26 29 35 38 41
Sample Input 2 :
4
Sample Output 2 :
5 11 14 17
Explanation :
Input is 4 and print the first 4 numbers that are not divisible by 4 and are of the form 3N + 2, where k is a non-negative integer.   

CATHCH ::  when we get AP term for any i which could be divisible by 4 then we need to count that missed iteration while using the countine( the way which i tried,getting difficult)
SO CORRECT CODE IS HERE :

*/

#include<iostream>
using namespace std;
int main() {
    int x;
    cin >> x;

    int count = 0; // To keep track of the number of terms printed

     for (int N = 1; count < x; N++) {
        int term = 3 * N + 2;
        if (term % 4 == 0) {
            continue; // Skip the current iteration if term is a multiple of 4
        }
        cout << term << " ";
        count++;
    }

}
