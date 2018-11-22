#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN(x,y)(((x)<(y))?(x):(y))
char a[100]="#";
char b[100]="#";

int dp[100][100];
int s = 1;

void findDp(int lengthA,int lengthB){
    for(int i=0; i < lengthB+2 ; i++ ){
        for(int j=0;j<lengthA+2;j++){
            if(i*j==0)
            {
                dp[i][j] = i+j;
                continue;
            }
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=MIN(dp[i-1][j-1],MIN(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
    }
}

void printA(int j,int i){
    if(i*j==0){
        while(i>0){
            printf("I%c%.2d",b[i],i);
            i--;
        }
        while(j>0){
            printf("D%c%.2d",a[j],j);
            j--;
        }
    }else if(a[i]==b[j]){
        printA(i-1,j-1);
    }else{
        if(dp[i][j]-1 == dp[i-1][j-1]){
            printf("C%c%.2d",b[j],i);
            printA(i-1,j-1);
        }else if(dp[i][j]-1 == dp[i-1][j]){
            printf("I%c%.2d",b[j],i);
            printA(i-1,j);
        }else if(dp[i][j]-1 == dp[i][j-1]){
            printf("D%c%.2d",a[i+1],i+1);
            printA(i,j-1);
        }
    }
}

int main(){

    while(scanf("%s",&a[1])&&a[1]!='#'){
        scanf("%s",&b[1]);
        s = 1;
        memset(dp,-1,sizeof(dp));
        findDp(strlen(a)-1,strlen(b)-1);
        printA(strlen(a)-1,strlen(b)-1);
        puts("E");
    }

    return 0;
}
