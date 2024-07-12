#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int cash;
    do
    {
        cash = get_int("Change Owed: ");
    }
    while(cash < 0);
    while(cash>=25)
    {
        cash = cash - 25;
        a = a + 1;
        printf("a is: %i\n", a);
    }
    while(cash>=10)
    {
        cash = cash - 10;
        b = b + 1;
        printf("b is: %i\n", b);
    }
    while(cash>=5)
    {
        cash = cash - 5;
        c = c + 1;
        printf("c is: %i\n", c);
    }
    while(cash>=1)
    {
        cash = cash - 1;
        d = d + 1;
        printf("d is: %i\n", d);
    }
    int e = a+b+c+d;
    printf("%i\n", e);
    return(0);
}
