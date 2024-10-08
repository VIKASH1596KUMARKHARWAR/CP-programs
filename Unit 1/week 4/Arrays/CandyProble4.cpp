#include<iostream>
using namespace std;

void maximum_candy(int n, int arr[],int extra_candies, bool output[]){
    // checking maximum candies a child  have currently w/o given extra to  them 
    int maxCandies = 0;
    for(int i = 0; i < n;   i++){
        if(arr[i] > maxCandies){
            maxCandies = arr[i];
        }
    }
    //checking for theeach child if they will have the maximum candies if given all extraCandies
    for (int i = 0; i < n; i++){
        output[i] =(arr[i] + extra_candies >= maxCandies);
    }
}

int main(){
     int n,extraCandies;
    cin>>n>>extraCandies;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    bool output[n];
    
    maximum_candy(n,arr,extraCandies,output);

    for(int i = 0;i<n;i++){
        if(output[i]){
            cout<<"True ";
        }
        else{
            cout<<"False ";
        }
    }
    return 0;
}