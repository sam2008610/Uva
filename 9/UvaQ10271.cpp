#include<iostream>
#include<cstring>
#define SQ(x) ((x)*(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MaxN = 5100;

int n,m;
int len[MaxN];
int dp[MaxN][1050];
int main()
{
    int nCase;
    cin >> nCase;
    while(nCase--)
    {
        cin >> m >> n;
        for(int i=1 ; i<=n ;i++)
        {
            cin >> len[i];
        }
        m+=8;
        memset(dp,INF,sizeof(dp));
        for(int i=1 ; i <=n ; i++){
            dp[i][0]=0;
        }
        for(int i=n-2 ; i>0 ;i--)
        {
            for(int j=m ; j>0 ;j--)
            {
                dp[i][j] = dp[i+1][j];
                if(dp[i+2][j-1] !=INF &&(n-i-1)-(j-1)*3>=1 )
                {
                    dp[i][j] = min(dp[i][j],dp[i+2][j-1]+SQ(len[i]-len[i+1]));
                }
            }
        }
        cout << dp[1][m] <<endl;
    }
}