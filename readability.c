#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");
    // Count the number of letters, words, and sentences in the text
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    // Compute the Coleman-Liau index
    float avg_let = (letters/words)*100;
    float avg_sent = (sentences/words)*100;
    float index = 0.0588 * avg_let - 0.296 * avg_sent - 15.8;
    int grade = round(index);
    // Print the grade level
    if(grade < 1)
    {
        printf("Before Grade 1\n");
    }
    if(grade > 16)
    {
        printf("Grade 16+\n");
    }
    if(grade >= 1 && grade <= 16)
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int word_counter = 0;
    // Return the number of letters in text
    for(int i = 0; i < strlen(text); i++)
    {
        int s = text[i];
        if(s >= 65 && s <= 90)
        //this is to avoid the signs the text
        {
            word_counter += 1;
        }
        if(s >= 97 && s <= 122)
        {
            word_counter += 1;
        }
    }
    return(word_counter);
}

int count_words(string text)
{
    int word_counter = 1;
    // Return the number of words in text
    for(int j = 0; j < strlen(text); j++)
    {
        int word = text[j];
        if(word == 32)
        {
            word_counter += 1;
        }
    }
    return(word_counter);
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int sentence_counter = 0;
    // Return the number of words in text
    for(int k = 0; k < strlen(text); k++)
    {
        int symbol = text[k];
        if(symbol == 33)
        {
            sentence_counter += 1;
        }
        if(symbol == 46)
        {
            sentence_counter += 1;
        }
        if(symbol == 63)
        {
            sentence_counter += 1;
        }
    }
    return(sentence_counter);
}

