#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays
 * @array: Original array
 * @left: Left subarray start index
 * @mid: Middle index
 * @right: Right subarray end index
 * @temp: Temporary array for merging
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *temp)
{
	size_t i = left, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];

	while (j < right)
		temp[k++] = array[j++];

	for (i = 0; i < k; i++)
		array[left + i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, k);
}

/**
 * merge_sort_recursive - Recursively sorts array using merge sort
 * @array: Array to sort
 * @left: Left index
 * @right: Right index
 * @temp: Temporary array
 */
void merge_sort_recursive(int *array, size_t left, size_t right, int *temp)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;

	merge_sort_recursive(array, left, mid, temp);
	merge_sort_recursive(array, mid, right, temp);
	merge(array, left, mid, right, temp);
}

/**
 * merge_sort - Sorts an array using merge sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort_recursive(array, 0, size, temp);
	free(temp);
}
