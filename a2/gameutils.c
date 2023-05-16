#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "terminal.h"
#include "macros.h"
#include "linkedlist.h"

/**
 * Disables terminal input buffering and echoing in order to immediately
 * get user input. Input buffering means that it will store what you write into a buffer
 * before sending it to the program by pressing Enter
 * Echoing means that the termnial will display what the user is actually writing as they type
 * @public
 * @returns character that was pressed by the user
 */
char get_input()
{
    char c;

    disableBuffer();
    scanf(" %c", &c);
    enableBuffer();
    return c;
}

/**
 * Checks if the player is next to the box and wants to move towards the box
 * @private
 * @param map Pointer to the game map
 * @param row The row to check if out of bounds
 * @param col The column to check if out of bounds
 * @returns 0 for FALSE, 1 for TRUE
 */
int is_wall(Map *map, int row, int col)
{
    return map->map[row][col] == 'O';
}
/**
 * Checks if the next position is out of bounds
 * @private
 * @param map Pointer to the game map
 * @param row The row to check if out of bounds
 * @param col The column to check if out of bounds
 * @returns 0 for FALSE, 1 for TRUE
 */
int is_oob(Map *map, int row, int col)
{
    return row < 0 || row >= map->rows || col < 0 || col >= map->columns;
}

/**
 *  Checks if box is next to player
 *  @param map Pointer to the game map
 *  @param direction Which direction we want to check if the box is located at
 * @public
 * @returns 0 for FALSE, 1 for TRUE
 * */
int is_box_adjacent(Map *map, Direction direction)
{
    int is_adjacent = FALSE;
    switch (direction)
    {
    case UP:
        /* If the box is above the player*/
        if (map->player_pos.row - 1 == map->box_pos.row && map->player_pos.col == map->box_pos.col)
        {
            is_adjacent = TRUE;
        }
        break;
    case DOWN:
        /* If the box is under the player*/
        if (map->player_pos.row + 1 == map->box_pos.row && map->player_pos.col == map->box_pos.col)
        {
            is_adjacent = TRUE;
        }
        break;
    case LEFT:
        /* If the box is to the left of the player */
        if (map->player_pos.col - 1 == map->box_pos.col && map->player_pos.row == map->box_pos.row)
        {
            is_adjacent = TRUE;
        }

        break;
    case RIGHT:
        /* If the box is to the right of the player*/
        if (map->player_pos.col + 1 == map->box_pos.col && map->player_pos.row == map->box_pos.row)
        {
            is_adjacent = TRUE;
        }
        break;
    default:
        break;
    }

    return is_adjacent;
}

/**
 *
 * Checks if the potential move would be out of bounds
 *   If the player is next to the box and the box is by the border,
 *   the player cannot move in that direction as the box would be out of bounds
 * Additionally, it checks if the player is trying to push the box into a wall or walk into one
 *  @public
 *  @param map Pointer to the game map
 *  @param direction The direction the player want to me to
 *  @param box_adjacent If the player is next to the box and wants to move towards the box
 *  @returns 0 for FALSE, 1 for TRUE
 */
int is_move_oob(Map *map, Direction direction, int box_adjacent)
{
    int oob = FALSE;
    switch (direction)
    {
    case UP:
        /* If the player moves one row up  */
        /* Check if move is oob, which means the box or player would go outside map border
        and then check if the player is trying to push the box into a wall or walk into one
        */
        if (is_oob(map, map->player_pos.row - 1, map->player_pos.col) ||
            (box_adjacent == TRUE && is_oob(map, map->player_pos.row - 2, map->player_pos.col)) ||
            is_wall(map, map->player_pos.row - 1, map->player_pos.col) ||
            (box_adjacent == TRUE && is_wall(map, map->player_pos.row - 2, map->player_pos.col)))
        {
            oob = TRUE;
        }
        break;
    case DOWN:
        /* If the player moves one row down */
        if (is_oob(map, map->player_pos.row + 1, map->player_pos.col) ||
            (box_adjacent == TRUE && is_oob(map, map->player_pos.row + 2, map->player_pos.col)) ||
            is_wall(map, map->player_pos.row + 1, map->player_pos.col) ||
            (box_adjacent == TRUE && is_wall(map, map->player_pos.row + 2, map->player_pos.col)))
        {
            oob = TRUE;
        }
        break;
    case LEFT:
        /* If the player moves one column left */
        if (is_oob(map, map->player_pos.row, map->player_pos.col - 1) ||
            (box_adjacent == TRUE && is_oob(map, map->player_pos.row, map->player_pos.col - 2)) ||
            is_wall(map, map->player_pos.row, map->player_pos.col - 1) ||
            (box_adjacent == TRUE && is_wall(map, map->player_pos.row, map->player_pos.col - 2)))
        {
            oob = TRUE;
        }
        break;
    case RIGHT:
        /* If the player moves one column right */
        if (is_oob(map, map->player_pos.row, map->player_pos.col + 1) ||
            (box_adjacent == TRUE && is_oob(map, map->player_pos.row, map->player_pos.col + 2)) ||
            is_wall(map, map->player_pos.row, map->player_pos.col + 1) ||
            (box_adjacent == TRUE && is_wall(map, map->player_pos.row, map->player_pos.col + 2)))
        {
            oob = TRUE;
        }
        break;
    default:
        break;
    }

    return oob;
}

