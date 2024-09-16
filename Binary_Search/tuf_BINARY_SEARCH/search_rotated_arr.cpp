#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    /*
    This function searches for a target value in a rotated sorted array.

    What is a rotated sorted array?
    - A rotated sorted array is an array that was originally sorted in ascending order but then some leading elements were moved to the end of the array.
    - For example, the sorted array [0, 1, 2, 4, 5, 6, 7] might be rotated at the pivot index 3, resulting in [4, 5, 6, 7, 0, 1, 2].

    Example:
    Let's say nums = [4, 5, 6, 7, 0, 1, 2] and target = 5.
    The function should return the index of the target value, which is 1 in this case.

    Steps:
    1. Initialize the low and high pointers.
    2. Use binary search to find the target.
    3. If the middle element is the target, return its index.
    4. Determine which part of the array is sorted and adjust pointers accordingly.
    5. Continue the process until the target is found or the search space is exhausted.

    Step-by-step process with pointers:
    Initial array: [4, 5, 6, 7, 0, 1, 2]
    Initial pointers: low = 0, mid = 3, high = 6

    [4, 5, 6, 7, 0, 1, 2]
     ^        ^        ^
    low     mid      high

    mid value = 7, target = 5
    Left part is sorted, target is in the left part
    Adjust high = mid - 1 = 2

    [4, 5, 6, 7, 0, 1, 2]
     ^  ^  ^
       mid
    low   high
    
    mid value = 5, target = 5
    Target found at index 1
    */

    int search(vector<int> &nums, int target)
    {
        // Initialize low and high pointers
        int low = 0, high = nums.size() - 1, mid, ans = -1;

        // Binary search loop
        while (low <= high)
        {
            // Calculate mid index
            mid = (low + high) / 2;

            // Check if mid element is the target
            if (nums[mid] == target)
            {
                ans = mid;
                return ans; // Return the index if target is found
            }

            // Check if the left part is sorted
            if (nums[low] <= nums[mid])
            {
                // Check if target is in the sorted left part
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1; // Adjust high pointer
                }
                else
                {
                    low = mid + 1; // Adjust low pointer
                }
            }
            else
            {
                // Check if the target is in the sorted right part
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1; // Adjust low pointer
                }
                else
                {
                    high = mid - 1; // Adjust high pointer
                }
            }
        }

        return ans; // Return -1 if target is not found
    }
};

int main()
{
    // Example array and target
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Create an instance of Solution
    Solution sol;

    // Search for the target value 5 and print the result
    cout << sol.search(nums, 5) << endl;

    return 0;
}
