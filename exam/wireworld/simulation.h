#ifndef SIMULATION_H
#define SIMULATION_H

typedef struct simulation
{
    int **map;
    int rows;
    int cols;
    int MAX_ITERATION;
    float sleep_seconds; /* Sleep in seconds */
} Simulation;

void start_simulation(Simulation *simulation);
#endif