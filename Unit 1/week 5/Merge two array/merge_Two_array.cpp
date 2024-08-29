void merge(int arr1[], int size1, int arr2[], int size2, int ans[]){
  int i = 0, j = 0, k = 0;

    // Merge both arrays until one of them is exhausted
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            ans[k++] = arr1[i++];
        } else {
            ans[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1, if any
    while (i < size1) {
        ans[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2, if any
    while (j < size2) {
        ans[k++] = arr2[j++];
    }
}
#include <iostream>
using namespace std;


int main()
{
	int t;
    cout<<"no. of test cases: ";
	cin >> t;
	
	while (t--)
	{
		int size1;
            cout<<"size1: ";

		cin >> size1;

		int arr1[size1];
                    cout<<"Element of 1: ";

		for (int i = 0; i < size1; i++)
		{
			cin >> arr1[i];
		}

		int size2;
                    cout<<"size2: ";

		cin >> size2;

		int arr2[size2];
                    cout<<"Element of 2: ";

		for (int i = 0; i < size2; i++)
		{
			cin >> arr2[i];
		}

		int ans[size1+size2];

		merge(arr1, size1, arr2, size2, ans);

		for (int i = 0; i < size1 + size2; i++)
		{
			cout << ans[i] << " ";
		}

		cout << endl;

	}
}