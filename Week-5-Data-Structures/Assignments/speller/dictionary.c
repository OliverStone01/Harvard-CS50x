// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1126;

// Hash table
node *table[N] = {NULL};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // get hash value of word
    int hash_value = hash(word);

    // create a node to search and compare to
    node *ptr = table[hash_value];

    while (ptr != NULL)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    int a = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalnum(word[i]))
        {
            a = ((toupper(word[i])) - 'A');
            sum += a;
        }
        else if (word[i] == 39)
        {
            a = word[i];
            sum += a;
        }
    }
    return sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict != NULL)
    {
        int index = 0;
        char word[LENGTH + 1];

        char c;
        while (fread(&c, sizeof(char), 1, dict))
        {
            // Allow only alphabetical characters and apostrophes
            if (isalpha(c) || (c == '\'' && index > 0))
            {
                // Append character to word
                word[index] = c;
                index++;

                // Ignore alphabetical strings too long to be words
                if (index > LENGTH)
                {
                    // Consume remainder of alphabetical string
                    while (fread(&c, sizeof(char), 1, dict) && isalpha(c))
                        ;

                    // Prepare for new word
                    index = 0;
                }
            }

            // Ignore words with numbers (like MS Word can)
            else if (isdigit(c))
            {
                // Consume remainder of alphanumeric string
                while (fread(&c, sizeof(char), 1, dict) && isalnum(c))
                    ;

                // Prepare for new word
                index = 0;
            }

            // We must have found a whole word
            else if (index > 0)
            {
                // Terminate current word
                word[index] = '\0';

                int hashing = hash(word);
                insert(hashing, word);

                index = 0;
            }
        }
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // create an int for the count
    int word_count = 0;
    int n = 1126;
    // make a for loop that goes over each bucket.
    for (int i = 0; i < n; i++)
    {
        node *temp = table[i];

        while (temp != NULL)
        {
            word_count++;
            temp = temp->next;
        }
    }
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    int n = 1126;
    for (int i = 0; i < n; i++)
    {
        node *temp = table[i];
        while (temp != NULL)
        {
            node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    return true;
}

bool insert(int key, const char *word)
{
    node *new_word = malloc(sizeof(node));
    if (new_word == NULL)
    {
        return false;
    }

    strcpy(new_word->word, word);
    new_word->next = NULL;

    // check for empty list in table at key.
    if (table[key] == NULL)
    {
        table[key] = new_word;
    }
    else
    {
        node *temp = table[key];

        while (true)
        {
            if (temp->next == NULL)
            {
                temp->next = new_word;
                break;
            }

            temp = temp->next;
        }
    }
    return true;
}
