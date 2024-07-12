#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a;
    do
    {
        a = get_int("What height do you want?\n");
    }
    while(a <= 0);
    int k=0;
    for(int i=0; i<a; i++) //i++ goes through the loop once then only add i by 1 so at first it is 0
    {
        k = a-1;
        for(int j=1; j <= a-i-1; j++)
            {
                printf(" ");
            }
        //printf("%i", i);
        for(int j=a; j >= a-i; j--)
            {
                printf("#");
            }
        printf("  ");
        for(int x=a; x >= a-i; x--)
            {
                printf("#");
            }
        printf("\n");
    }
    return(0);
}
