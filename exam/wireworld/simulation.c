#include <stdlib.h>
#include <stdio.h>
#include "simulation.h"
#include "color.h"

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

void start_simulation(Simulation simulation) {
    
}