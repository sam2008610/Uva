#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define N 100000
using namespace std;

int father[N];
int find(int p)
{
    return p==father[p]?p:father[p]=find(father[p]);
}
int main()
{
    int a,b,casecount=0;
    while(scanf("%d%d",&a,&b)&&(a>=0&&b>=0))
    {
        bool q=true;
        memset(father,-1,sizeof(father));
        if(!a&&!b)
            q=true;
        else
        {
            if(father[a]==-1) father[a]=a;
            if(father[b]==-1) father[b]=b;
            if(find(a)==find(b))
                q=false;
            father[find(a)]=find(b);
            while(scanf("%d%d",&a,&b)&&!(!a&&!b))
            {
                if(father[a]==-1) father[a]=a;
                if(father[b]==-1) father[b]=b;
                if(find(a)==find(b))
                    q=false;
                father[find(a)]=find(b);
            }
            int count=0;
            for(int i=0; i<=N; ++i)
                if(i==father[i]) count++;
            if(count!=1) q=false;
        }
        if(q==true)  printf("Case %d is a tree.\n",++casecount);
        else  printf("Case %d is not a tree.\n",++casecount);
    }
    return 0;
}