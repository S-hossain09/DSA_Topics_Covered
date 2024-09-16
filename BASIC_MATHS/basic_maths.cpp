#include <bits/stdc++.h>

using namespace std;

// Function to calculate GCD using Euclidean Algorithm
int GCD_cal(int a, int b)
{
    // Continue looping until one of the numbers becomes 0
    while (a > 0 && b > 0)
    {
        // If either number is 0, break the loop
        if (a == 0 || b == 0)
        {
            break;
        }

        // Find the smaller and larger number
        int min_num = min(a, b);
        int max_num = max(a, b);

        // Update 'b' to be the smaller number and 'a' to be the remainder of max_num / min_num
        b = min_num;
        a = max_num % min_num;

        // ASCII Art to visualize the process
        /*
            a = max_num
            b = min_num
            GCD(a, b):
            a % b
            a % b == remainder

            Example:
            GCD(68, 51)
            68 % 51 = 17
             _______
            |      |
        68 | 51   |    68 divided by 51 gives a remainder of 17
          |____17|


            Now, continue with GCD(51, 17):
            51 % 17 = 0
             _______
            |      |
        51 | 17   |    51 divided by 17 gives a remainder of 0
          |____0_|

            When one number becomes 0, the other number is the GCD.
        */
    }

    // Return the maximum of 'a' and 'b' which is the GCD
    return max(a, b);
}

int main()
{
    int num1 = 1234, num2 = 12345, count = 0;

    // Approach 1: Counting the number of digits in num1 using a loop
    // Takes O(log10(n)) time
    // Number of times the number is divided by 10
    while (num1 > 0)
    {
        count++;
        num1 /= 10;

        /*
            1234:
            1234 / 10 -> 123   count = 1
            123 / 10 -> 12     count = 2
            12 / 10 -> 1       count = 3
            1 / 10 -> 0        count = 4

            after this num1 = 0;
            loop stops.
        */
    }
    cout << "The number of digits in num1: " << count << endl;

    // Approach 2: Counting the number of digits in num2 using logarithm method
    // Takes O(1) time
    int result = (int)(log10(num2)) + 1;
    // log10(12345) = 4.09 -> 4 + 1 = 5

    cout << "The number of digits in num2: " << result << endl;

    // Finding the divisors of any number:
    // Approach 1: Loop from 1 to N (Time: O(n))
    // Approach 2: Loop from 1 to sqrt(n) (Time: O(sqrt(n)))

    int n = 36;
    vector<int> store_divisors;

    // Loop to find divisors from 1 to sqrt(n)
    for (int i = 1; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            store_divisors.push_back(i); // Add divisor to list

            if ((n / i) != i)
            {
                store_divisors.push_back(n / i); // Add the paired divisor
            }
        }
    }

    // Sort the list of divisors
    sort(store_divisors.begin(), store_divisors.end());

    cout << endl;
    cout << "The divisors of " << n << " are: ";
    for (int i = 0; i < store_divisors.size(); i++)
    {
        cout << store_divisors[i] << " ";
    }
    cout << endl;

    // GCD using Euclidean Algorithm
    // The Euclidean Algorithm is based on the principle that the GCD of two numbers
    // also divides their difference.

    cout << endl;
    cout << "GCD of 68 and 51 is " << GCD_cal(68, 51) << endl;

    return 0;
}
