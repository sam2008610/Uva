//pass online judge
#include <iostream>
#include <iomanip>

#define max_num 1000
using namespace std;

int main()
{
    double stu[max_num], t;
    while (1 == 1)
    {
        cin >> t;
        if (t == 0)
            break;
        for (int i = 0; i < t; i++)
        {
            cin >> stu[i];
        }
        double all = 0, last = 0;
        for (int i = 0; i < t; i++)
        {
            all = all + stu[i];
        }
        all = all / t;
        int temp = all * 100;
        all = (double)(temp) / 100;
        //cout << all << endl;
        double bigger = 0, smaller = 0, temp2 = 0;
        int coun = 0;
        for (int i = 0; i < t; i++)
        {
            if (stu[i] > all)
            {
                temp2 = stu[i] - all - 0.01;
                smaller -= temp2;
                bigger += temp2;
            }
            else
            {
                temp2 = all - stu[i];
                smaller += temp2;
            }
        }
        //cout << smaller << endl;
        //cout << bigger << endl;
        if (smaller > 0)
        {
            bigger += smaller;
        }

        cout << "$" << fixed << setprecision(2) << bigger << endl;
    }
    return 0;
}
