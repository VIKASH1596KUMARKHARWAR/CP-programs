#include<iostream>
using namespace std;

/*Function to check if a single number is composite*/
bool isPrime(int n){
    if(n<=1)  return true;
    for (int divisor = 2; divisor*divisor <=n;divisor++){
        if(n % divisor == 0){
            return false;
            break;
            // //we found  the  factor of n... in range 2 to sqrt. of n ..therefore not a prime no. 
        }
    }
    return true;//no factor found

}


int main() {

    if(isPrime(78)){
        cout << "78 is a prime no." <<endl;
    }else{
        cout << "78 is a prime no." <<endl;
    }
    int n;
    cout << "Enter the no. N to get all prime no. from 2 to N :  ";
    cin >> n;
    
//print all prime no. from 2 to n 
    cout << "Composite numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (isPrime(i))
            cout << i << " ";
    }
    cout << endl;

    return 0;
}
