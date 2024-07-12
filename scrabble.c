#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int upper(string str);
int conv(string s, int t[]);

int main(void)
{
    int val[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    string player_1 = get_string("player one's turn: ");
    string player_2 = get_string("player two's turn: ");
    //player_1 = upper(player_1);
    for(int i = 0; i < strlen(player_1); i++)
    {
        player_1[i] = toupper(player_1[i]);
    }
    //printf("%s", player_1);
    int sum_1 = conv(player_1, val);
    //player_2 = upper(player_2);
    for(int j = 0; j < strlen(player_2); j++)
    {
        player_2[j] = toupper(player_2[j]);
    }
    //printf("%s", player_2);
    printf("sum 1 is %i\n", sum_1);
    int sum_2 = conv(player_2, val);
    printf("sum 2 is %i \n", sum_2);
    if(sum_1 > sum_2)
    {
        printf("Player 1 Wins!\n");
    }
    if(sum_1 == sum_2)
    {
        printf("Tie\n");
    }
    if(sum_1 < sum_2)
    {
        printf("Player 2 Wins!\n");
    }
}

/*int upper(string str)
{

    for(int i = 0; i < strlen(sum); i++)
    {
        str[i] = toupper(str[i]);
    }
    return(str);
}*/

int conv(string s, int t[])
{
    int value = 0;
    int sum = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] >= 'A' && s[i] <=  'Z') //using this we can ignore the fact that there things othr than A to Z so we can signore symbols too (smart)
        {
            sum = sum + (t[s[i] - 65]);
        }
    }
    return(sum);
}
