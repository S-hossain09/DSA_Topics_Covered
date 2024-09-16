#include <bits/stdc++.h>

using namespace std;

int main()
{
    /* number hashing.
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // precompute
    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;

        cout << "This " << number << " appears " << hash[number] << " this many times" << endl;
    }

    */

    // Character Hashing
    // string s = "abacdbeagvlgac";

    /*
    int hash[26] = {0};

    for (int i = 0; s[i] != '\0'; i++)
    {

        hash[s[i] - 'a'] += 1;
    }

    char q;

    cin >> q;

    cout << hash[q - 'a'] << endl;
    */

    // Character hashing

    // Code by Map

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;

    }

    int q;
    cin >> q;

    cout << endl;

    while (q--)
    {
        int number;
        cin >> number;

        cout << "Number " << number << " " << mpp[number] << endl;
    }

    return 0;
}