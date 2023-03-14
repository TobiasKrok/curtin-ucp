#ifndef MACROS_H
#define MACROS_H
#define FALSE 0
#define TRUE !FALSE

#define BETWEEN(low, high, value) (((low <= value) && (value <= high)) ? TRUE : FALSE)

#endif