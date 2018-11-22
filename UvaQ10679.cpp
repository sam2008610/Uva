#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string s;
        int q;
        cin >> s >> q;
        for (int j = 0; j < q; j++)
        {
            string ss;
            cin >> ss;
            if (s.find(ss) == string::npos)
            {
                cout << "n" << endl;
            }
            else
            {
                cout << "y" << endl;
            }
        }
    }
}