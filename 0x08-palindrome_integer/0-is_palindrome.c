#include "palindrome.h"
/**
 * is_palindrome - Check if an integer is palindrome
 * @n: is the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int size = 0;
	unsigned long array_n[11];
	unsigned long aux_n = n / 10;
	int i = 0;
	int j = 0;

	array_n[size] = n % 10;

	while (aux_n != 0)
	{
		size++;
		array_n[size] = aux_n % 10;
		aux_n = aux_n / 10;
	}
	j = size;
	for (i = 0; i <= size / 2; i++)
	{
		if (array_n[i] != array_n[j])
			return (0);
		j--;
	}
	return (1);
}
