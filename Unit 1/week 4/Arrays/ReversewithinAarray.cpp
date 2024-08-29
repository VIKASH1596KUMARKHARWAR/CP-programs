#include <iostream>
using namespace std;

void printArray(int b[], int size){
        for(int i=0 ; i<size ; i++){
            cout << b[i] <<" " ;
        }
        cout << endl;
}
void reverse(int b[],int n){
    int i =0;
    int j = n-1;
    while (i < j){
        int temp = b[i];
        b[i]= b[j];
        b[j]=temp;
        i++; 
        j--;
    }
}
int main(){
    int a = 10;
    int input[10] = {1,2,3,4,5,6};
    //hamara main array intput[] that but while defining any particuar function we come up with different array  names (may or may not come ...choice of programmer)

    cout << "Reversed array" << endl;
    reverse(input,6);
printArray(input,6);
}