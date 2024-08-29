#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, size = 0;
    cin >> n;
    vector<int> ar(2 * n + 1);

    // Input elements into the vector 'ar' and find the maximum element
    for (int i = 0; i < 2 * n; ++i) {
        cin >> ar[i];
        size = max(size, ar[i]);
    }

    // FREQUENCY ARRAY
    vector<int> f(size + 1, 0);

    // Update the frequency array
    for (int i = 0; i < 2 * n; ++i) {
        f[ar[i]]++;
    }

    // Find and print the unique element
    for (int i = 0; i <= size; ++i) {
        if (f[i] == 1) {
            cout << unique;
            break;
        }
    }
    return 0;
}
