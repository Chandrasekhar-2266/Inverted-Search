/*#include "header.h"

int save(hash_t *arr, char *str) {
    // Check if hash table is NULL
    if (arr == NULL) {
        printf("Error: Hash table (arr) is NULL\n");
        return FAILURE;
    }

    printf("Attempting to open file: %s\n", str);
    FILE *ptr = fopen(str, "w");  // Open file for writing
    if (ptr == NULL) {
        perror("File opening failed");
        return FAILURE;
    }
    printf("File opened successfully: %s\n", str);

    // Iterate over the hash table indices (0-26)
    for (int i = 0; i < 27; i++) {
        if (arr[i].h_link == NULL) {  // Skip empty indices
            
            continue;
        }
        mainnode *temp_main = arr[i].h_link;  // Get the first main node

        while (temp_main != NULL) {
            if (temp_main->word == NULL) {  // Ensure word is not NULL
                printf("Error: temp_main->word is NULL\n");
                break;
            }
            // Write main node details to file
            fprintf(ptr, "#%d;", i);  // Index
            fprintf(ptr, "%s;", temp_main->word);  // Word
            fprintf(ptr, "%d;", temp_main->filecount);  // File count
            fflush(ptr);  // Ensure data is written immediately

            subnode *temp_sub = temp_main->sublink;  // Get first subnode
            while (temp_sub != NULL) {
                if (temp_sub->filename == NULL) {  // Ensure filename is not NULL
                    printf("Error: temp_sub->filename is NULL\n");
                    break;
                }
                

                // Write subnode details to file
                fprintf(ptr, "%d;", temp_sub->wordcount);  // Word count
                fprintf(ptr, "%s;", temp_sub->filename);  // Filename
                fflush(ptr);

                temp_sub = temp_sub->link2;  // Move to next subnode
            }

            fprintf(ptr, "#\n");  // End of main node entry
            fflush(ptr);
            temp_main = temp_main->link1;  // Move to next main node
        }
    }

    fclose(ptr);  // Close file
    return SUCCESS;
}
#include "header.h"

int save(hash_t *arr, char *str) {
    // Check if hash table is NULL
    if (arr == NULL) {
        printf("Error: Hash table (arr) is NULL\n");
        return FAILURE;
    }

    printf("Attempting to open file: %s\n", str);
    FILE *ptr = fopen(str, "w");  // Open file for writing
    if (ptr == NULL) {
        perror("File opening failed");
        return FAILURE;
    }
    printf("File opened successfully: %s\n", str);

    // Iterate over the hash table indices (0-26)
    for (int i = 0; i < 27; i++) {
        if (arr[i].h_link == NULL) {  // Skip empty indices
            continue;
        }
        mainnode *temp_main = arr[i].h_link;  // Get the first main node

        while (temp_main != NULL) {
            if (temp_main->word == NULL) {  // Ensure word is not NULL
                printf("Error: temp_main->word is NULL\n");
                break;
            }
            // Write main node details to file
            fprintf(ptr, "#%d;", i);  // Index
            fprintf(ptr, "%s;", temp_main->word);  // Word
            fprintf(ptr, "%d;", temp_main->filecount);  // File count

            subnode *temp_sub = temp_main->sublink;  // Get first subnode
            while (temp_sub != NULL) {
                if (temp_sub->filename == NULL) {  // Ensure filename is not NULL
                    printf("Error: temp_sub->filename is NULL\n");
                    break;
                }
                // Write subnode details to file
                fprintf(ptr, "%d;", temp_sub->wordcount);  // Word count
                fprintf(ptr, "%s;", temp_sub->filename);  // Filename

                temp_sub = temp_sub->link2;  // Move to next subnode
            }

            fprintf(ptr, "#\n");  // End of main node entry
            temp_main = temp_main->link1;  // Move to next main node
        }
    }

    fclose(ptr);  // Close file
    return SUCCESS;
}
#include "header.h"

int save(hash_t *arr, char *str) {
    // Check if hash table is NULL
    if (arr == NULL) {
        printf("Error: Hash table (arr) is NULL\n");
        return FAILURE;
    }

    printf("Attempting to open file: %s\n", str);
    FILE *ptr = fopen(str, "w");  // Open file for writing
    if (ptr == NULL) {
        perror("File opening failed");
        return FAILURE;
    }
    printf("File opened successfully: %s\n", str);

    // Iterate over the hash table indices (0-26)
    for (int i = 0; i < 27; i++) {
        if (arr[i].h_link == NULL) {  // Skip empty indices
            continue;
        }
        mainnode *temp_main = arr[i].h_link;  // Get the first main node
        printf("Processing index: %d\n", i);  // Debugging print

        while (temp_main != NULL) {
            if (temp_main->word == NULL) {  // Ensure word is not NULL
                printf("Error: temp_main->word is NULL\n");
                break;
            }
            printf("Processing word: %s\n", temp_main->word);  // Debugging print

            // Write main node details to file
            fprintf(ptr, "#%d;", i);  // Index
            fprintf(ptr, "%s;", temp_main->word);  // Word
            fprintf(ptr, "%d;", temp_main->filecount);  // File count

            subnode *temp_sub = temp_main->sublink;  // Get first subnode
            printf("Processing subnodes for word: %s\n", temp_main->word);  // Debugging print

            while (temp_sub != NULL) {
                if (temp_sub->filename == NULL) {  // Ensure filename is not NULL
                    printf("Error: temp_sub->filename is NULL\n");
                    break;
                }
                // Write subnode details to file
                fprintf(ptr, "%d;", temp_sub->wordcount);  // Word count
                fprintf(ptr, "%s;", temp_sub->filename);  // Filename

                temp_sub = temp_sub->table_link;  // Move to next subnode
            }

            fprintf(ptr, "#\n");  // End of main node entry
            temp_main = temp_main->link1;  // Move to next main node
        }
    }

    fclose(ptr);  // Close file
    return SUCCESS;
}
*/
#include "header.h"

