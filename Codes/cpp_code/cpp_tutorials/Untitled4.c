/**
*Example to learn how many iterations take time over one second.
*/
#include<stdio.h>
#include<time.h>
int k ;
void nothing(void)
{
    int j;
    for(j=0;j<10000;j++)
        k++;
    return;
}
int main()
{
    clock_t timer;
    timer = clock();
    int i;
    k = 0;
    for(i = 0;i<11000;i++)
    {
        nothing();
        nothing();
        nothing();
        nothing();
    nothing();
    nothing();


        }
        timer = clock() - timer;
    printf("ticks is %d and time taken is %f.\n k is %d.\n",timer,(float)timer/CLOCKS_PER_SEC,k);
return 0;
}
