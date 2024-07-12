// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

int count_word = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node *n = table[hash(word)];
    while(n != NULL)
    {
        if(strcasecmp(n->word,word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return (toupper(word[0]) - 'A')%26;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE* source = fopen(dictionary, "r");
    if(source == NULL)
    {
        printf("no file read!");
        return false;
    }
    char word[LENGTH + 1];
    while(fscanf(source, "%s", word) != EOF)
    {
        int n = hash(word);
        count_word += 1;
        node *new_node = malloc(sizeof(node));
        new_node->next = NULL;
        strcpy(new_node->word,word);
        if(table[hash(word)] == NULL) //when hash table does not store anything address we then assign the first word struct for it to point to
        {
            table[hash(word)] = new_node;
        }
        else
        {
            new_node->next=table[hash(word)];
            table[hash(word)] = new_node;
        }
    }
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count_word;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++) //iterate through all the array to clear the malloc in all the arrays
    {
        node *ptr = table[i];
        while(ptr != NULL)
        {
            node *tmp = ptr->next;
            free(ptr);
            ptr = tmp;
        }
        table[i] = NULL;
    }
    return true;
}
