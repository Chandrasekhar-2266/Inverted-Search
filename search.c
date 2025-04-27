#include "header.h"

int sreach(hash_t *arr, char *str)
{
    int ind;

    // Determine the index based on the first character of the word
    if (str[0] >= 'A' && str[0] <= 'Z')
    {
        ind = str[0] - 'A';
    }
    else if (str[0] >= 'a' && str[0] <= 'z')
    {
        ind = str[0] - 'a';
    }
    else
    {
        ind = 26; // Special index for non-alphabetic words
    }

    // Check if there are any words at this index
    if (arr[ind].h_link == NULL)
    {
        printf("Word is not present\n");
        return FAILURE;
    }
    else
    {
        mainnode *temp_mainnode = (mainnode *)arr[ind].h_link; // Get the first main node

        while (temp_mainnode != NULL) // Traverse the main node list
        {
            if (strcmp(temp_mainnode->word, str) == 0) // Word match found
            {
                printf("The word \"%s\" is present in \"%d\" file(s).\n",temp_mainnode->word,temp_mainnode->filecount);
                // printf("File Count: %d\n", temp_mainnode->filecount);
                // printf("Word: %s\n", temp_mainnode->word);

                subnode *temp_sub = temp_mainnode->sublink; // Get the first subnode
                while (temp_sub != NULL) // Traverse the subnode list
                {
                    printf("In \"%s\" for \"%d\" times.\n",temp_sub->filename,temp_sub->wordcount);

                    temp_sub = temp_sub->link2; // Move to the next subnode
                }
                return SUCCESS; // Word found and displayed
            }

            temp_mainnode = temp_mainnode->link1; // Move to the next main node
        }
        
        printf("Word is not present\n");
        return FAILURE; // Word not found in the list
    }
}
