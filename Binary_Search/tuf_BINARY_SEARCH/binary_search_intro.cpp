/*
     Q-> What is Binary Search?

    Ans-> Binary Search Algorithm is a searching
    algorithm used in a sorted array by repeatedly
    dividing the search interval in half.

    Q-> Add a real life example below for using a
    binary search.

    Ans-> An example of binary search in real life is looking for a word in a dictionary.
          You start in the middle and decide whether the word should be before or after
          the current page, thus reducing the search area by half each time.

    Q-> Special requirements for binary search:

    Ans-> 1) The elements need to be in a sorted order.

    Q-> Below is the example of how we can apply binary search
    in coding.

    Ans-> Suppose we have a sorted array.
    arr[] = {1, 3, 4, 6, 7, 12, 13, 14, 18, 23, 53}

    from this we have to find 3. Now writing the pseudo code
    of how it will work.

    Pseudo Code:
    ------------------------
    1. Initialize start to 0 and end to n-1.
       start = 0, end = 10 (since n = 11)

    2. While start is less than or equal to end:
       a. Find the middle element.
          middle = (start + end) / 2
          In the first iteration:
          start = 0, end = 10, middle = (0 + 10) / 2 = 5

       b. Check if the middle element is the target:
          If arr[middle] == target, return the index.
          In the first iteration:
          arr[5] = 12, which is not equal to 3

       c. If the middle element is greater than the target,
          search in the left half:
          If arr[middle] > target, end = middle - 1
          In the first iteration:
          12 > 3, so end = 5 - 1 = 4

       d. If the middle element is less than the target,
          search in the right half:
          If arr[middle] < target, start = middle + 1
          (This step will not be executed in the first iteration)

    Second iteration:
       start = 0, end = 4, middle = (0 + 4) / 2 = 2
       arr[2] = 4, which is not equal to 3
       4 > 3, so end = 2 - 1 = 1

    Third iteration:
       start = 0, end = 1, middle = (0 + 1) / 2 = 0
       arr[0] = 1, which is not equal to 3
       1 < 3, so start = 0 + 1 = 1

    Fourth iteration:
       start = 1, end = 1, middle = (1 + 1) / 2 = 1
       arr[1] = 3, which is equal to 3
       Return the index 1
    ------------------------

    Q-> Implementations of Binary Search?

    Ans-> There are two ways to implement a Binary Search.

    They are :
    1) Recursive method.
    2) Iterative method.
*/


/*
    Time complexity to find the element using binary search:

    ** In best case scenario :
    if the array is sorted . Then the time complexity is 
    O(log2(n))

    Because every time it is getting divided by half.
    suppose we have an array of size 32 > 32/2 == 16 > 8 > 4 > 2 > 1.

    ** In worst case scenario :
    if the array is not sorted. We have to sort the array first.
    so to sort the sort the array it will take O(nlogn);
*/

#include <bits/stdc++.h>

using namespace std;

// Function to implement binary search with iterative method.
int Iterative_Binary_search(vector<int> &nums, int target)
{
    int n = nums.size();
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] < target)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

// Function to implement binary search with recursive method.
int Recursive_Binary_search(std::vector<int> &nums, int start, int end, int target)
{
    // Pseudo code:
    // 1. If start index is greater than end index, return -1 (base case, target not found).
    if (start > end)
    {
        return -1;
    }

    // 2. Calculate the middle index of the current range.
    int mid = (start + end) / 2;

    // 3. If the middle element is the target, return the middle index.
    if (nums[mid] == target)
    {
        return mid; // Target found
    }

    // 4. If the middle element is less than the target,
    //    recursively search in the right half (mid + 1 to end).
    else if (nums[mid] < target)
    {
        return Recursive_Binary_search(nums, mid + 1, end, target);
    }

    // 5. If the middle element is greater than the target,
    //    recursively search in the left half (start to mid - 1).
    return Recursive_Binary_search(nums, start, mid - 1, target);

        /*
        int target = 7; // Example: Find the target value 7 in arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    
        Step-by-step process for finding 7:
        Initial call: Recursive_Binary_search(nums, 0, 9, 7)
        1. mid = (0 + 9) / 2 = 4

        2. nums[4] = 5, which is less than 7

        3. Search in the right half: Recursive_Binary_search(nums, 5, 9, 7)
           a. mid = (5 + 9) / 2 = 7

           b. nums[7] = 8, which is greater than 7

           c. Search in the left half: Recursive_Binary_search(nums, 5, 6, 7)

              i. mid = (5 + 6) / 2 = 5

              ii. nums[5] = 6, which is less than 7

              iii. Search in the right half: Recursive_Binary_search(nums, 6, 6, 7)

                  1. mid = (6 + 6) / 2 = 6

                  2. nums[6] = 7, which is equal to 7

                  3. Target found at index 6

        
        Result: The element 7 is found at index 6

        */
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 14, 15, 16, 17, 18};

    cout << endl << "Applying Iterative implementation on binary search: " << endl;

    int target = 123123;

    int result = Iterative_Binary_search(nums, target);

    if (result == -1)
    {
        cout << "The target is not in the array" << endl;
    }

    else
    {
        cout << "The target is in the array in position: " << result << endl;
    }

    cout << endl
         << "Applying Recursive implementation on binary search: " << endl;

    int target2 = 112321;

    int result2 = Recursive_Binary_search(nums, 0, nums.size() - 1, target2);

    if (result2 == -1)
    {
        cout << "The target is not in the array" << endl;
    }

    else
    {
        cout << "The target is in the array in position: " << result2 << endl;
    }

    return 0;
}