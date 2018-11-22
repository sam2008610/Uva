#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int llt;

llt sum0(llt n)
{
    llt N = n, sum = 0;
    int left = 1, mid, right = 1;
    while (N >= 10)
    {
        mid = N % 10;
        N /= 10;
        if (mid)
            sum += (N * left);
        else
            sum += ((N - 1) * left + n % right + 1);
        left *= 10;
        right *= 10;
    }
    return sum;
}
int main()
{
    llt m, n;
    while (scanf("%lld%lld", &m, &n))
    {
        if (m < 0)
            break;
        llt ans = sum0(n) - sum0(m - 1);
        if (m == 0)
            ans++; // 函數是從1~m，如果m==0會少算
        printf("%lld\n", ans);
    }
    return 0;
}