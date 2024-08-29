#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());       // reverse the entire array
        reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
        reverse(nums.begin() + k, nums.end());   // reverse the rest of the array
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