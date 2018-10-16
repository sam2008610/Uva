
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[1000000];
char str[1000000];
int i,k,q,j;
char *ptr;

int main(void)
{
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {                    
        scanf("%s",&string);
        scanf("%d",&q); 
        for(j=0;j<q;j++)
        {                     
            scanf("%s",&str);
            ptr = strstr( string, str );
            if ( ptr != NULL ) printf("y\n");
            else printf("n\n");
        }
    }
    return 0;
}