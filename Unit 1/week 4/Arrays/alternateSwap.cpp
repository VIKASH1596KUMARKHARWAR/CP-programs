#include <iostream>
using namespace std;

#include <iostream>
using namespace std;


void swapAlternate(int b[],int n){
    int i =0;
    int j = n-1;
    while (i < j){
        int temp = b[i];
        b[i]= b[i+1];
        b[i+1]=temp;
        i+=2;
    }
}

int main()
{
	
		int size;
		cin >> size;
		int arr[size];
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
		swapAlternate(arr, size);
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	
}