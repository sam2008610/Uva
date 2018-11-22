// 10324  zeros and ones
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

string data;
int tt, sums[1000010];

int main()
{
    int n, i, j, Min, Max, T = 1;
    while (cin >> data)
    {
        int L = data.length();
        sums[0] = 0;
        for (i = 1; i < L; ++i)
        {
            sums[i] = sums[i - 1];
            if (data[i] != data[i - 1])
                sums[i]++;
        }

        printf("Case %d:\n", T++);
        cin >> n;
        while (n--)
        {
            cin >> i >> j;
            if (sums[i] == sums[j])
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}