/**
 * Undos the last move made by the player
 * @public
 * @param map Pointer to the game map
 * @param object Pointer to the object that was moved
 */
void undo_move(Map *map)
{
    if (ll_is_empty(map->move_history) != TRUE)
    {
        Node *lastNode;
        Move *move;
        /* Removes the last node in the move history and gets the data*/
        lastNode = ll_remove_last(map->move_history);
        move = (Move *)lastNode->data;

        /* move.to is now the position we are moving from. We set the previous character (old_char) at this position */
        map->map[move->to->row][move->to->col] = move->old_char;
        /* move.from is the position we wanto move to. Here we set the equivalent character to the object we are moving at this position */
        map->map[move->from->row][move->from->col] = move->object_char;
        /* Update the objects's position. This will be a pointer to the our map struct*/
        move->object->row = move->from->row;
        move->object->col = move->from->col;

        if (move->leave_trail == TRUE)
        {
            if (map->trail_map[move->to->row][move->to->col] > 'T')
            {
                map->trail_map[move->to->row][move->to->col] -= 1;
            }
            else
            {

                map->trail_map[move->to->row][move->to->col] = ' ';
            }
        }

        /* Recursively undo moves of chained moves. The top node will be freed last as it unwinds the recursion stack */
        if (move->is_chained == TRUE)
        {
            undo_move(map);
        }
        /* Free removed node and old move*/
        free(move->from);
        free(move->to);
        free(lastNode->data);
        free(lastNode);
    }
}

/**
 * Handles the actual moving of the object on the map
 * @private
 * @param map The game map 
 * @param move The move that is to be processed on the map
 * @param replacement Which character should be placed at the old position of the object
 */
void move_handler(Map *map, Move *move, char replacement)
{

    move->old_char = map->map[move->to->row][move->to->col];
    /* Sets the current position to the replacement char, either G or ' '*/
    map->map[move->from->row][move->from->col] = replacement;
    /*Sets the char at the new position */
    map->map[move->to->row][move->to->col] = move->object_char;
    if (move->leave_trail)
    {

        if (map->trail_map[move->to->row][move->to->col] >= 'T')
        {
            /* If the box overlaps its tail, we need to signal this. We just increment the char to the next ASCII char
               and when undoing, we will decrement until the char is equal to T again
            */
            map->trail_map[move->to->row][move->to->col] += 1;
        }
        else
        {
            map->trail_map[move->to->row][move->to->col] = 'T';
        }
    }
}

/**
 * Moves a point object the specified direction on the map. Does not do any checks
 * on whether the move would be out of bounds
 * @public
 * @param map A pointer to the map we are playing on
 * @param direction The direction in which the object should be moved, can be UP, DOWN, LEFT or RIGHT
 * @param c The char that should be set at the new position
 * @param object A pointer to an object on the map, like the player or box. This will be updated with the new posotion
 * @param link_prevous_move Whether or not the move should be linked to the previous move in the move history
 * @param leave_trail Whether or not the move should leave a trail on the map
 *
 * @returns void
 */
void move(Map *map, Direction direction, char c, Point *object, int link_previous_move, int leave_trail)
{
    /* Which character we should set at the old position of the object
        If the old position was the goal, we want to make sure we set the G back to its spot
        This will only happen if the player moves to the position of the goal
    */
    char replacement = object->col == map->goal_pos.col && object->row == map->goal_pos.row ? 'G' : ' ';
    /* Initialize movement structs that will be stored in the move history linked list*/
    Move *move = (Move *)malloc(sizeof(Move));
    Point *old_pos = (Point *)malloc(sizeof(Point));
    Point *new_pos = (Point *)malloc(sizeof(Point));
    old_pos->col = object->col;
    old_pos->row = object->row;
    move->from = old_pos;
    move->to = new_pos;
    /* Specify the object that is to be moved and its character*/
    move->object = object;
    move->object_char = c;

    /* Is chained tells if this move is chained to the previous move.
    If the player moves the box, the player move will be chained to the box move (we move the box before the player
    so the player move will be last in the list and be chained to the box move)
    */
    move->is_chained = link_previous_move;
    
    move->leave_trail = leave_trail;
    switch (direction)

    {
    case UP:
        /* Set the new position */
        new_pos->row = object->row - 1;
        new_pos->col = object->col;
        /* Perform the actual move */
        move_handler(map, move, replacement);
        /* Updates the object position*/
        object->row -= 1;
        /* Insert the move into the box history*/
        ll_insert_last(map->move_history, move);
        break;
    case DOWN:
        new_pos->row = object->row + 1;
        new_pos->col = object->col;
        move_handler(map, move, replacement);
        object->row += 1;
        ll_insert_last(map->move_history, move);
        break;
    case LEFT:
        new_pos->row = object->row;
        new_pos->col = object->col - 1;
        move_handler(map, move, replacement);
        object->col -= 1;
        ll_insert_last(map->move_history, move);
        break;
    case RIGHT:
        new_pos->row = object->row;
        new_pos->col = object->col + 1;
        move_handler(map, move, replacement);
        object->col += 1;
        ll_insert_last(map->move_history, move);
        break;

    default:
        break;
    }
}
