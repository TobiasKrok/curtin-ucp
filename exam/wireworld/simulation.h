#ifndef SIMULATION_H
#define SIMULATION_H

typedef struct simulation
{
    int **map;
    int rows;
    int cols;
    int MAX_ITERATION;
    float sleep_ms;
} Simulation;
void print_simulation(Simulation *simulation);
#endif