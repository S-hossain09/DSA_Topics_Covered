#include <bits/stdc++.h>

using namespace std;

void sum_elems(int i, int sum)
{
    if(i < 1)
    {
        cout << sum << endl;
        return;
    }

    else
    {
        sum_elems(i-1, sum+i);
    }
}

int main()
{
    sum_elems(3, 0);

    return 0;
}