#include <bits/stdc++.h>

using namespace std;

int find_peak(vector<int> &nums)
{
    int n = nums.size() - 1;

    if (n == 1)
    {
        return 0;
    }

    if (nums[n - 1] > nums[n - 2])
    {
        return n - 1;
    }

    int low = 1, high = n - 2, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }

        else if (nums[mid] > nums[mid - 1])
        {
            low = mid + 1;
        }

        else if (nums[mid] > nums[mid + 1])
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{

    vector<int> nums= {1,10,13,7,6,5,4,2,1,0};

    cout << find_peak(nums) << endl;

    return 0;
}