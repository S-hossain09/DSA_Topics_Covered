#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;

    int left = low;
    int right = (mid + 1);

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }

        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void merge_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    else
    {
        int mid = (low + high) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, (mid + 1), high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    vector<int> arr = {4, 2, 1, 6, 7};

    cout << "Before Sorting" << endl;

    for (auto it : arr)
    {
        cout << it << " ";
    }

    cout << endl;

    cout << "After Sorting" << endl;
    merge_sort(arr, 0, 4);

    for (auto it : arr)
    {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}