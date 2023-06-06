#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"
#include "macros.h"


/**
 * Validates the arguments passed to the program
 * @param argc Number of arguments
 * @param argv Array of arguments
 * @returns OperationResult
 * */
OperationResult validate_args(int argc, char **argv)
{
    /* Initialize the validation result*/
    OperationResult result = {FALSE, ""};

    /* Total arguments should be 1 + 1 (executable name)*/
    if (argc < 4)
    {
        result.is_error = TRUE;
        strcpy(result.error_message, "usage: <map file.txt <cycle limit> <sleep duration>");
    }
    else if (argc > 2)
    {
        result.is_error = TRUE;
        strcpy(result.error_message, "usage: <map file.txt <cycle limit> <sleep duration>");
    }

    return result;
}

/**
 * Gets the length of a file
 * @param fptr File pointer
 * @returns length of the file
 * */
int get_file_len(FILE *fptr)
{
    int len = 0;
    /* Get the current position of the file pointer*/
    int curPos = ftell(fptr);
    /* Seek to the end of the file*/
    fseek(fptr, 0, SEEK_END);
    /* Get the current position of the file pointer, which is the length of the file*/
    len = ftell(fptr);
    /* Seek back to the original position using curPos as the offset*/
    fseek(fptr, curPos, SEEK_SET);
    return len;
}

/**
 * Reads the map file and sets the properties of GameInput
 * @param argv Array of arguments containing the file name
 * @param input Pointer to GameInput
 * @returns OperationResult
 * */
OperationResult read_map_file(char **argv, GameInput *input)
{
    OperationResult op_result = {FALSE, ""};

    FILE *fptr;

    /* Open file*/
    fptr = fopen(argv[1], "r");
    /* Check if the file is null, which indicates that the file could not be found*/
    if (fptr == NULL)
    {
        op_result.is_error = TRUE;
        strcpy(op_result.error_message, "ERROR: File not found");
    }
    else
    {
        int file_len = get_file_len(fptr);
        /* Check if the file is empty*/
        if (file_len == 0)
        {
            op_result.is_error = TRUE;
            strcpy(op_result.error_message, "ERROR: File is empty");
        }

        else /* Everything should be good so let's read the file*/
        {
            int n;
            int is_first_line = TRUE;

            /* Create an array of size 1, we will realloc it later*/
       
            while (n != EOF)
            {
                if (is_first_line)
                {
                    /* Read the first line, which is the size of the map*/
                    fscanf(fptr, "%d %d", &input->rows, &input->cols);
                    is_first_line = FALSE;
                }
                else
                {
                    /* Read the rest of the file and set the properties of GameInput*/
                 

                }
            }
        }
        fclose(fptr);
    }

    return op_result;
}