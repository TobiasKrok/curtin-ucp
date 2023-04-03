#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"
#include "macros.h"

/* Validates all the input provided by the user and returns a pointer to a validation result
    We need to free this after usage

*/
ValidationResult *validate_args(int argc, const GameInput input)
{

    /* Initialize the validation result*/
    ValidationResult *result = (ValidationResult *)malloc((sizeof(ValidationResult)));

    result->is_error = FALSE;
    result->error_message = NULL;

    /* Total arguments should be 6 + 1 (executable name)*/
    if (argc < 7)
    {
        result->is_error = TRUE;
        /* We need to add + 1 in the lenght to make space for null operator \0*/
        create_string(&result->error_message, "usage: <map_row> <map_col> <player_row> <player_col> <goal_row> <goal_col>");
    }
    /* If map rows/cols is within the specified bounds. MIN: 5 MAX: 100 */
    else if (within_bounds(MAP_MAX, MAP_MIN, input.MAP_ROW) == FALSE || within_bounds(MAP_MAX, MAP_MIN, input.MAP_COL) == FALSE)
    {
        result->is_error = TRUE;
        create_string(&result->error_message, "input error: map_row and map_col must be 5 or higher, and 100 or lower");
    }
    /* Checks if player row and col is within specified map bounds
        Player can not spawn at the border of the map, that is why we do - 1 to account for border
     */
    else if (within_bounds(input.MAP_ROW - 1, 1, input.PLAYER_ROW) == FALSE || within_bounds(input.MAP_COL - 1, 1, input.PLAYER_COL) == FALSE)
    {
        result->is_error = TRUE;
        create_string(&result->error_message, "input error: player_row and player_col cannot be higher or lower than map_row and map_col \n or on the map border");
    }
    /* Checks if GOAL row and col is within specified map bounds
      Goal can not spawn at the border of the map, that is why we do - 1 to account for border
   */
    else if (within_bounds(input.MAP_ROW - 1, 1, input.GOAL_ROW) == FALSE || within_bounds(input.MAP_COL - 1, 1, input.GOAL_COL) == FALSE)
    {
        result->is_error = TRUE;
        create_string(&result->error_message, "input error: goal_row and goal_col cannot be higher or lower than map_row and map_col \n or on the map border");
    }
    /* Cheks if the goal position is the same as player position*/
    else if (input.PLAYER_ROW == input.GOAL_ROW && input.PLAYER_COL == input.GOAL_COL)
    {
        result->is_error = TRUE;
        create_string(&result->error_message, "input error: goal_row and goal_col cannot overlap with player_row and player_col");
    }

    return result;
}

/* Creates a GameInput struct pointer from the passed arguments
     arg[0] = map_row
    arg[1] = map_col
    arg[2] = player_row
    arg[3] = player_col
    arg[4] = goal_row
    arg[5] = goal_col

    Must be freed
*/
const GameInput *map_argv_to_game_input(int *argv)
{
    GameInput *input = (GameInput *)malloc(sizeof(GameInput));
    input->MAP_ROW = argv[0];
    input->MAP_COL = argv[1];
    input->PLAYER_ROW = argv[2];
    input->PLAYER_COL = argv[3];
    input->GOAL_ROW = argv[4];
    input->GOAL_COL = argv[5];

    return input;
}

/* Simple helper function to verify that a number is within specified bounds*/
int within_bounds(int high, int low, int n)
{

    return n <= high && n >= low ? TRUE : FALSE;
}

/* Helper function to free validation results correctly. We got to free the error message string as well as the result itself*/
void free_validation_result(ValidationResult *result)
{
    free(result->error_message);
    free(result);
}

/* Helper function to create a string. We first malloc the passed string content then we copy the passed string
into the malloced memory using strcpy
  */
void create_string(char **destination, char *string)
{
    /* We do + 1 to allocate memory for null character \0 */
    *destination = (char *)malloc(strlen(string) + 1);
    strcpy(*destination, string);
}