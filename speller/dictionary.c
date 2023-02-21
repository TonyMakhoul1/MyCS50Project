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
    int value = 0;
    for (int i = 0; word[i] = '\0'; i++)
    {
        value += tolower(word[i]);
    }
    return value / N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    int countword = 0;
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return 0;
    }
    char words[LENGTH + 1];
    while (fscanf(file, "%s", words) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(file);
            return 0;
        }
        strcpy(n -> word, words);
        int h = hash(words);
        if (table[h] -> next == NULL)
        {
            n -> next = NULL;
            table[h] -> next = n;
        }
        else
        {
            n -> next = table[h] -> next;
            table[h] -> next = n;
        }
        countword++;
    }
        fclose(file);
        return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        while (tmp != NULL)
        {
            counter++;
            tmp = tmp -> next;
        }
    }
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i];
            table[i] = table[i] -> next;
            free(table[i]);
        }
    }
    return return;
}
