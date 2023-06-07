#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "macros.h"
#include "simulation.h"

int main(int argc, char **argv)
{

    OperationResult parse_args_result;
    Simulation *simulation = (Simulation *)malloc(sizeof(Simulation));
    /* Validate input and read map file */
    OperationResult validation_result = validate_args(argc, argv);

    if (validation_result.is_error == TRUE)
    {
        printf("%s\n", validation_result.error_message);
    }
    else
    {
        /* Attempt to parse the arguments*/
        parse_args_result = parse_args(argv, simulation);

        if (parse_args_result.is_error == TRUE)
        {
            printf("%s\n", parse_args_result.error_message);
        }
        /* Everything is good, let's start the simulation */
        else
        {
            start_simulation(simulation);
        }
    }

    return (parse_args_result.is_error == TRUE || validation_result.is_error == TRUE);
}