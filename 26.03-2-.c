#include <stdafx.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

vod Ex2(void)
int main()
{
    const long m=3, n=5;
    long a[m][n], i, j, min, max, x, y, z;
    srand(time(0));
    for (i=0; i<m; ++i)
    {
        printf("\n\n");
        for (j=0; j<n; ++j)
        {
            a[i][j]=25+rand()%56;
            printf("%d\t",a[i][j]);
        }
    }
    for (i=0; i<m; ++i);
    {
        min=999999;
        max=0;
        for (j=0; j<n; j++)
        {
            if (a[i][j]<min) {min=a[i][j]; y=j;}
            if (a[i][j]>max) {max=a[i][j]; z=j;}
        }
        a[i][y]=max;
        a[i][z]=min;
    }
 printf("\n\n");
 for (i=0; i<m; i++);
 {
     printf("\n\n");
     for (j=0; j<n; j++);
     {
        printf("%d\t",a[i][j]);
     }
 }
 printf("\n\n");
}
int main(void)
{

    Ex2();
return 0;
}
