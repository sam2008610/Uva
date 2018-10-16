
#include <iostream>
#include <string>

using namespace std;
int main()
{
    int cases = 0;
    while (1 == 1)
    {
        int problems;
        string s;
        cin >> s;
        cin >> problems;
        if (s == "0" && problems == 0)
        {
            break;
        }
        for (int i = 0; i < problems; i++)
        {
            int n1, n2;
            cin >> n1 >> n2;
            if (n1 > n2)
            {
                int temp = n1;
                n1 = n2;
                n2 = temp;
            }
            int sum = 0;
            for (int j = n1; j <= n2; j++)
            {
                if (s[j] == '1')
                    sum++;
            }
            if (i == 0)
                cout << "Case " << ++cases << ":" << endl;
            if (sum == 0 || sum == n2 - n1 + 1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
