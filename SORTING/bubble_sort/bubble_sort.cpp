#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {3,1,5,2,4,9};

    for(int i = (6-1); i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            if(arr[j] > arr[j+1])
            // this is because of adjacent swaps.
            // we can get it by checking the next element of it
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return 0;
}