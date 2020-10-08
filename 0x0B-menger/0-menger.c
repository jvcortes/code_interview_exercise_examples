#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"

/**
 * menger - creates one 2d face of a 3d menger sponge.
 * @level: level of fractal recusrion
 * Return: void
 */
void menger(int level)
{
	int max_len, i;
	char **sponge;
	char symbol;

	symbol = '#';
	if (level == 0)
		printf("%c\n", symbol);
	else if (level > 0)
	{
		/* malloc: multiply  3^level by the size of a char ptr (8 bytes) */
		/*  e.g. @ level 2: (3^2) * 8 = 72 */
		max_len = pow(3, level);
		sponge = malloc(sizeof(char *) * max_len);
		if (sponge == NULL)
			return;

		for (i = 0; i < max_len; i++)
			sponge[i] = malloc(sizeof(*sponge[i]) * max_len);

		build_level_one_sponge(sponge, symbol);
		recurse(sponge, 0, level, 3, 3);
		print_sponge(sponge, max_len);
		free_sponge(sponge, max_len);
	}
}

/**
 * build_level_one_sponge - constructs 3x3 lvl 1 sponge
 * @sponge: empty, malloc'd 2d array
 * @symbol: character used to represent 'non-hole' bytes
 * Return: void
 */
void build_level_one_sponge(char **sponge, char symbol)
{
	int i;

	for (i = 0; i < 3; i++)
		sponge[0][i] = symbol;
	sponge[1][0] = symbol;
	sponge[1][1] = ' ';
	sponge[1][2] = symbol;
	for (i = 0; i < 3; i++)
		sponge[2][i] = symbol;
}

/**
 * recurse - increases sponge to level size
 * @sponge: ptr to char array representing current sponge
 * @idx: current level of sponge
 * @level: size of 2d menger sponge face
 * @len: current len of sponge
 * @nxt: the index in each row and column at which the sponge will expand
 * Return: ptr to current char array representing 2d menger sponge face
 */
void recurse(char **sponge, int idx, int level, int len, int nxt)
{
	int i, j, k, div, mid_start, mid_end, limit;

	if (idx < (level - 1))
	{
		/* duplicate cols twice (so col count triples)  */
		for (i = 0; i < len; i++)
			for (j = 0, k = nxt; j < nxt * 2; j++, k++)
				sponge[i][k] = sponge[i][j];
		limit = len;

		/* duplicate rows twice (so row count triples) */
		for (i = 0; i < limit * 2; i++, len++)
			for (j = 0; j < 3 * limit; j++)
				sponge[len][j] = sponge[i][j];

		/* remove center */
		div = len / 3;
		mid_start = div;
		mid_end = (div * 2) - 1;
		for (i = 0; i < len; i++)
			if (i >= mid_start && i <= mid_end)
				for (j = 0; j < len; j++)
					if (j >= mid_start && j <= mid_end)
						sponge[i][j] = ' ';
		nxt = k;
		recurse(sponge, idx + 1, level, len, nxt);
	}
}
/**
 * print_sponge - prints a 2d menger sponge face  to the standard output
 * @sponge: pointer to char array representing 2d menger sponge face to print
 * @len: len of 2d menger sponge face being printed
 * Return: void
 */
void print_sponge(char **sponge, int len)
{
	int i, j;

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
			printf("%c", sponge[i][j]);
		printf("\n");
	}
}

/**
 * free_sponge - frees a 2d char array representing one face of a menger sponge
 * @sponge: pointer to char array representing 2d menger sponge face to print
 * @max_len: the length of a completed 2d char array
 * Return: void
 */
void free_sponge(char **sponge, int max_len)
{
	int i;

	for (i = 0; i < max_len; i++)
		free(sponge[i]);
	free(sponge);
}
