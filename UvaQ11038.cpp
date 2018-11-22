#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
long long int summ(long long int);

int main()
{
    long long int m, n;
    while (scanf("%lld%lld", &m, &n))
    {
        if (m < 0)
            break;
        long long int anw = summ(n) - summ(m - 1);
        if (m == 0)
            anw++;
        printf("%lld\n", anw);
    }
}
long long int summ(long long int a)
{
    long long int anw = 0, A = a;
    int temp = 1; //每次要乘的數量
    while (A >= 10)
    {
        int n = A % 10;
        A = A / 10;
        if (n)
        {
            anw += (A * temp);
        }
        else
        {
            anw += ((A - 1) * temp + a % temp + 1);
        }
        temp *= 10;
    }
    return anw;
}