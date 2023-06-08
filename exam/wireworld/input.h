#ifndef INPUT_H
#define INPUT_H

#include "macros.h"
#include "simulation.h"

/* Struct for the validation result for input validation
    is_error will be TRUE/FALSE
    error_message is a string that i.e main can print when validating input
 */
typedef struct result
{
    Bool is_error;
    char error_message[1000];
} OperationResult;

OperationResult validate_args(int argc, char **argv);
OperationResult parse_args(char **argv, Simulation *input);
#endif