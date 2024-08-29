#include<iostream>
using namespace std;

void merge(int a[],int si,int ei){
    int mid= (si+ei)/2;

    int *temp = new int[ei-si +1];//temporary array to store the merged result

    int  i = si; 
    int j = mid+1;
    int k =0;

    //merge
    while(i<=mid && j<=ei){
        if(a[i] <=a [j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }

    while (i<=mid){
        temp[k++]=a[i++];
    }

    while (j<=ei){
        temp[k++]=a[j++];
    }
    

    int m =0;
    while(m<k){
        a[si+m]=temp[m];
        m++;
    }

    delete[] temp;
}

void mergeSort(int input[],int start,int end){
    if(start >=end) return;

    int midIndex= (start+end)/2;
    mergeSort(input,start,midIndex);
    mergeSort(input,midIndex+1,end);
    merge(input,start,end);
}  

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    mergeSort(arr, 0, 9); // Call merge_sort with array and initial indices

    // Print sorted array
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
