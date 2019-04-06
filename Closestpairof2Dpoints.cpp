#include <iostream>
#include <cmath>
#include <set>
using namespace std;
class corrd
{
  public:
    double x, y;
};
corrd *prex[2000];
corrd *prey[2000];
int main()
{
    set<corrd> mySet;
    int cases;
    cin >> cases;
    corrd mycorrd[2000];
    while (cases--)
    {
        int n;
        for (int i = 0; i < n; i++)
        {
            cin >> mycorrd[i].x >> corrd[i].y;
        }
    }
}

double dis(corrd n1, corrd n2)
{
    return sqrt(pow((n1.x - n2.x), 2) * pow((n1.y - n2.y), 2));
}