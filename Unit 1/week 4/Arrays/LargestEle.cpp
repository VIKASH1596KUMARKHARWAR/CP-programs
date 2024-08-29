#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of the ARRAY" <<endl;
    cin >> n;
    int arr[100];
    //user inputs
    for (int i = 0;i < n;i++){
        cin >>  arr[i];
    }

    //print the array
    cout << "The elements in the array are " <<endl;
    for (int i = 0;i<n;i++){
        cout << arr[i] <<endl;
    }

    //larget  in  Array
    int max=INT_MIN;
    for (int i = 0;i < n;i++){
        if (arr[i] >max){
            max= arr[i];
        }
    }
    cout << "The largest element in the array is " << max <<endl;

    return 0;
}