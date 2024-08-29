
#include<iostream>
using namespace std;

void sort012(int arr[],int n ){
    int low = 0 , iter=0, high = n-1;
     while (low <= high){
        if(arr[iter] ==0){
            swap(arr[low],arr[iter]);
            iter++;
            low++;
        }
         else if(arr[iter] == 1){
            iter++;
        }else{
            swap(arr[iter],arr[high]);

            high--;
        }


     }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;

		cin >> size;
		int arr[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

	
		cout << endl;
	}

	return 0;
}

