#include<iostream>
using namespace std;

void printTable(int start,int end, int step){

    int fahrenheit =start;
    while (fahrenheit <=end){
        int celsius = (5.0/9) * (fahrenheit -32);
        cout << fahrenheit <<"\t" <<"\t"<< celsius <<endl;
        fahrenheit +=step;
    }
}


int main() {
    int start, end, step;
    cout << "Enter Start Fahrenheit Value: ";
    cin >> start;
    cout << "Enter End Fahrenheit Value: ";
    cin >> end;
    cout << "Enter Step Size: ";
    cin >> step;
    cout << "fahrenheit" <<"\t"  << "celsius" <<endl;

    printTable(start, end, step);
    
    return 0;
}