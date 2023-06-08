#include <stdlib.h>
#include <stdio.h>
#include "simulation.h"
#include "color.h"
#include "newSleep.h"
#include "arrays.h"

/**
 * Prints the wireworld simulation
 * @param simulation The simulation struct
 */
void print_simulation(Simulation *simulation)
{

    int i, k;

    for (i = 0; i < simulation->rows; i++)
    {
        for (k = 0; k < simulation->cols; k++)
        {
            switch (simulation->map[i][k])
            {
            case 1: /* head */
                setBackground("blue");
                break;
            case 2: /* tail */
                setBackground("red");
                break;
            case 3: /* conductor */
                setBackground("yellow");
                break;
            default: /* empty cell */
                setBackground("black");
                break;
            }

            /* Print two spaces to make a square */
            printf("  ");
            /* Reset background color */
            setBackground("reset");
        }
        printf("\n");
    }
}

/**
 * Creates a Moore neighborhood matrix for a specified cell in the simulation map
 * which lists the values of the adjacent cells
 * @param cell_row Which row the cell is on
 * @param cell_col Which column the cell is on
 * @param simulation The simulation struct
 * @param matrix_size The size of the adjacency matrix
 * @returns 2D int array representing the Moore neighborhood
 */
int **adjacency_matrix_for_cell(int cell_row, int cell_col, Simulation *simulation, int matrix_size)
{

    int i, k;
    int matrix_row = 0;
    int matrix_col = 0;
    /* Create and malloc the adjacency matrix, filling it with zero*/
    int **adjacency_matrix = create_2d_array(matrix_size, matrix_size, TRUE);

    /*
    This algorithm works like this:

    If the cell we want to check is at (3, 4), we want to check all the surrounding cells

    We want to check the row -1, row and row + 1. Visualized like this:
    Row -1 -> 0  0  0
    Row    -> 0  c  0  (c is the current cell)
    Row +1 -> 0  0  0

    The same is done with the columns, we check column -1, column and column +1. Visualized like this:
    -1  0 +1
    ---------
     0  0  0
     0  c  0
     0  0  0

     So, an iteration looks like this (cell is located at (3,4) )

     1: Row: 2 Cell: 3
     2: Row: 2 Cell: 4  Row - 1
     3: Row: 2 Cell: 5

     4: Row: 3 Cell: 3
     5: Row: 3 Cell: 4  <-- This is the location of the cell (3,4)
     6: Row: 3 Cell: 5

     4: Row: 4 Cell: 3
     5: Row: 4 Cell: 4 Row + 1
     6: Row: 4 Cell: 5

     This gets all the cells that is directly adjacent to the cell
    */
    for (i = cell_row - 1; i <= cell_row + 1; i++)
    {
        for (k = cell_col - 1; k <= cell_col + 1; k++)
        {
            /* Checks if we are not out of bounds. This can happen if a cell is at i.e row 0 and we try to check
               row - 1 (-1)
            */
            if ((i >= 0 && i < simulation->rows) && (k >= 0 && k < simulation->cols))
            {
                /* The adjacency matrix is already filled with zero, we only care about head, tail or conductor */
                if (simulation->map[i][k] > 0)
                {
                    adjacency_matrix[matrix_row][matrix_col] = simulation->map[i][k];
                }
            }
            /* Jump to the next column in the adjacency matrix*/
            matrix_col++;
        }
        /* Reset matrix column index and jump to the next row*/
        matrix_col = 0;
        matrix_row++;
    }

    return adjacency_matrix;
}

/**
 * Gets the number of heads adjacent in a adjacency matrix
 * @param matrix The adjacency matrix for a cell
 * @param matrix_size The size of the adjacency matrix
 * @returns The number of heads adjacent
 */
int adjacent_head_count(int **matrix, int matrix_size)
{
    int count = 0;
    int i, k;

    for (i = 0; i < matrix_size; i++)
    {
        for (k = 0; k < matrix_size; k++)
        {
            if (matrix[i][k] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

/**
 * Updates the simulation on each tick with the next move
 * @param simulation The simulation struct
 */
void update_simulation(Simulation *simulation)
{
    int i, k;
    /* To keep the integrity of the actual game map when calculating the next movements in the simulation tick,
    we create a identical temporary 2d array to apply our changes to. Once all changes are done, we can commit the temp array to the actual map array
    */
    int **temp_map = create_2d_array(simulation->rows, simulation->cols, FALSE);
    /* Copy the contents of the map array to the temp array */
    copy_2d_int_array(simulation->map, temp_map, simulation->rows, simulation->cols);

    for (i = 0; i < simulation->rows; i++)
    {
        for (k = 0; k < simulation->cols; k++)
        {
            int **adjacency_matrix;
            int adjacent_heads;
            /* Check the cell value in the actual simulation map*/
            switch (simulation->map[i][k])
            {
            case 1:
                /* If the cell in the map array is a head, replace it with a tail in the temp map
                Because every cell where a head is should turn into a tail in the next iteration
                */
                temp_map[i][k] = 2;
                break;
            case 2: /* If the cell is a tail, replace it with a conductor */
                temp_map[i][k] = 3;
                break;
            case 3:
                /* If the cell is a conductor, we want to check how many heads are adjacent to it
                 */
                /* First we create the adjacency matrix */
                adjacency_matrix = adjacency_matrix_for_cell(i, k, simulation, 3);
                /* Then get the amount of heads found in the adjacency matrix */
                adjacent_heads = adjacent_head_count(adjacency_matrix, 3);

                /* If the amount of heads adjacent is either 1 or 2, the conductor will become a head
                Otherwise it will remain a conductor
                */
                if (adjacent_heads == 1 || adjacent_heads == 2)
                {
                    /* Set a head at the current location in the temp map*/
                    temp_map[i][k] = 1;
                }

                /* Free adjacency matrix */
                free_2d_int_array(adjacency_matrix, 3);
                break;
            }
        }
    }
    /* Replace the simulation map with the updated temporary map*/
    copy_2d_int_array(temp_map, simulation->map, simulation->rows, simulation->cols);
    free_2d_int_array(temp_map, simulation->rows);
}

/**
 * Starts the simulation and runs it for the specifed amount of iterations
 * @param simulation The simulation struct
 */
void start_simulation(Simulation *simulation)
{

    int i;

    for (i = 0; i < simulation->MAX_ITERATION; i++)
    {

        /* Print the map */
        print_simulation(simulation);
        /* Update the simulation for this tick */
        update_simulation(simulation);
        /* Sleep for the specified amount of seconds */
        newSleep(simulation->sleep_seconds);
        system("clear");
    }
}