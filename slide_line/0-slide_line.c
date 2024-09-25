#include "slide_line.h"
#include "slide_line.h"

/**
 * reverse_arr - reverses an array of ints.
 * @line: pointer to array of ints.
 * @size: size of the array.
 */
void reverse_arr(int *line, size_t size)
{
	size_t i;
	int temp;

	for (i = 0; i < size / 2; i++)
	{
		temp = line[i];
		line[i] = line[size - 1 - i];
		line[size - 1 - i] = temp;
	}
}

/**
 * slide_line - slides and merges an array of ints to left or right.
 * @line: pointer to array of ints.
 * @size: size of the array.
 * @direction: direction to slide (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * Return: 1 or 0.
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, j;
	int white = 0;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_RIGHT)
		reverse_arr(line, size);

	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != white)
		{
			if (j > 0 && line[j - 1] == line[i])
			{
				line[j - 1] *= 2;
				line[i] = white;
			}
			else
			{
				if (j != i)
				{
					line[j] = line[i];
					line[i] = white;
				}
				j++;
			}
		}
	}

	if (direction == SLIDE_RIGHT)
		reverse_arr(line, size);

	return (1);
}
