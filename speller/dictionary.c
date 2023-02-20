// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    countword = 0;
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return 0;
    }
    char words[LENGTH + 1];
    while (fscanf(file,"%s",words) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 0;
        }
        strcpy(node -> word, words);
    }
    int h = hash(words);
    if (table[h] == NULL)
    {
        n -> next = NULL;
        table -> next = n;
    }
    else
    {
        n -> next = table[h] -> next;
        table[h] -> = n -> next;
    }
    countword++;

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
