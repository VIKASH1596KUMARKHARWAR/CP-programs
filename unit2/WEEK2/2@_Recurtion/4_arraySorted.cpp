#include<iostream> 
using namespace std;

bool isSorted( int arr[],int size){
    if(size == 0|| size ==1) return true;
    if(arr[0]> arr[1]) return false;

    bool isSmallSorted = isSorted(arr+1,size-1);
    return isSmallSorted;
    // return isSorted(arr + 1, size - 1);
}


//WAY -2 TO check for  SORT
 bool is_Sorted(const  int arr[],int size,int index=0){
    if(index >= size-1) return true;
    if(arr[index] >arr[index+1]){
        return false;
    };
     return is_Sorted(arr,size,index+1);
 }


int main(){
    int arr1[]={1,2,23,34,45,55,56};
    int arr2[]={1,2,23,34,4,55,56};
  cout << "   Array 1 is " << (isSorted(arr1, sizeof(arr1) / sizeof(arr1[0])) ? "sorted" : "not sorted") << endl;
    cout << "   Array 2 is " << (isSorted(arr2, sizeof(arr2) / sizeof(arr2[0])) ? "sorted" : "not sorted") << endl;
    return 0;}