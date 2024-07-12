#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc,string argv[])
{
    int counter_1 = 0;
    int num = 0;
    int repeat = 0;
    if(argc == 2)
    {
        string key = argv[1];
        for(int i=0; i < strlen(key); i++)
        {
        if(isalpha(key[i]) != 0)
        {
                counter_1 += 1;
        }
        for(int j = i+1; j < strlen(key); j++)
        {
                if(key[j] == key[i])
                {
                    repeat += 1;
                }
        }
        }
        if(repeat != 0)
        {
            printf("Key must not contain repeating alphabets\n");
            return(1);
        }
        if(strlen(key) != counter_1)
        {
            printf("Usage: ./substitution key\n");
            return(1);
        }
        if(strlen(key) != 26)
        {
            printf("Key must contain 26 characters");
            return(1);
        }
        else
        {
            string text = get_string("plaintext: ");
            printf("ciphertext: ");
            for(int j = 0; j < strlen(text); j++)
            {
                if(isalpha(text[j]) != 0)
                {
                    if(isupper(text[j]) != 0)
                    {
                        num = key[(text[j]-39)%26];
                        printf("%c",toupper(num));
                    }
                    if(islower(text[j]) != 0)
                    {
                        num = key[(text[j]-71)%26];
                        printf("%c", tolower(num));
                    }
                }
                else
                {
                    printf("%c", text[j]);
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("Usage ./substitution key\n");
        return(1);
    }
}
