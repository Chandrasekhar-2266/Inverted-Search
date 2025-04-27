#include "header.h"

int display(hash_t *arr)
{
    printf("[Index]\tWord\tFilecount\tFilename   Wordcount\n");
    for (int i = 0; i <= 26; i++) // Iterate through the hash table
    {
        if (arr[i].h_link != NULL) // Check if there is data at this index
        {
            //printf("Index: %d\n", i);

            mainnode *temp_main = (mainnode *)arr[i].h_link; // Get the first main node
            while (temp_main != NULL) // Traverse the main node list
            {
                printf("[%-2d]\t",i);
				printf("%-10s",temp_main->word);
				printf("%-10d\t",temp_main->filecount);
                //printf("File Count: %d\n", temp_main->filecount);
                //printf("Word: %s\n", temp_main->word);

                subnode *temp_sub = temp_main->sublink; // Get the first subnode
                while (temp_sub != NULL) // Traverse the subnode list
                {
                    printf("%-10s\t%-10d  ",temp_sub->filename,temp_sub->wordcount);
                    //printf("Word Count: %d\n", temp_sub->wordcount);
                    //printf("File Name: %s\n", temp_sub->filename);
                    temp_sub = temp_sub->link2; // Move to the next subnode
                }

                temp_main = temp_main->link1; // Move to the next main node
                printf("\n");
            }
        }
    }
    return SUCCESS; // Indicate successful execution
}
