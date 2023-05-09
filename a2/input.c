#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"
#include "macros.h"


OperationResult validate_args(int argc, char* argv) {
     /* Initialize the validation result*/
    OperationResult result = {FALSE, NULL};


    /* Total arguments should be 1 + 1 (executable name)*/
    if (argc < 2)
    {
        result.is_error = TRUE;
        strcpy(result.error_message, "usage: <map file.txt>");

    } else if (argc > 2) {
        result.is_error = TRUE;
        strcpy(result.error_message, "usage: <map file.txt>");
    }

    return result;
}

int get_file_len(FILE *file) {

    int curPos = ftell(file);
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, curPos, SEEK_SET);
    return size;
    
}

void *read_map_file(char* argv, GameInput *input, OperationResult *result) {

    /* Define structs for file reading
    Operation result will indicate if the reading was successful or not
    GameInput will contain input data 
    FileLoadResult is the overall struct containing this information
    */
    FILE *fptr;


    int file_len;


    /* Open file*/
    fptr = fopen(argv[1], 'r');
    /* Check if the file is null, which indicates that the file could not be found*/
    if(fptr == NULL) {
        op_result->is_error = TRUE;
        strcpy(&op_result->error_message, "Error opening file, check if the filename and path is correct");
    } else {
        int n;
        int is_first_line = TRUE;
        char line_content[3];
        file_len = get_file_len(fptr);
        /* We dont know how many walls there are, lets initialize the array with the total lenght of the file
        and we can realloc it later
        */
        input->walls_pos = (Point*)malloc(sizeof(Point) * file_len);
        while(n != EOF) {
            
        }
 
    }


    return flr;
}
