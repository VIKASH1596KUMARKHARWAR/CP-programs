#include <iostream>
#include <climits>
using namespace std;

void printArray(int input[], int size) {
    // cout << "Function : " <<  sizeof(input[0]) << endl;
    cout << "Print" << endl;
    for(int i= 0; i < size;i++){
        cout << input[i] << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;

    if (n > 100) {
        cout << "Error: Maximum array size exceeded" << endl;
        return 1;
    }

    int input[100];
    cout <<"address of zeroth index is given by array name and  is"  << input << endl;
cout <<" Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    // cout << "Main : " << sizeof(input) << endl;
    printArray(input, n);

    return 0;
}
