#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /*
        Suppose we have an array:
        1 2 3 4 5 6

        We want to find the prefix sum of
        the array.

        The prefix sum will be like:

        1 3 6 10 15 21.
    */

    int n;
    cout << "Enter the value of n for prefix sum: ";

    cin >> n;

    vector<int> arr(n + 1);
    /*
         For 1 based vector.

         we will store 0 at arr[0].
    */

    // can take user input if we want instead of adding i.
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = arr[i - 1] + i;
    }

    // we have created a prefix sum of the values.

    /*
        Now we can find out the sum of any range from
        array.
    */

    // let us find the sum of index : 4 and 6 (1 based).

    cout << "Sum of range 4 and 6 is " << arr[6] - arr[4 - 1] << endl;
    
    /*
        We already know the sum upto 6th index.

        so the sum at 6th index is 21.

        now for 4th index.
        we know that sum upto 4th index is 10. 

        We need sum starting from 4th index to 6th index.

        we deduct the sum before 4th index. We
        get the sum of the range 4th index to 6th index.
    */

    return 0;
}