#ifndef _MUL_H
#define _MUL_H
#include <stdlib.h>
int _putchar(char c);
void print_answer(int *answer, int size_h);
void sum_up(int *sum[], int *answer, int size_h, int size_v);
void fill_zeros(int *sum[], int size_v, int size_h);
void to_number(char argv[], int size, int n[]);
void mul_line(int n1, int *n2, int size, int size_v, int **sum, int level);
void error(void);
int check_number(char *argv[], int lens[]);
#endif
