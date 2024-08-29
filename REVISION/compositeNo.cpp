#include<iostream>
using namespace std;
//composite no. and prime no. are complement to each other
//composite number could have many factor .not just 1 and itself

//Note : for checking the Prime Number we used to take a a variabel which keep track of the factor(or say divisor) and we initialise it from 2 and iterate till the sqrt. n, the else we can do is iterating divisior*divisor till the n(squarinng on both side🙃)


/*Function to check if a single number is composite*/
bool isComposite(int n){
    if(n<=1)  return false;
    for (int divisor = 2; divisor*divisor <=n;divisor++){
        if(n % divisor == 0){
            return true;
            //we found  the  factor of n... in range 2 to sqrt. of n +
        }
    }
    return false;

}


int main() {
    int n;
    cin >> n;
//print all composite no. from 2 to n 
    cout << "Composite numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (isComposite(i))
            cout << i << " ";
    }
    cout << endl;

    return 0;
}
