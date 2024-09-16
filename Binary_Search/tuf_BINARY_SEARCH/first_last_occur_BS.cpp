#include <bits/stdc++.h>

using namespace std;

int lower_bound_func(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1, ans = -1, mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (nums[mid] >= target)
        {
            ans = mid;
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int result[2];

    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};

    int target = 123;

    result[0] = lower_bound_func(arr, target);
    result[1] = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

    if (arr[result[0]] != target)
    {
        result[0] = -1;
    }

    if (arr[result[1] - 1] != target)
    {
        result[1] = -1;
    }

    cout << result[0] << " ";

    cout << (result[1] != -1 ? result[1] - 1 : result[1]) << endl;

    return 0;
}