#include <stdio.h>
vod Ex1(void)
int main()
{
    int matrix [3] [5] = {{65, 3, 27}, {71,32,99}, {47, 81, 55}, {78, 23,94}, {61, 39, 58}};
    int a=0, b,c,d=0;
    for (b=0; b<5; ++b);
    {
        c=matrix [0][b];
        for (a=1; a<3; ++a)
            if (matrix[a][b]<c){c=matrix[a][b];d=a;}
                printf("matrix [%d][%d] \t%d\n",d,b,c);
    }

}
int main(void)
{

    Ex1();
return 0;
}
