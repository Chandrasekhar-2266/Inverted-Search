#include "header.h"

// Function to initialize the hash table
int createhash(hash_t *arr, mainnode **mainnode1, subnode **subnode1)
{
    // Initializing each index of the hash table
    for (int i = 0; i <= 26; i++)
    {
        arr[i].index = i; // Assigning index
        arr[i].h_link = NULL; // Setting link to NULL initially
    }
    return 0;
}

int main(int argc, char *argv[])
{
	int f3=1;
    // Checking if enough arguments are provided
    if ( argc <= 1 )
    {
        printf("Enter valid arguments\n");
        printf("program <.txt> <.txt>\n");
        return 0;
    }

    Slist *head = NULL; // Initializing the linked list head
    int flag1 = 0; // Flag to track database creation
    int flag2 = 0; // Flag to track database update

    int i = 1;

	  if ( validate_file( &head, argv ) == SUCCESS )
	{
	 printf ("Read and validate SUCCESSFUL\n");// Argument index
      printf("INFO : Files: ");
    print_list(head); // Printing the list of files

    // Initializing hash table and database structures
    hash_t arr[26];
    mainnode *mainnode = NULL;
    subnode *subnode = NULL;
    createhash(arr, &mainnode, &subnode); // Creating hash table
	//if(f3==1)
	// printf ("1.Create Database\n2.Display Database\n3.Search Database\n4.Save Database\n5.Update Database\n6.EXIT\n");
        

    // Menu loop for database operations
    // hash_t arr[26];

    while (1)
    {
		if(f3==1)
        printf ("1.Create Database\n2.Display Database\n3.Search Database\n4.Save Database\n5.Update Database\n6.EXIT\n");
        int choice;
        printf("Enter the choice: ");
        __fpurge(stdin); // Clearing input buffer (non-standard function)
        scanf("%d", &choice);

        if (choice < 1 || choice > 6) // Validating user input
        {
            printf("Enter a valid choice (1-6)\n");
            continue; // Prompt again if invalid
        }
        else
        {
            char str2[50]; // Buffer for search string
            char file[50]; // Buffer for file name
            Slist *temp1 = head; // Temporary pointer for linked list traversal
            char str1[50]; // Buffer for reading words from file

            switch (choice)
            {
            case 1: // Create Database
                if (flag1 == 1 && flag2 == 0)
                {
                    printf("It is not possible\n");
                }
                else 
                {
                    flag1 = 1; // Setting database creation flag
                    while (temp1 != NULL)
                    {
                        FILE *ptr1 = fopen(temp1->str, "r"); // Opening file
                        if (ptr1 == NULL)
                        {
                            printf("INFO : File does not exist: %s\n", temp1->str);
                            break;
                        }
                        while (fscanf(ptr1, "%s", str1) != EOF) // Reading words from file
                        {
                            createdata_base(arr, temp1->str, str1); // Storing words in database
                        }
                        if (temp1 != NULL)
                            temp1 = temp1->link; // Moving to next file
                    }
                    printf("INFO : Database created successfully\n");
                }
                break;

            case 2: // Display Database
                display(arr);
                printf("INFO : Displayed successfully\n");
                break;

            case 3: // Search Database
                printf("Enter word:");
                scanf("%s", str2);
                sreach(arr, str2);
                printf("INFO : Search completed successfully\n");
                break;

            case 4: // Save Database
                printf("Enter the filename:");
                scanf("%s", file);
                if (strstr(file, ".txt") == NULL || strcmp(strchr(file, '.'), ".txt") != 0)
                {
                    printf("INFO : Invalid File name\n");
                }
                else
                {
                    save(arr, file); // Saving database to file
                    printf("INFO : Data saved successfully\n");
                }
                break;

            case 5: // Update Database
                if (flag1 == 1 || flag2 == 1)
                {
                    printf("It is not possible\n");
                }
                else 
                {
                    flag2 = 1; // Setting database update flag
                    printf("Enter the backup file:");
                    scanf("%s", str2);
                    if ((strstr(str2, ".txt") == NULL || strcmp(strchr(str2, '.'), ".txt") != 0))
                    {
                        printf("INFO: Invalid File name\n");
                    }
                    else
                    {
                        updata(arr, str2, &head); // Updating database
                        printf("INFO : Updated successfully\n");
                    }
                }
                break;

            case 6: // Exit program
                return SUCCESS; // Return success code

            default:
                printf("Enter a valid choice \n");
                break;
            }
        }
    }
	}
    else
    {
        printf("Read and Validation are fail\n");
        return 0;
    }
}

// Function to insert a file name at the end of the linked list
int insert_at_last(Slist **head, char *str1)
{
    Slist *new = malloc(sizeof(Slist)); // Allocating memory for new node

    if (new == NULL) // Checking memory allocation success
    {
        return FAILURE;
    }

    strcpy(new->str, str1); // Storing file name
    new->link = NULL;       // Setting link to NULL

    if (*head == NULL)      // If list is empty, set head to new node
    {
        *head = new;
        return SUCCESS;
    }

    Slist *temp = *head;       // Temporary pointer to traverse list
    while (temp->link != NULL) // Traverse till the last node
    {
        temp = temp->link;
    }

    temp->link = new; // Link last node to new node
    return SUCCESS;
}

// Function to print the linked list
void print_list(Slist *head)
{
    if (head == NULL)
    {
        printf("INFO : List is empty  exit and give valid files /only.txt files\n");
    }
    else
    {
        while (head)
        {
            printf("%s -> ", head->str);
            head = head->link;
        }
        printf("NULL\n");
    }
}
int validate_file(Slist **head, char *argv[])
{
    int count = 0;// Count of valid files
    int i = 1;      // Starting index of command-line arguments
    while (argv[i] != NULL)  // Loop through all provided file names
    {
		if ( strstr(argv[i], ".txt") == NULL || strcmp(strrchr(argv[i], '.'), ".txt") != 0)
		{
			printf("%s is  not a .txt file \n", argv[i]);
			i++;
			continue;
		}
        int ret = empty_file_or_not(argv[i]);  // Check if the file is empty or available
        if (ret == FILE_NOT_AVAILABLE)  // If file doesn't exist
        {
            printf("%s is not present in current directory\n", argv[i]);
        }
        else if (ret == FILE_EMPTY)  // If file is empty
        {
            printf("%s Data in file is not present\n", argv[i]);
        }
        else  // If the file is valid
        {
            int ret_val = insert_at_last(head, argv[i]); // Adding file to the list
                              // Add file to the list
            if (ret_val == SUCCESS)  // File added successfully
            {
                count++;
                printf("Successfully inserted %s into file linked list\n", argv[i]);
            }
            else if (ret_val == REPEATED_FILE)  // If file is repeated
            {
                printf("%s is repeated. Don't add that one\n", argv[i]);
            }
            else  // Failure in adding the file
            {
                printf("Failure\n");
            }
        }
        i++; 
	// Move to the next file
    }
    if (count >= 1)  // If at least one file was successfully validated
        return SUCCESS;
    else  // If no files were validated
        return FAILURE;
	
}


// Check if a file is empty or not
int empty_file_or_not(char *file_name)
{
	
    FILE *fptr = fopen(file_name, "r");  // Open file in read mode
    if (fptr == NULL)  // If file does not exist
    {
        return FILE_NOT_AVAILABLE;
    }
    fseek(fptr, 0, SEEK_END);  // Move to the end of the file
    if (ftell(fptr) == 0)  // If the file size is 0, it is empty
    {
        return FILE_EMPTY;
    }
    return SUCCESS;  // File is available and not empty
}
