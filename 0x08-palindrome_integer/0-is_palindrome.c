#include <stdio.h>
#include "palindrome.h"

int length(char *s);
int assert(char *s, char *e, int len);
/**
 * is_palindrome - determines if a provided string is a palindrome
 * @s: provided string
 * Return: 1 if a string is a palindrome, otherwise, 0.
 */
int is_palindrome(unsigned long n)
{
	char buf[256];
	sprintf(buf, "%ld", n);

	return (assert(buf, buf + (length(buf) - 1), length(buf)));
}

/**
 * assert - recursively asserts if a string is a palindrome
 * @s: provided pointer to the start of the string
 * @e: provided pointer to the end of the string
 * @len: length of the string
 * Return: 1 if a string is a palindrome, otherwise, 0.
 */
int assert(char *s, char *e, int len)
{
	if (length(s) == len / 2)
		return (1);
	if (*s == *e)
		return (assert(++s, --e, len));
	else
		return (0);
}

/**
 * length - recursively determines the length of a string
 * @s: provided string
 * Return: length of the string.
 */
int length(char *s)
{
	if (!*s)
		return (0);
	return (1 + length(++s));
}
