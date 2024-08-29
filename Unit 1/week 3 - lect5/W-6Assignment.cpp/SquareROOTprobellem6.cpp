// Binary search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing the portion of the list that could contain the item in half until you narrow it down to the desired location.
#include <iostream>
using namespace std;

int integerSquareRoot(int N) {
    if (N == 0 || N == 1) {
        return N;
    }
    
    int low = 0, high = N;
    int result = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long midSquared = (long long)mid * mid;
        
        // If mid*mid is equal to N, return mid
        if (midSquared == N) {
            return mid;
        }
        
        // If mid*mid is less than N
        if (midSquared < N) {
            low = mid + 1;
            result = mid;  // Update result because we need floor of the square root
        } else {
            high = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int N;
    cin >> N;
    
    int sqrtN = integerSquareRoot(N);
    cout << sqrtN << endl;
    
    return 0;
}
