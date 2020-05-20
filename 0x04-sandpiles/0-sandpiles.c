#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - prints grid.
 *
 * @grid: grid to print.
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - checks if sand pile is stable
 *
 * @grid: grid to check.
 * Return: 1 if stable 0 if not.
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * sandpiles_simple_sum - sums sandpiles.
 *
 * @grid1: grid1.
 * @grid2: grid2.
 * The simple sand pile sum (without topping).
 */

void sandpiles_simple_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, c = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			c = grid1[i][j] + grid2[i][j];
			grid2[i][j] = c;
			grid1[i][j] = c;
		}
	}
}

/**
 * sandpiles - computes the sum of two sandpiles
 * @grid1: are individually stable
 * @grid2: are individually stable
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0, first_time = 0, run = 1;
	int n = 2;

	while (run)
	{
		run = 0;
		for (i = 0; i < 3; ++i)
		{
			for (j = 0; j < 3; ++j) {
				if (first_time == 0)
					grid1[i][j] += grid2[i][j];
				else
				{
					if (grid1[i][j] > 3)
					{
						grid1[i][j] -= 4;
						if  ((n - i) == 2)
							grid1[i + 1][j] += 1;
						else if ((n - i) == 0)
							grid1[i - 1][j] += 1;
						else
						{
							grid1[i + 1][j] += 1;
							grid1[i - 1][j] += 1;
						}

						if  ((n - j) == 2)
							grid1[i][j + 1] += 1;
						else if ((n - j) == 0)
							grid1[i][j - 1] += 1;
						else
						{
							grid1[i][j + 1] += 1;
							grid1[i][j - 1] += 1;
						}
					}
				}
				if (grid1[i][j] > 3)
					run = 1;
			}
		}
		first_time ++;
		printf("=\n");
		print_grid(grid1);
	}
}
