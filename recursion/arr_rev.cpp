#include <bits/stdc++.h>

using namespace std;

void arr_rev(int i, int arr[], int n)
{
    if(i >= n/2)
    {
        return;
    }

    else
    {
        swap(arr[i],arr[(n-i-1)]);

        arr_rev(i+1, arr, n);
    }
}


int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    arr_rev(0, arr, 5);

    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}