#ifndef VALIDATION_H
#define VALIDATION_H
/* Struct for the validation result for input validation
    is_error will be TRUE/FALSE
    error_message is a string that i.e main can print when validating input
 */
typedef struct validation_result
{
    int is_error;
    char *error_message;
} ValidationResult;

/* Struct for the input provided by user, makes it easier to work with rather than accessing argv using brackets
Everything is const as they should not be changed during runtime.
*/

typedef struct input
{
    int MAP_ROW;
    int MAP_COL;
    int PLAYER_ROW;
    int PLAYER_COL;
    int GOAL_ROW;
    int GOAL_COL;
} GameInput;

ValidationResult *validate_args(int argc, const GameInput input);
void free_validation_result(ValidationResult *result);
GameInput *map_argv_to_game_input(int *argv);
void create_string(char **destination, char *string);
int within_bounds(int high, int low, int n);

#endif