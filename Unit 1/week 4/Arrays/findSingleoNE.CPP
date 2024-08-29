/*You have been given an integer array(ARR) of size N.

Now, in the given array, all numbers are present twice or more than twice except only one number is present only once.

You need to find and return that number which is unique in the array.

*/
#include <iostream>
using namespace std;
int findUnique( int arr[], int size){
    for(int i = 0 ;i< size; i++){
        int count = 0;
        for ( int j = 0 ; j< size ; j++){
            //compute the freq of elements
             if(arr[i]== arr[j]){
                count++;
             } 
        }
        //if frequency of elements is 1
        if (count == 1){
            return arr[i];
        }
    }
    return -1;
}
int main()
{

	
		int size;
		cin >> size;
		int input[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		cout << findUnique(input, size) << endl;
	

	return 0;
}    



