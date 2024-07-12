#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int i = 0;
    int a = 0;
    int b = 0;
    int v = 0;
    int w = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int div1 = 0;
    int div2 = 0;
    int sum1 = 0;
    int sum2 = 0;
    int sum = 0;
    int check = 0;
    long card = 0;
    long j = 0;
    int k = 0;
    long l = 0;
    int h = 0;
    int m = 0;
    long n = 0;
    int o = 0;
    card = get_long("Card Number: ");
    l = card;
    j = card;
    n = card;
    while(j > 0)
    {
        j = j/10;
        i = i+1; //this is use as a counter to check the number of digits of the card
    }
    if(i != 13 && i != 16 && i != 15)
    {
        printf("INVALID\n");
    }
    else
    {
        //printf("%i\n", i);
        do
        {
            a = (card%10); //take in the odd digits in the card
            //printf("a %i\n",a);
            if(a >= 10)
            {
                do
                {
                    y = a%10;
                    z = a/10;
                    div1 = div1 + y;
                }
                while(z>0);
            }
            //printf("div1 is %i\n",div1);
            card = card/10;
            sum1 = sum1 + a + div1; //to store the odd number digits into sum1
            //printf("card is %li\n",card);
            printf("sum 1 is %i\n",sum1);
            b = (card%10)*2; //take in the even digits in the card
            if(b >= 10)
            {
                do
                {
                    v = b%10;
                    b = b/10;
                    div2 = div2 + v;
                }
                while(b>0);
                b = 0;
            }
            //printf("div2 is %i\n",div2);
            //printf("b is %i\n", b);
            card = card/10;
            sum2 = sum2 + b + div2;
            div2 = 0;
            printf("sum2 is %i\n", sum2);
            //printf("card is %li\n",card);
        }
        while(card > 0);
        sum = sum1 + sum2;
        check = sum%10;
        //printf("check is %i\n", check);
        printf("sum is %i\n", sum);
        if(check != 0)
        {
            printf("INVALID\n");
        }
        if(check == 0)
        {
            if(i == 16)
            {
                //long u = pow(10,i-2);
                //printf("%li\n", u);
                l = l/pow(10,i-2);
                //printf("l is %li\n", l);
                while(l > 0)
                {
                    m = l%10;
                    h = h + m;
                    l = l/10;
                    if(m == 4)
                    {
                        h = m;
                        break;
                    }
                }
                //printf("h is %i\n", h);
                if(h == 6)
                {
                    printf("MASTERCARD\n");
                }
                if(h == 7)
                {
                    printf("MASTERCARD\n");
                }
                if(h == 8)
                {
                    printf("MASTERCARD\n");
                }
                if(h == 9)
                {
                    printf("MASTERCARD\n");
                }
                if(h == 10)
                {
                    printf("MASTERCARD\n");
                }
                if(h == 4)
                {
                    n = n/pow(10,i-1);
                    //printf("l is %li\n", l);
                    while(n > 0)
                    {
                        o = o + n%10;
                        n = n/10;
                    }
                    printf("o is %i", o);
                    printf("n is %li", n);
                    if(o == 4)
                    {
                        printf("VISA\n");
                    }
                    else if(o != 4)
                    {
                        printf("INVALID\n");
                    }
                }
                else if(h != 6 && h != 7 &&h != 8 && h != 9 && h != 10 && h != 4)
                {
                    printf("INVALID\n");
                }
            }
            if(i == 13)
            {
                l = l/pow(10,i-1);
                //printf("l is %li\n", l);
                while(l > 0)
                {
                    h = h + l%10;
                    l = l/10;
                }
                //printf("%i\n", h);
                if(h == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            if(i == 15)
            {
                l = l/pow(10,i-2);
                while(l > 0)
                {
                    h = h + l%10;
                    l = l/10;
                }
                if(h == 7)
                {
                    printf("AMEX\n");
                }
                if(h == 10)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
    }
    //printf("sum1 is %i\n", sum1);
    //printf("sum2 is %i\n", sum2);
}
