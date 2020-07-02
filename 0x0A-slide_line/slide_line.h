
#ifndef SLIDE_H
#define SLIDE_H
#define SLIDE_RIGHT 1
#define SLIDE_LEFT 0
#include <stdio.h>
int slide_line(int *line, size_t size, int direction);
int slide_line_left(int *line, size_t size);
int slide_line_right(int *line, size_t size);
#endif
