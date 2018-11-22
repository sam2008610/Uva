#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
    int anw[77];
    anw[1] = 1;
    anw[2] = 2;
    anw[3] = 2;
    for (int i = 4; i < 77; i++)
    {
        anw[i] = anw[i - 2] + anw[i - 3];
    }
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", anw[n]);
    }
    return 0;
}
