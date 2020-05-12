#!/usr/bin/python3
"""
Module for task 0.
"""


def minOperations(n):
    """
    Returns the number of minimum operations to go from a single character
    'H' to n 'H' characters.

    The valid operations are composed of:
        - Copy all the text.
        - Paste

    Parameters:
        n (int): number of 'H' characters to determine the amount of minimum
        operations.
    """

    d = 2
    paste = 0
    copy_all = 0

    if n in (0, 1):
        return 0

    m = n

    while (True):
        if m % d == 0:
            m = m / d
            d = 2
            paste += 1
            copy_all += 1
        else:
            copy_all += 1
            d += 1

        if m == 1:
            break

    return paste + copy_all
