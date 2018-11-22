#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
#define N 2005
#define M 10005
int dp[N][M], w[N], sum[N], pre[N][M], ans[N];
//dp[i][j] i代表到第幾個車車  j 代表長度
//w[i] 紀錄每個車車尺寸
//紀錄上一個點位置 以便 print
int main()
{
    int n, t, v, i, j, vj, k;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &v);
        v *= 100;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        sum[0] = 0;
        n = 0;
        while (cin >> k, k)
        {
            n++;
            w[n] = k;
            sum[n] = sum[n - 1] + k;
        }
        vj = -1;
        for (i = 1; i <= n; i++)
        {
            for (j = 0; j <= v; j++)
            {
                if (j >= w[i] && dp[i - 1][j - w[i]])
                {
                    k = i;  //可以加到第幾個
                    vj = j; //給print那個迴圈用的
                    dp[i][j] = 1;
                    pre[i][j] = j - w[i]; //紀錄上一次在哪裡
                }
                else if (sum[i] - j <= v && dp[i - 1][j])
                {
                    k = i;
                    vj = j;
                    dp[i][j] = 1;
                    pre[i][j] = j;
                }
            }
        }
        i = k;
        while (i--)
        {
            j = pre[i + 1][vj];
            if (j == vj)
                ans[i] = 1;
            else
                ans[i] = 0;
            vj = j;
        }
        printf("%d\n", k);
        for (i = 0; i < k; i++)
        {
            if (ans[i])
                printf("starboard\n");
            else
                printf("port\n");
        }
        if (t)
            printf("\n");
    }
}