int save(hash_t *arr, char *str) {
    // Check if hash table is NULL
    if (arr == NULL) {
        printf("Error: Hash table (arr) is NULL\n");
        return FAILURE;
    }

    printf("Attempting to open file: %s\n", str);
    FILE *ptr = fopen(str, "w");  // Open file for writing
    if (ptr == NULL) {
        perror("File opening failed");
        return FAILURE;
    }
    printf("File opened successfully: %s\n", str);

    // Iterate over the hash table indices (0-26)
    for (int i = 0; i < 27; i++) {
        if (arr[i].h_link == NULL) {  // Skip empty indices
            continue;
        }

        mainnode *temp_main = arr[i].h_link;  // Get the first main node

        while (temp_main != NULL) {
            if (temp_main->word == NULL) {  // Ensure word is not NULL
                printf("Error: temp_main->word is NULL\n");
                break;
            }
            // Write main node details to file
            fprintf(ptr, "#%d;", i);  // Index
            fprintf(ptr, "%s;", temp_main->word);  // Word
            fprintf(ptr, "%d;", temp_main->filecount);  // File count
            fflush(ptr);  // Ensure data is written immediately

            subnode *temp_sub = temp_main->sublink;  // Get first subnode
            while (temp_sub != NULL) {
                if (temp_sub->filename == NULL) {  // Ensure filename is not NULL
                    printf("Error: temp_sub->filename is NULL\n");
                    break;
                }

                // Write subnode details to file
                fprintf(ptr, "%d;", temp_sub->wordcount);  // Word count
                fprintf(ptr, "%s;", temp_sub->filename);  // Filename
                fflush(ptr);

                temp_sub = temp_sub->link2;  // Move to next subnode
            }

            fprintf(ptr, "#\n");  // End of main node entry
            fflush(ptr);
            temp_main = temp_main->link1;  // Move to next main node
        }
    }

    fclose(ptr);  // Close file
    return SUCCESS;
}

