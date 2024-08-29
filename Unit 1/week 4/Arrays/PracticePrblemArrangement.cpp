/*You have been provided with an empty array (ARR) and its size N. The user will only input the value of N, and you don't need to be concerned about the array itself.

Your objective is to fill the array using integer values from 1 to N (inclusive), following the specific order: 1, 3, 5, ..., 6, 4, 2.

Note:
Printing the array is not required. Your task is solely to fill it.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 10^4
Time Limit: 1sec
Sample Input 1 :
6
Sample Output 1 :
1 3 5 6 4 2
Explanation of Sample Input 1 :
Since the value of N is 6, the number will be stored in the array in such a fashion that 1 will appear at 0th index, then 2 at the last index, in a similar fashion 3 is stored at index 1. Hence the array becomes 1 3 5 6 4 2.
Sample Input 2 :
9
Sample Output 2 :
1 3 5 7 9 8 6 4 2
*/

#include <iostream>
using namespace std;

void arrange(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    // Fill odd numbers in ascending order from the start
    for (int i = 1; i <= n; i += 2) {
        arr[start] = i;
        start++;
    }

    // Fill even numbers in descending order from the end
    for (int i = 2; i <= n; i += 2) {
        arr[end] = i;
        end--;
    }
}
int main()
{
	
		int n;
		cin >> n;

		int arr[n];
		arrange(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

	
}