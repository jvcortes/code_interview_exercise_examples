#include <stdio.h>
#include "palindrome.h"

int length(unsigned long n);
int digit_at(unsigned long n, int pos);
int assert(int n, int s, int e, int len);
/**
 * is_palindrome - determines if a provided string is a palindrome
 * @s: provided string
 * Return: 1 if a string is a palindrome, otherwise, 0.
 */
int is_palindrome(unsigned long n)
{
	int len = length(n);
	int start = digit_at(n, 1), end = digit_at(n, len), c = 1, cr = len;

	while (c <= len) {
		if (start != end)
		{
			return (0);
		}
		else
		{
			start = digit_at(n, ++c);
			end = digit_at(n, --cr);
		}
	}

	return (1);
}

/**
 * power - returns the exponential value of a number
 * @base: base number
 * @exponent: exponent number
 * Return: result
 */
unsigned long power(unsigned long base, unsigned int exponent)
{
	int count;
	long result;

	if (exponent == 0)
		return (1);
	result = 1;
	for (count = 0; count < (int)exponent; count++)
		result *= base;
	return (result);
}

/**
 * digit_at - gets a digit at a specific position from an unsigned int
 * @n: number
 * @pos: position
 *
 * Return: digit at given position.
 */
int digit_at(unsigned long n, int pos)
{
	while (n >= power(10, pos))
		n /= 10;

	return n % 10;
}

/**
 * length - recursively determines the length of a string
 * @s: provided string
 * Return: length of the string.
 */
int length(unsigned long n)
{	
	int i = 1;

	for (i = 1; n > 9; i++)
		n = n / 10;

	return (i);
}
