#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

// Define constants for success and failure return values
#define SUCCESS 0
#define FAILURE -1
#define FILE_EMPTY -2
#define FILE_NOT_AVAILABLE -3
#define REPEATED_FILE -4

/* Hash table structure */
typedef struct nod {
    int index;               // Index for the hash table (0-26 for alphabet, 1 for non-alphabet)
    struct node1 *h_link;    // Pointer to the first node (main node) in the hash table slot
} hash_t;

/* Singly linked list for storing strings (words) */
typedef struct node {
    char str[10];            // Word (maximum length 10)
    struct node *link;       // Pointer to the next node in the linked list
} Slist;

/* Main node structure that stores word information and links to subnodes (file-related data) */
typedef struct node1 {
    int filecount;           // Number of files the word appears in
    char word[20];           // The word itself
    struct node2 *sublink;   // Pointer to a list of subnodes (file details for the word)
    struct node1 *link1;     // Pointer to the next main node (for chaining in hash table)
} mainnode;

/* Subnode structure for storing word count and filename where the word appears */
typedef struct node2 {
    int wordcount;           // Count of the word in the file
    char filename[20];       // Name of the file where the word is found
    struct node2 *link2;     // Pointer to the next subnode (file details)
} subnode;

// Function declarations with their purpose in the program:

/* Validates the files provided by the user */
int validate_file(Slist **head, char *argv[]);  

/* Checks whether the file is empty or not */
int empty_file_or_not(char * file_name);

/* Inserts a string at the end of the singly linked list */
int insert_at_last(Slist **head, char * );

/* Prints the content of the singly linked list */
void print_list(Slist *head);

/* Creates a hash table and initializes it with mainnode and subnode */
int createhash(hash_t *arr, mainnode **mainnode, subnode **subnode);

/* Creates a database from the provided input */
int createdata_base(hash_t *arr, char *single, char *str);

/* Displays the content of the hash table */
int display(hash_t *arr);

/* Searches for a specific word in the hash table */
int sreach(hash_t *arr, char *str);

/* Saves the content of the hash table to a file */
int save(hash_t *arr, char *str);

/* Updates the hash table with data from a backup file */
int updata(hash_t *arr, char *back_str, Slist **head);

#endif  // End of header guard

