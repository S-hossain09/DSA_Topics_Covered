#include <bits/stdc++.h>

using namespace std;

// function to write a lower bound of bs
int lower_bound_func(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1, ans = -1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
/*
        Lower bound in binary search :

        smallest index such that arr[ind] >= n.


        Until the smallest index is found we will keep
        searching for the index that matches our requirements.

        Suppose we want to find the lower bound of 1
        from this arr = {1,2,3,3,7,8,9,9,9,11};

        we will have to do this steps below :

        start = 0;
        end = 9;
        mid = (start + end)/2;

        if arr[mid] >= 1
        {
            ans = mid;
        }

        but as we have to find smallest index which has
        the value >= 1 we have to keep searching the index to
        left for smallest value.

        so we need to continue... searching.

        while (start <= end)
        {
            mid = (start + end)/2;

            if arr[mid] >= 1
            {
                ans = mid; // update the answer
                end = mid - 1; // search in the left half
            }
            else
            {
                start = mid + 1; // search in the right half
            }
        }

        // after exiting the loop, ans will hold the smallest index
        // such that arr[ans] >= 1 or it will be -1 if no such index exists.


        Time complexity is same as binary search .

        Time : O(log2(n));
    */

int upper_bound_func(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1, ans = nums.size(), mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (nums[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
/*
         Upper bound in binary search :

         The concept is same as lower bound .

         the only difference is .

         smallest index such that arr[ind] > n

         The difference is in sign only. only greater than
         is sufficient for upper bound.

         Time complexity is same as binary search .

        Time : O(log2(n));

*/

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 13, 13};

    // lower bound starts
    int result = lower_bound_func(arr, 13);

    cout << "The lower bound from our own function is " << result << endl;

    // c++ stl to find the lower bound of binary search.
    int index = lower_bound(arr.begin(), arr.end(), 13) - arr.begin();
    /*
        it return the address where the element is .
        So if we substract with begining address it gives us the index
        position where the element is .
    */

    cout << endl;
    cout << "Lower bound from stl c++ : " << index << endl;
    // lower bound ends

    // upper bound starts
    int result2 = upper_bound_func(arr, 2);

    cout << "The upper bound from our own function is " << result2 << endl;

    // c++ stl to find the lower bound of binary search.
    int index2 = upper_bound(arr.begin(), arr.end(), 2) - arr.begin();

    cout << endl;
    cout << "Upper bound from stl c++ : " << index2 << endl;

    // upper bound ends
    return 0;
}