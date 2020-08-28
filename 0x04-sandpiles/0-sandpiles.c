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

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	do {
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	} while (is_unstable(grid1));
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
void topple(int grid1[3][3])
{
	int i, j;
	int residue[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] >= 4)
			{
				grid1[i][j] -= 4;
				if (j - 1 >= 0)
					residue[i][j - 1]++;
				if (j + 1 < 3)
					residue[i][j + 1]++;
				if (i - 1 >= 0)
					residue[i - 1][j]++;
				if (i + 1 < 3)
					residue[i + 1][j]++;
			}
		}
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += residue[i][j];
}
