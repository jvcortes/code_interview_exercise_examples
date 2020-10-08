#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * slide_line - Slides and merges the integers inside an array, in the same
 * way as the game "2048"
 * @line: Array of integers
 * @size: Size of the array
 * @direction: Direction in which the elements of the array will be merged
 *
 * Return: Non-zero value if the elements of the array are merged successfully.
 */
int slide_line(int *line, size_t size, int direction)
{
	int hold, x, increase, stop;
	
		if (size < 2)
			return (1);
	
		x = direction == SLIDE_RIGHT ? size - 2 : 1;
		hold = direction == SLIDE_RIGHT ? size - 1 : 0;
		stop = direction == SLIDE_RIGHT ? -1 : size;
		increase = direction == SLIDE_RIGHT ? -1 : 1;

		for (; x != stop; x += increase)
			if (line[x] != 0)
			{
				if (line[x] == line[hold])
				{
					line[x] = 0;
					line[hold] *= 2;
					hold += increase;
				}
				else if (line[hold] == 0)
				{
					line[hold] = line[x];
					line[x] = 0;
				}
				else
					hold += increase;
				if (x + increase == stop && line[x] != 0 && line[hold] == 0)
				{
					line[hold] = line[x];
					line[x] = 0;
				}
			}
		return (1);
}
