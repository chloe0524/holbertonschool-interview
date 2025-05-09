#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * get_max - Finds the maximum number in an array
 * @array: The array of integers
 * @size: The size of the array
 * Return: The maximum integer in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		max = (array[i] > max) ? array[i] : max;
	return (max);
}

/**
 * counting_sort - Performs counting sort based on a significant digit
 * @array: The array of integers
 * @size: The size of the array
 * @exp: The current significant digit (1, 10, 100, ...)
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;
	int j;
	ssize_t k;

	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];

	for (k = size - 1; k >= 0; k--)
	{
		output[count[(array[k] / exp) % 10] - 1] = array[k];
		count[(array[k] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers using the LSD radix sort algorithm
 * @array: The array of integers
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	}
}
