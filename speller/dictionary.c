// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>



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
int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashh = hash(word);

    node *current = table[hashh];
    while (current != NULL)
    {
        if (strcasecmp(current -> word, word) == 0)
        {
            return true;
        }
        current = current -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int value = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        value += tolower(word[i]);
    }
    return (value % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Dictionary does not exist.\n");
        return false;
    }
    char str[LENGTH + 1];
    while (fscanf(file, "%s", str) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n ->word, str);
        int hashh = hash(str);

        if (table[hashh] == NULL)
        {
            n -> next = NULL;
        }
        else
        {
            n -> next = table[hashh];
        }
        table[hashh] = n;
        count += 1;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *h = table[i];
        node *current = h;
        node *tmp = h;
        while (current != NULL)
        {
            current = current -> next;
            free(tmp);
            tmp = current;
        }
    }
    return true;
}
