#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int meth[8000] = {0};
int cent[5] = {1, 5, 10, 25, 50};
int main(void)
{
    meth[0] = 1;
    //�ܹ����ӱ�
    //�ت�
    //�~�h�j��N���e�u�Τ@�سf����
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j + cent[i] <= 7490; j++)
        {
            meth[j + cent[i]] += meth[j]; //�C���[�Wcent�����A�ҥH�� meth[j]�[�� meth[j+cent[i]]
        }
    }
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", meth[n]);
    }
}