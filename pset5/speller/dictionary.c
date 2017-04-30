/**
 * Implements a dictionary's functionality.
 *
 * Pset 5
 * CS50
 * Mohammed Attya
 *
 * @GitHub mohammedattya2
 *
 * MIT Licence
 *
 * OpenSource OpenMind
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"


// define struct for value-pointer pair, i.e., a node
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// make an array of pointer of size HASHTABLE_SIZE
node* hashtable[HASHTABLE_SIZE];

// global variable for tracking dictionary size
unsigned int word_count = 0;

// global boolean for tracking load/unload dictionary operations
bool loaded = false;

// make a hash table
int hash(char* to_hash)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(to_hash); i<n; i++)
        hash = (hash << 2) ^ to_hash[i];
    return hash % HASHTABLE_SIZE;
}

/**
 * Returns true if word is in dictionary else false. Case-insensitive.
 * Assume that check is only passed strings with alphabetical characters and/or
 * apostrophes.
 */
bool check(const char* word)
{
    int len = strlen(word);
    char word_copy[len + 1];

    // convert to lowercase
    for (int i = 0; i < len; i++)
    {
       word_copy[i] = tolower(word[i]);
    }

    // add null terminator to end of char array
    word_copy[len] = '\0';

    // get hash value
    int h = hash(word_copy);

    node* ptr = hashtable[h];

    // check until the end of the linked list
    while (ptr != NULL)
    {
        if (strcmp(ptr->word, word_copy) == 0)
        {
            // word is in dictionary
            return true;
        }
        else
        {
            // check next node
            ptr = ptr->next;
        }
    }
    return false;
}

/**
 * Loads dictionary into memory. Stores words in hash table. Returns true if
 * successful else false.
 */
bool load(const char* dictionary)
{
    // make all hash table elements NULL
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    // open dictionary
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }

    while (true)
    {
        // malloc a node for each new word
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Could not malloc a new node.\n");
            return false;
        }

        // read a word from the dictionary and store it in new_node->word
        fscanf(fp, "%s", new_node->word);
        new_node->next = NULL;

        if (feof(fp))
        {
            // hit end of file
            free(new_node);
            break;
        }

        word_count++;

        // hashtable[h] is a pointer to a key-value pair
        int h = hash(new_node->word);
        node* head = hashtable[h];

        // if bucket is empty, insert the first node
        if (head == NULL)
        {
            hashtable[h] = new_node;
        }

        else
        {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
        }
    }
    // close file
    fclose(fp);
    loaded = true;
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (loaded)
    {
        return word_count;
    }
    else
    {
        return 0;
    }
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node* ptr = hashtable[i];
        while (ptr != NULL)
        {
            // copy pointer before free
            node* temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
    loaded = false;
    return true;
}
