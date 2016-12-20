/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"


/**
 * Returns true if word is in dictionary else false.
 */
 
int dic_size = 0; 
 
typedef struct node
    {
        char word[LENGTH + 1];
        struct node* next;
    } node; 

node* table[NUM_BINS] = { NULL };

bool check(const char* word)
{
    int letters = strlen(word);
    char lowerWord[strlen(word)+1];
    lowerWord[letters] = '\0';
    
    for (int i = 0; i < letters; i++)
    {
        if(isalpha(word[i]))
        {
            lowerWord[i] = tolower(word[i]);
        }
        else
        {
            lowerWord[i] = word[i];
        }
    }
    
    unsigned int hashkey = hash(lowerWord);
    node* head = table[hashkey];
    
    while (head != NULL)
    {
        if (strcmp(lowerWord, head->word) == 0)
        {
            return true;
        }
        else
        {
            head = head->next;
        }
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE *inputFile = fopen(dictionary, "r");
    node* head = NULL; 
    
    if(inputFile == NULL)
    {
        return false;
    }
    
   // read until the end of the dictionary
   while(true)
    {  
        node* newNode = malloc(sizeof(node));
        
        if (fscanf(inputFile, "%s", newNode->word)!= 1)
        {
            free(newNode);
            break;
        }
        
        unsigned int hashkey = hash(newNode->word);
       
        if (table[hashkey] == NULL)
        {
            table[hashkey] = newNode;
            head = table[hashkey];  
            head->next = NULL;              
            dic_size++;
        }
        else
        {
            head = table[hashkey];
            newNode->next = head;
            table[hashkey] = newNode;
            dic_size++;
        }
   }
   fclose(inputFile);
   return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dic_size;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    //for each entry in the table...
    for (int i = 0; i < NUM_BINS; i++)
    {
        // get the head of the list
        node* newNode= table[i];

        // walk over the entire list and free all the nodes
        while (newNode != NULL)
        {
            // grab a reference to the next node (we'll need this in a sec)
            node* temp = newNode;
            newNode = newNode->next;

            // free the current node and its associated data
            free(temp);
        }
    }
    return true;
}

unsigned int hash(char *str)
{
    unsigned int hash = 5381;
    int c = 0;

    while ((c = *str++) != 0)
    {
        hash = (((hash << 5) + hash) + c);
    }
    
    return hash % NUM_BINS;
}