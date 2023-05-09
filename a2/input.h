#ifndef INPUT_H
#define INPUT_H

/* Struct for the validation result for input validation
    is_error will be TRUE/FALSE
    error_message is a string that i.e main can print when validating input
 */
typedef struct result
{
    int is_error;
    char error_message[1000];
} OperationResult;

/* Contains the position of an object on the map */
typedef struct point
{
    int col;
    int row;
} Point;


typedef struct input
{
    Point box_pos;
    Point player_pos;
    Point goal_pos;
    Point* walls_pos; /*  Array of walls */
    int wall_size;
    int rows;
    int cols;
} GameInput;

typedef struct loadresult {
    OperationResult *result;
    GameInput *game_input;
} FileLoadResult;


FileLoadResult read_map_file(char* argv);
OperationResult validate_args(int argc, char* argv);
#endif