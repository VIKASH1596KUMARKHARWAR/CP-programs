#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(false);
        int n = nums.size();
        k %= n;
        if (k == 0)
            return;
        vector<int> remainder;
        for (int i = n - k; i < n; i++)
            remainder.push_back(nums[i]);
        for (int i = 0; i < n - k; i++)
            remainder.push_back(nums[i]);
        nums = remainder;
    }
};
int main()
{
    int N, k;
    cout << "Enter the number of elements in the array: ";
    cin >> N;

    vector<int> nums(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter the number of positions to rotate: ";
    cin >> k;

    Solution obj;
    obj.rotate(nums, k);

    cout << "Rotated array: ";
    for (const int &num : nums)
    {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}