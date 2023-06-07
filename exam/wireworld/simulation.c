#include <stdlib.h>
#include <stdio.h>
#include "simulation.h"
#include "color.h"
#include "newSleep.h"

void print_simulation(Simulation *simulation)
{

    int i, k;

    for (i = 0; i < simulation->rows; i++)
    {
        for (k = 0; k < simulation->cols; k++)
        {
            switch (simulation->map[i][k])
            {
            case 1: /* */
                setBackground("blue");
                break;
            case 2:
                setBackground("red");
                break;
            case 3:
                setBackground("yellow");
                break;
            default:
                setBackground("black");
                break;
            }
            printf("  ");
            setBackground("reset");
        }
        printf("\n");
    }
}

void start_simulation(Simulation *simulation)
{

    int i;

    for (i = 0; i < simulation->MAX_ITERATION; i++)
    {

        print_simulation(simulation);
        update_simulation(simulation);
        newSleep(simulation->sleep_seconds);
    }
}

Cell **adjacency_matrix_for_cell(int cell_row, int cell_col, Simulation *simulation, int matrix_size)
{
    Cell **adjacency_matrix = (Cell **)malloc(matrix_size * sizeof(Cell *));
    int i, k;
    int matrix_row = 0;
    int matrix_col = 0;
    Cell invalid_cell = {-1, -1, -1};

    for (i = 0; i < matrix_size; i++)
    {
        adjacency_matrix[i] = (Cell *)malloc(matrix_size * sizeof(Cell));
    }

    for (i = 0; i < matrix_size; i++)
    {
        for (k = 0; k < matrix_size; k++)
        {
            adjacency_matrix[i][k] = invalid_cell;
        }
    }

    for (i = cell_row - 1; i <= cell_row + 1; i++)
    {
        for (k = cell_col - 1; k <= cell_col + 1; k++)
        {
            if ((i >= 0 && i < simulation->rows) && (k >= 0 && k < simulation->cols))
            {
                if (simulation->map[i][k] > 0)
                {
                    Cell valid_cell;
                    valid_cell.row = i;
                    valid_cell.col = k;
                    valid_cell.value = simulation->map[i][k];
                    adjacency_matrix[matrix_row][matrix_col] = valid_cell;
                }
            }

            matrix_col++;
        }
        matrix_col = 0;
        matrix_row++;
    }

    return adjacency_matrix;
}

int adjacent_conductors_count(Cell **matrix, int matrix_size)
{
    int count = 0;
    int i, k;
    for (i = 0; i < matrix_size; i++)
    {
        for (k = 0; k < matrix_size; k++)
        {
            if (matrix[i][k].value == 3)
            {
                count++;
            }
        }
    }
    return count;
}

Cell *get_adjacent_conductors(Cell **matrix, int matrix_size, int conductor_count)
{
    Cell *adjacent_conductors = (Cell *)malloc(sizeof(Cell) * conductor_count);
    int i, k;
    int count = 0;
    for (i = 0; i < matrix_size; i++)
    {
        for (k = 0; k < matrix_size; k++)
        {
            if (matrix[i][k].value == 3)
            {
                adjacent_conductors[count] = matrix[i][k];
                count++;
            }
        }
    }
    return adjacent_conductors;
}

void update_simulation(Simulation *simulation)
{
    int i, k;

    for (i = 0; i < simulation->rows; i++)
    {
        for (k = 0; k < simulation->cols; k++)
        {
            if (simulation->map[i][k] == 1 || simulation->map[i][k] == 2)
            {
                int conductor_count;

                Cell **adjacency_matrix = adjacency_matrix_for_cell(i, k, simulation, 3);
                switch (simulation->map[i][k])
                {
                case 1:
                    conductor_count = adjacent_conductors_count(adjacency_matrix, 3);
                    if (conductor_count > 0 && conductor_count < 3)
                    {
                        int j;

                        Cell *conductors = get_adjacent_conductors(adjacency_matrix, 3, conductor_count);

                        for (j = 0; j < conductor_count; j++)
                        {
                            simulation->map[conductors[j].row][conductors[j].col] = 1;
                        }
                        simulation->map[i][k] = 3;
                    }
                    break;

                default:
                    break;
                }
            }
            /*           int j, l;
                      for (j = 0; j < 3; j++)
                      {
                          for (l = 0; l < 3; l++)
                          {
                              printf("%d ", adjacency_matrix[j][l]);
                          }
                          printf("\n");
                      }
                      printf("\n"); */
        }
    }
}
