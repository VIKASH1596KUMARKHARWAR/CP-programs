#include <iostream>
#include <string>
using namespace std;

int lcs_moemoisation(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();

    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (output[m][n] != -1)
    {
        return output[m][n];
    }

    int ans;
    if (s[0] == t[0])
    {
        ans = 1 + lcs_moemoisation(s.substr(1), t.substr(1), output);
    }
    else
    {
        int a = lcs_moemoisation(s.substr(1), t, output); // disarding s[0];
        int b = lcs_moemoisation(s, t.substr(1), output);
        int c = lcs_moemoisation(s.substr(1), t.substr(1), output);
        ans = max(a, max(b, c));
    }

    // save your calculations
    output[m][n] = ans;

    return ans;
}

int lcs_moemoisation(string s, string t)
{
    int m = s.size();
    int n = t.size();

    // Create a 2D array for memoization
    int **output = new int *[m + 1]; // Allocate m+1 rows
    for (int i = 0; i <= m; ++i)
    {
        output[i] = new int[n + 1]; // Allocate n+1 columns
        for (int j = 0; j <= n; ++j)
        {
            output[i][j] = -1; // Initialize with -1 (indicating not computed)
        }
    }

    int result = lcs_moemoisation(s, t, output);

    // Free dynamically allocated memory
    for (int i = 0; i <= m; ++i)
    {
        delete[] output[i];
    }
    delete[] output;

    return result;
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << lcs_moemoisation(s, t) << '\n';

    return 0;
}
