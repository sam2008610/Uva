// 10220 I love big numbers!!
// 大數階層之每位數種和  
//最大到 1000
#include <iostream>

using namespace std;
int main()
{
    int num[3000] = {1}, mem[1001] = {1, 1}, d = 1;
    for (int i = 2; i < 1001; i++)
    {
        for (int j = 0; j < d; j++)
        {
            num[j] *= i;
        }
        for (int j = 0; j < d; j++)
        {
            num[j + 1] += num[j] / 10;
            if (j + 1 >= d && num[j] > 0)
                d++;
            num[j] %= 10;
            mem[i] += num[j];
        }
    }
    int n;
    while (cin >> n && n != EOF)
    {
        cout << mem[n] << endl;
    }
}