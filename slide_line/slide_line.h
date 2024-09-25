#ifndef SLIDELINES
#define SLIDELINES

/* LIBRARIES */

#include <stddef.h>

#define SLIDE_LEFT  0
#define SLIDE_RIGHT 1

/* PROTOTYPES */

int slide_line(int *line, size_t size, int direction);
void reverse_arr(int *line, size_t size);

#endif
