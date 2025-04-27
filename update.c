#include "header.h"

// Function to update the hash table using backup file data
int updata(hash_t *arr, char *back_str, Slist **head)
{
    // Opening the backup file in read mode
    FILE *ptr1 = fopen(back_str, "r");
    if (ptr1 == NULL)
    {
        perror("File opening failed");
        return FAILURE;
    }

    // Checking if the file is a valid backup file (must start and end with '#')
    char frist;
    fscanf(ptr1, "%c", &frist); // Read first character
    char last;
    fseek(ptr1, 0, SEEK_END);   // Move to end of file
    fseek(ptr1, -2, SEEK_CUR);  // Move two characters back (to ignore EOF)
    fscanf(ptr1, "%c", &last);  // Read last character

    if (frist == '#' && last == '#')
    {
        printf("INFO: It is a backup file\n");
    }
    
    rewind(ptr1); // Reset file pointer to the beginning

    int index = -1;
    char buffer1[50]; // To store words
    int file_count = -1;
    int word_count = -1;
    char buffer2[50]; // To store filenames

    // Reading main node details from backup file
    while (fscanf(ptr1, "#%d;%[^;];%d;", &index, buffer1, &file_count) != EOF)
    {
        // Allocating memory for a new main node
        mainnode *main = malloc(sizeof(mainnode));
        main->filecount = file_count;  // Assigning file count
        strcpy(main->word, buffer1);   // Copying word data
        main->link1 = NULL;            // Initializing main node links
        main->sublink = NULL;

        // Inserting main node into the hash table
        if (arr[index].h_link == NULL)
        {
            arr[index].h_link = main; // If empty, insert as first node
        }
        else
        {
            mainnode *temp_main = arr[index].h_link;
            mainnode *prev_main = NULL;
            while (temp_main != NULL) // Traverse to the end of the list
            {
                prev_main = temp_main;
                temp_main = temp_main->link1;
            }
            if (prev_main == NULL)
            {
                temp_main->link1 = main;
            }
            else
            {
                prev_main->link1 = main;
            }
        }

        // Processing subnodes for the main node
        for (int i = 0; i < file_count; i++)
        {
            fscanf(ptr1, "%d;%[^;];", &word_count, buffer2); // Read subnode details

            // Removing the file from linked list if it exists
            Slist *temp = *head, *prev = NULL;
            while (temp)
            {
                if (strcmp(temp->str, buffer2) == 0)
                {
                    if (prev)
                        prev->link = temp->link; // Bypass the node
                    else
                        *head = temp->link; // Update head if first node is removed
                    free(temp); // Free memory
                    break;
                }
                prev = temp;
                temp = temp->link;
            }

            // Allocating memory for subnode and inserting it
            subnode *sub = malloc(sizeof(subnode));
            sub->wordcount = word_count; // Assigning word count
            strcpy(sub->filename, buffer2); // Storing filename
            sub->link2 = NULL; // Initializing subnode link

            if (main->sublink == NULL)
            {
                main->sublink = sub; // Insert as first subnode
            }
            else
            {
                subnode *temp_sub = main->sublink;
                subnode *prev_sub = NULL;
                while (temp_sub != NULL) // Traverse to end of subnode list
                {
                    prev_sub = temp_sub;
                    temp_sub = temp_sub->link2;
                }
                if (prev_sub == NULL)
                {
                    temp_sub->link2 = sub;
                }
                else
                {
                    prev_sub->link2 = sub;
                }
            }
            fscanf(ptr1, "#\n"); // Move to the next main node entry
        }
    }

    fclose(ptr1); // Closing the file
    return SUCCESS;
}
