#ifndef SIMULATION_H
#define SIMULATION_H
typedef struct cell
{
    int col;
    int row;
    int value;
} Cell;

typedef struct simulation
{
    int **map;
    int rows;
    int cols;
    int MAX_ITERATION;
    float sleep_seconds; /* Sleep in seconds */
} Simulation;

void start_simulation(Simulation *simulation);
void update_simulation(Simulation *simulation);
#endif