#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"
#include "macros.h"
#include "simulation.h"
#include "arrays.h"

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
        strcpy(result.error_message, "usage: <map_file.txt> <steps_amount> <sleep_duration>");
    }
    else if (argc > 4)
    {
        result.is_error = TRUE;
        strcpy(result.error_message, "usage: <map_file.txt> <steps_amount> <sleep_duration>");
    } else if(atoi(argv[2]) < 0) {
        result.is_error = TRUE;
        strcpy(result.error_message, "error: steps_amount cannot be a negative number ");
    } else if(atof(argv[3]) < 0) {
        result.is_error = TRUE;
        strcpy(result.error_message, "error: sleep_duration cannot be a negative number ");
    }

    return result;
}

/**
 * Parses and populates the GameInput struct with input arguments
 * @param argv Array of command line arguments
 * @returns OperationResult
 */

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
 * Reads the map file and sets the properties of Input
 * @param filename Name of the file to read
 * @param simulation Pointer to Input
 * @returns OperationResult
 * */
OperationResult read_map_file(char *filename, Simulation *simulation)
{
    OperationResult op_result = {FALSE, ""};

    FILE *fptr;

    /* Open file*/
    fptr = fopen(filename, "r");
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
            int i, j;
            /* Read the first line, which is the size of the map*/
            fscanf(fptr, "%d %d", &simulation->rows, &simulation->cols);

            /* Create the 2d array for the map */
            simulation->map = create_2d_array(simulation->rows, simulation->cols, FALSE);

            /* Read the rest of the file and populate the map array*/

            for (i = 0; i < simulation->rows; i++)
            {
                for (j = 0; j < simulation->cols; ++j)
                {
                    fscanf(fptr, "%d", &simulation->map[i][j]);
                }
            }
        }
        fclose(fptr);
    }

    return op_result;
}

/**
 * Reads the input arguments, loads the map file and parses the input arguments
 * @param argv Command line arguments
 * @param simulation The simulation struct
 * @returns OperationResult
 */
OperationResult parse_args(char **argv, Simulation *simulation)
{

    OperationResult op_result = read_map_file(argv[1], simulation);

    if (op_result.is_error == FALSE)
    {
        simulation->MAX_ITERATION = atoi(argv[2]);
        simulation->sleep_seconds = atof(argv[3]);
    }
    return op_result;
}
