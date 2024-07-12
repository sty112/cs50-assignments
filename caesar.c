#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int digit_check = 0;
    int digit_check2 = 0;
    int new_word = 0;
    string key = argv[1];
    if(argc != 2)
    {
        printf("Usage ./caesar key\n");
        return(1);
        }
    else
    {
        for(int i = 0; i < strlen(key); i++)
        {
            digit_check = strlen(key);
            if(isdigit(key[i]) != 0)
            {
                digit_check2 += 1;
            }
        }
        //printf("%i\n", digit_check);
        //printf("%i\n", digit_check2);
        if(digit_check != digit_check2)
        {
            printf("Usage ./caesar key\n");
            return(1);
        }
        else
        {
            int int_key = atoi(key); //this gives me the key that i previously inputted and change to int
            string word = get_string("plaintext: ");
            printf("ciphertext: ");
            for(int j = 0; j < strlen(word); j++)
            {
                string upper_let[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
                string lower_let[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
                if(isalpha(word[j]) != 0)
                {
                    if(isupper(word[j]) != 0)
                    {

                        new_word = ((word[j]-39)+int_key)%26;
                        printf("%s", upper_let[new_word]);
                    }
                    if(islower(word[j]) != 0)
                    {
                        new_word = ((word[j]-71)+int_key)%26;
                        printf("%s", lower_let[new_word]);
                    }
                }
                if(isalpha(word[j]) == 0)
                {
                    printf("%c", word[j]);
                }
            }
            printf("\n");
        }
    }
}
