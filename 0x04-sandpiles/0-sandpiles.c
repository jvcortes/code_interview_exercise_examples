#include <stdio.h>
#include "sandpiles.h"

#define DIRECTION_UP 0
#define DIRECTION_DOWN 1
#define DIRECTION_LEFT 2
#define DIRECTION_RIGHT 3

/**
 * print_grid - prints a 3x3 array of integers.
 * @grid: array to print
 *
 * Return: nothing
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
 * sandpiles_sum - sums two 3x3 sandpiles and displays its result.
 * @grid1: first grid
 * @grid2: second grid
 *
 * Return: nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int result[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			result[i][j] = grid1[i][j] + grid2[i][j];
	printf("=\n");
	print_grid(result);
	top(result, 1, 1, 1);
}

/**
 * is_unstable - checks if a 3x3 sandpile is unstable (contains a cell
 * holding more than three grains)
 *
 * @grid: grid to check
 *
 * Return: if the grid is unstable, a non-zero value is returned, otherwise,
 * the function will return zero.
 */
int is_unstable(int grid[3][3])
{

	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);

	return (0);
}


/**
 * topple - topples a 3x3 unstable sandpile at position x, y
 * @grid: grid to topple
 * @x: horizontal position in the grid
 * @y: vertical position in the grid
 * @center: start from the center of the grid, if set as a non-zero value,
 * it will call itself on its adjacent positions.
 *
 * Return: nothing.
 */
void topple(int grid[3][3], int x, int y, int center)
{

	if (grid[y][x] > 3)
	{
		grid[y][x] -= 4;
		if (x - 1 >= 0)
			grid[y][x - 1]++;
		if (x + 1 < 3)
			grid[y][x + 1]++;
		if (y - 1 >= 0)
			grid[y - 1][x]++;
		if (y + 1 < 3)
			grid[y + 1][x]++;
	}

	if (center)
	{
		top(grid, x - 1, y, 0);
		top(grid, x + 1, y, 0);
		top(grid, x, y - 1, 0);
		top(grid, x, y + 1, 0);

		top(grid, x - 1, y - 1, 0);
		top(grid, x - 1, y + 1, 0);
		top(grid, x + 1, y - 1, 0);
		top(grid, x + 1, y + 1, 0);

		printf("=\n");
		print_grid(grid);

		if (is_unstable(grid))
			top(grid, 1, 1, 1);
	}
}
