#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long LL;
LL M,K,books[501],MAXN,SUM;

void init();
void solve();
bool check(LL);
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        init();
        cin >> M >> K;
        for(int i=0 ; i<M ;i++)
        {
            cin >> books[i];
            SUM +=books[i];
            MAXN = max(MAXN,books[i]);
        }
        solve();
    }
}

void init()
{
    memset(books,0,sizeof(books));
    MAXN=0;
    SUM=0;
}

void solve(){
    //利用二分不斷逼近
    LL left=MAXN,right=SUM,middle;
    while(1)
    {
        if(left==right)
        {
            break;
        }
        middle = (left+right) / 2;
        if(check(middle))
        {
            right = middle;
        }
        else
        {
            left=middle+1;
        }
        
    }
    string ans="";
    LL tmpSum=0;
    int cnt=1;
    middle = left;
    for(int i=M-1 ; i>=0 ; i--){
        if(tmpSum + books[i] > middle || K-cnt == i+1){
            tmpSum = 0;
            cnt++;
            ans=" /"+ans;
        }
        tmpSum +=books[i];
        if(i){
            ans = " "+to_string(books[i])+ans;
        }else{
            ans = to_string(books[i])+ans;
        }
    }
    cout << ans << endl;
}

bool check(LL UB){
    LL tmpSum=0;
    int cnt = 1;
    // 由左至右遍歷
    for(int i=0;i<M;i++){
        if(tmpSum+books[i]>UB){
            tmpSum = 0;
            cnt++;
        }
        tmpSum +=books[i];
        if(cnt>K)
            return false; //「人數 > k」 -> 回傳false
    }
    return true;  //「人數 <= k」 -> 回傳true
}