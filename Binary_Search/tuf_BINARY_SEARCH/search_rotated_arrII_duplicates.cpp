#include <bits/stdc++.h>

using namespace std;

/*
    This function searches for a target value in a rotated sorted array that may contain duplicates.

    Example:
    Let's say nums = {3, 3, 1, 2, 3, 3, 3, 3, 3} and target = 1.
    The function should return the index of the target value, which is 2 in this case.

    Steps:
    1. Initialize the low and high pointers.
    2. Use binary search to find the target.
    3. If the middle element is the target, return its index.
    4. Handle the special case where nums[low] == nums[mid] == nums[high].
    5. Determine which part of the array is sorted and adjust pointers accordingly.
    6. Continue the process until the target is found or the search space is exhausted.

    Step-by-step process with pointers:
    Initial array: [3, 3, 1, 2, 3, 3, 3, 3, 3]
    Initial pointers: low = 0, mid = 4, high = 8

    [3, 3, 1, 2, 3, 3, 3, 3, 3]
     ^           ^           ^
    low         mid         high

    mid value = 3, target = 1

    nums[low] == nums[mid] == nums[high], adjust low and high
    Adjust low = low + 1 = 1, 
    high = high - 1 = 7

    [3, 3, 1, 2, 3, 3, 3, 3, 3]
        ^        ^        ^
       low      mid     high

    nums[low] == nums[mid] == nums[high], adjust low and high
    Adjust low = low + 1 = 2,
    high = high - 1 = 6

    [3, 3, 1, 2, 3, 3, 3, 3, 3]
           ^     ^     ^
         low    mid  high

    mid value = 3, target = 1
    Left part is sorted, target is in the left part
    Adjust high = mid - 1 = 3

    [3, 3, 1, 2, 3, 3, 3, 3, 3]
           ^  ^  ^
         low mid high

    [3, 3, 1, 2, 3, 3, 3, 3, 3]
           ^  
           ^ ^
          low
          mid
            high
    mid value = 1, target = 1
    Target found at index 2
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

        // Handle the case where nums[low] == nums[mid] == nums[high]
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low += 1;  // Increment low
            high -= 1; // Decrement high
            continue;  // Continue to the next iteration
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

int main()
{
    // Example array and target
    vector<int> nums = {3, 3, 1, 2, 3, 3, 3, 3, 3};

    // Search for the target value 1 and print the result
    cout << search(nums, 1) << endl;

    return 0;
}
