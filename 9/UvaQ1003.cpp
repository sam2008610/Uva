#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f;
int L, n;
int cut[52], dp[52][52];

int dynamic(int, int);

int main() {
    while(cin >> L && L != 0) {
        cin >> n;
        cut[0] = 0; cut[n+1] = L;
        memset(dp, -1, sizeof(dp));
        for(int i=1; i<=n; i++)
            cin >> cut[i];
        printf("The minimum cutting is %d.\n", dynamic(0, n+1));
    }
    return 0;
}

int dynamic(int a, int b) {
    if(dp[a][b] > -1)
        return dp[a][b]; 
    if(a + 1 == b) // 沒辦法切割
        return 0;

    int ans = INF;
    for(int i=a+1; i<b; i++) {
        ans = min(ans, dynamic(a, i) + dynamic(i, b));
    }
    return dp[a][b] = ans + cut[b] - cut[a]; // cut[b] - cut[a] 為被切割棍子長度
}