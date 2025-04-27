#include "header.h"

int createdata_base(hash_t *arr, char *single, char *str)
{
    int ind;
    if (str[0] >= 'A' && str[0] <= 'Z') // Check if first character is uppercase
    {
        ind = str[0] - 'A'; // Convert to index (0-25)
    }
    else if (str[0] >= 'a' && str[0] <= 'z') // Check if first character is lowercase
    {
        ind = str[0] - 'a'; // Convert to index (0-25)
    }
    else
    {
        ind = 26; // Assign index for non-alphabetic characters
    }

    int w_count = 1; // Initialize word count
    int f_count=1;
    // If no main node exists at this index, create a new one
    if (arr[ind].h_link == NULL)
    {
        mainnode *main = malloc(sizeof(mainnode)); // Allocate memory for main node
        if (main == NULL)
        {
            printf("Memory allocation failed for main node\n");
            return 1;
        }
        main->filecount = f_count; // Store file count
        strcpy(main->word, str); // Store word
        main->link1 = NULL;
        main->sublink = NULL;
        arr[ind].h_link = main; // Store main node in hash table

        subnode *sub = malloc(sizeof(subnode)); // Allocate memory for subnode
        if (sub == NULL)
        {
            printf("Memory allocation failed for sub node\n");
            return 1;
        }
        sub->wordcount = w_count; // Initialize word count
        strcpy(sub->filename, single); // Store filename
        sub->link2 = NULL;
        main->sublink = sub; // Link subnode to main node
        return SUCCESS;
    }

    mainnode *temp_mainnode = arr[ind].h_link; // Get first main node
    mainnode *prev_main = NULL;

    while (temp_mainnode != NULL)
    {
        prev_main = temp_mainnode;
        if (strcmp(temp_mainnode->word, str) == 0) // If word already exists
        {
            subnode *temp_sub = temp_mainnode->sublink;
            subnode *prev_sub = NULL;

            while (temp_sub != NULL)
            {
                prev_sub = temp_sub;
                if (strcmp(temp_sub->filename, single) == 0) // If filename already exists
                {
                    ++(temp_sub->wordcount);  // Increment word count
                    return SUCCESS;
                }
                temp_sub = temp_sub->link2;
            }
            f_count++;
            temp_mainnode->filecount = f_count; // Update file count
            subnode *sub = malloc(sizeof(subnode)); // Allocate memory for subnode
            if (sub == NULL)
            {
                printf("Memory allocation failed for sub node\n");
                return 1;
            }
            sub->wordcount = w_count; // Initialize word count
            strcpy(sub->filename, single); // Store filename
            sub->link2 = NULL;

            if (prev_sub != NULL)
            {
                prev_sub->link2 = sub; // Add new subnode to the end of sublist
            }
            else
            {
                temp_mainnode->sublink = sub; // Add subnode as first entry
            }
            return SUCCESS;
        }
        
        temp_mainnode = temp_mainnode->link1; // Move to next main node
    }

    // Create new main node if word not found
    mainnode *main = malloc(sizeof(mainnode)); // Allocate memory for new main node
    if (main == NULL)
    {
        printf("Memory allocation failed for main node\n");
        return 1;
    }
    main->filecount = f_count; // Store file count
    strcpy(main->word, str); // Store word
    main->link1 = NULL;
    main->sublink = NULL;
    prev_main->link1 = main; // Link new main node

    subnode *sub = malloc(sizeof(subnode)); // Allocate memory for new subnode
    if (sub == NULL)
    {
        printf("Memory allocation failed for sub node\n");
        return 1;
    }
    sub->wordcount = w_count; // Initialize word count
    strcpy(sub->filename, single); // Store filename
    sub->link2 = NULL;
    main->sublink = sub; // Link subnode to main node

    return SUCCESS;
}
