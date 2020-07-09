#include "menger.h"
/**
 * rotate - rotate 90 degress
 *
 * @p: pointer to matrix
 * @S: size of the matrix
 * Return: no return
 */
void rotate(char **p, int S)
{
	int i, j, tmp;

	for (i = 0; i < S / 2; i++)
	{
		for (j = i; j < S - i - 1; j++)
		{

			tmp = p[i][j];
			p[i][j] = p[S - 1 - j][i];
			p[S - 1 - j][i] = p[S - 1 - i][S - 1 - j];
			p[S - 1 - i][S - 1 - j] = p[j][S - 1 - i];
			p[j][S - 1 - i] = tmp;
		}
	}
}
/**
 * finallyfree - free memory
 * @i: interator
 * @p: pointer
 */

void finallyfree(char **p, int i)
{
	int j;

	for (j = 0; j < i; j++)
	{
		free(p[j]);
	}
	free(p);
}
/**
 * alloc_grid - concatenates two strings
 *
 * @width: width array
 * @height: height array
 * Return: pointer to 2D array
 */
char **alloc_grid(int width, int height)
{
	char **p;
	int i, j;

	if (width > 0 && height > 0)
	{
		p = (char **)malloc(sizeof(char *) * height);
		if (p == NULL)
			return (NULL);
		for (i = 0; i <  height; i++)
		{
			p[i] = (char *)malloc((width) * sizeof(char));
			if (p[i] == NULL)
			{
				finallyfree(p, i);
				return (0);
			}
			for (j = 0; j < width; j++)
			{
				p[i][j] = 35;
			}
		}
		return (p);
	}
	return (NULL);
}
/**
 * hole_maker - makes a hole in the middle
 *
 * @size: size of the matrix
 * @p_test: pointer to test
 * @size_test: size to test
 * @p: pointer to matrix
 * Return: no return
 */
char **hole_maker(char **p, int size, char **p_test, int size_test)
{
	int hole, i, j, k;

	hole = size / 3;

	for (i = hole; i < 2 * hole; i++)
	{
		for (j = hole; j < 2 * hole; j++)
			p[j][i] = 32;

	}
	if (size > 1)
	{
		for (k = 0; k < 3; k++)
		{
			hole_maker(p + k * (size / 3), size / 3, p_test, size_test);
			rotate(p + k * (size / 3), size / 3);
			hole_maker(p + k * (size / 3), size / 3, p_test, size_test);
			rotate(p + k * (size / 3), size / 3);
			hole_maker(p + k * (size / 3), size / 3, p_test, size_test);
			rotate(p + k * (size / 3), size / 3);
			hole_maker(p + k * (size / 3), size / 3, p_test, size_test);
			rotate(p + k * (size / 3), size / 3);
		}

	}
	return (p);
}
/**
 * menger - prints 2d merger sponge
 *
 * @level: depth - level
 *
 * Return: no return
 */
void menger(int level)
{
	int size, i, j;
	char **p;

	if (level < 0)
		exit(0);
	if (level == 0)
	{
		printf("#\n");
		exit(0);
	}
	size = pow(3, level);
	p = alloc_grid(size, size);
	hole_maker(p, size, p, size);
	rotate(p, size);
	hole_maker(p, size, p, size);
	rotate(p, size);
	hole_maker(p, size, p, size);
	rotate(p, size);
	hole_maker(p, size, p, size);
	rotate(p, size);
	hole_maker(p, size, p, size);
	/*print_grid(p, size);*/
	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size; i++)
			printf("%c", p[j][i]);
		printf("\n");
	}
	finallyfree(p, size);
}
