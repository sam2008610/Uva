#include <iostream>
#include <cstdio>
#include <cmath>
#define NN 10000000
using namespace std;

int main()
{
    //篩法建立質數表
    static bool isPrime[NN] = {false, false};
    int SQRT = sqrt(NN);
    for (int i = 2; i <= SQRT; i++)
        if (!isPrime[i])
            for (int j = i * 2; j < NN; j += i)
                isPrime[j] = true;
    int n;
    //歌德巴赫猜想-任意偶數為兩質數之組合
    while (scanf("%d", &n) != EOF)
    {
        if (n < 8)
        {
            printf("Impossible.\n");
            continue;
        }
        if (n % 2 == 0)
        {
            printf("2 2 ");
            n -= 4;
        }
        else
        {
            printf("2 3 ");
            n -= 5;
        }
        for (int i = 2; i < n; i++)
        {
            if (!isPrime[i] && !isPrime[n - i])
            {
                printf("%d %d\n", i, n - i);
                break;
            }
        }
    }
    return 0;
}