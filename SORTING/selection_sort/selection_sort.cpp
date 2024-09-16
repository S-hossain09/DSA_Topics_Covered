/*
    How selection sort works ?

    *It selects the minimum element and puts in the
    first index and then move to next minimum elements
    and place it in the next index.

    Suppose I have these elements :
    13 46 24 52 20 9

    Step 1  -> 9 46 24 52 20 13
    // it will take 9 as it is minimum and
    swap it with 13 because 13 as in the first index.
    Now upto first index in sorted. Now we select the
    next minimum element.

    Step 2  -> 9 13 24 52 20 46
    // it will take 13 as it is next minimum and
    swap it with 46 because 46 as in the second index.
    Now upto second index in sorted. Now we select the
    next minimum element.

    Step 3 -> 9 13 20 24 52 46
    // it will take 20 as it is next minimum and
    swap it with 24 because 24 as in the third index.
    Now upto third index in sorted. Now we select the
    next minimum element.

    Step 4 -> 9 13 20 24 46 52
    // // it will take 46 as it is next minimum and
    swap it with 52 because 52 as in the fifth index.
    Now upto fifth index in sorted. Now we select the
    next minimum element.

    Step 5 -> 9 13 20 24 46 52
    // As all the values upto 52 is sorted , we can say its
    sorted .
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
        int arr[] = {13, 46, 24, 52, 20, 9};

        int min;
        for (int i = 0; i < (5); i++)
        {
                min = i;
                for (int j = i; j < (6); j++)
                {
                        if (arr[min] > arr[j])
                        {
                                swap(arr[i], arr[j]);
                        }
                }
        }

        for (int i = 0; i < 6; i++)
        {
                cout << arr[i] << " ";
        }

        cout << endl;

        return 0;
}
