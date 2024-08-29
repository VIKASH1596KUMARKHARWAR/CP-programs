#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    // We initialize i to 0. This pointer keeps track of the position where the next non - zero element should be moved.

    int i = 0; // Pointer to track the position of the last non-zero element

    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
        {
            swap(nums[j], nums[i]);
            i++;
        }
    }
}

int main()
{
    int N;
    cout << "Enter the number of elements in the array: ";
    cin >> N;

    vector<int> nums(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    moveZeroes(nums);

    cout << "Array after moving zeroes: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
