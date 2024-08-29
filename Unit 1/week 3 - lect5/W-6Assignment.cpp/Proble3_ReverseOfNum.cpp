#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int N;
	cin >> N;
	int reverse = 0;
	while (N>0){
		int digits = N%10;
		if(digits != 0 || reverse != 0){
			reverse = reverse*10 + digits;
		}
		N /=10;
	}
	 cout << reverse;
}
