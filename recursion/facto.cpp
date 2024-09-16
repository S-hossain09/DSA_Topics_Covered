#include <bits/stdc++.h>

using namespace std;

int facto(int num)
{
    if(num == 1)
    {
        return 1;
    }

    else
    {
        return num * facto(num - 1);
    }

}

int main()
{
    int result;
    result = facto(5);

    cout << result << endl;

    return 0;
}