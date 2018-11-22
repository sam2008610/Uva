#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_ARRAY = 650; // 一人可得的最大金額為 32*20 = 640，取一個比它大的數字
const int BIG_NUM = 9999;  // 同上

/* 取最大值 */
int max3(int a, int b, int c)
{
    return max(max(a, b), c);
}

/* 取最小值 */
int min3(int a, int b, int c)
{
    return min(min(a, b), c);
}

int main()
{
    int times, tmpTime;
    cin >> times;
    tmpTime = times;
    while (tmpTime--)
    {
        int num, sum = 0, ans = BIG_NUM;
        bool T[MAX_ARRAY][MAX_ARRAY] = {};
        // T[i][j] => 三人分別取得 i, j, sum-i-j 時的情況
        // 若此情況存在 -> true

        /* Input */
        cin >> num;
        int candy[num];
        for (int i = 0; i < num; i++)
        {
            cin >> candy[i];
            sum += candy[i]; // 計算總和
        }

        /* Make table */
        T[0][0] = true;               // 三人分別取得 0, 0, sum -> 肯定存在 -> true
        for (int i = 0; i < num; i++) // 遍歷所有糖果
            // 遍歷 T
            for (int j = sum; j >= 0; j--)
                for (int k = sum; k >= 0; k--)
                    if (T[j][k])
                    {                              // 若此情況存在，則以下情況必存在
                        T[j + candy[i]][k] = true; // 給第一人糖果
                        T[j][k + candy[i]] = true; // 給第二人糖果

                        int badness = max3(j, k, sum - j - k) - min3(j, k, sum - j - k); // 算差距
                        ans = min(ans, badness);
                    }

        /* Output */
        cout << "Case " << times - tmpTime << ": " << ans << endl;
    }

    return 0;
}