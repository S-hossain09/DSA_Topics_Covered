#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

void print()
{
    if (cnt == 3)
    {
        return;
    }

    cout << cnt << endl;
    cnt++;

    print();
}

void print_name_nth_time(int i, int n)
{
    if (i > n)
    {
        cout << i << endl;
        return;
    }

    else
    {
        cout  << i << " Hello Habiba "<< endl;
        print_name_nth_time((i + 1), n);
    }
}

void back_tracking(int i, int n)
{
    if(i>6)
    {
        return;
    }

    back_tracking((i+1),n);
    cout << i << endl;

}

int main()
{
    // print();

    back_tracking(1,6);


    return 0;
}