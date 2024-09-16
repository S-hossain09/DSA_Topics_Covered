#include <bits/stdc++.h>

using namespace std;

// Function to find the element that appears only once in a sorted array
// where every other element appears exactly twice
int bin_ser(vector<int> &nums) {
    // Initializing the search boundaries
    int low = 1, high = nums.size() - 2, mid;

    // Binary search loop
    while (low <= high) {
        mid = (low + high) / 2; // Calculate the mid index

        // Check if the current element is the unique one
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
            return nums[mid]; // Return the unique element
        }

        // Process of elimination
        /*
            We are following this process:
            - If mid is even, we check its right for the same element.
            - If mid is odd, we check its left for the same element.
            - If the same element is found, move towards the right.
            - Otherwise, move towards the left.
        */
        if (mid % 2 != 0 && nums[mid] == nums[mid - 1] || mid % 2 == 0 && nums[mid] == nums[mid + 1]) {
            low = mid + 1; // Move the lower bound to the right
        } else {
            high = mid - 1; // Move the upper bound to the left
        }
    }

    return -1; // Return -1 if no unique element is found
}

int main() {
    // Example array where every element except one appears twice
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    // Call the binary search function and print the result
    cout << bin_ser(nums) << endl;

    return 0;
}
