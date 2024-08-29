#include <iostream>
using namespace std;

int fibo_3(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }

    return ans[n];
}

int main()
{
    int n;
    cout << "Enter the no. to find ith fibonacci no.";
    cin >> n;
    int a = fibo_3(n);
    cout << a << endl;

    for (int i = 0; i < n; i++)
    {
        cout << fibo_3(i) << " ";
    }
}