#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
     if (n <2) {
        cout << "Second Largest Doesn't exist "<< endl;
        return 0;
    }
    int largest =INT_MIN;
    int secondlargest =INT_MIN;
    int arr[n];

      for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

  for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondlargest =  largest;
            largest = arr[i];
        } 
        if (arr[i] != largest && arr[i] > secondlargest) {
            secondlargest = arr[i];
        }
    }  cout << secondlargest << endl;
    return 0;

}