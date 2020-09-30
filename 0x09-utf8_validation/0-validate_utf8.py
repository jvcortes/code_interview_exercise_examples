#!/usr/bin/python3
"""
Module for task 0
"""


def validUTF8(data):
    """
    Validates an array of integers for UTF-8 encoding.

    Parameters:
        data: array of integers.
    """

    count = 0

    for number in data:
        rep = format(number, '#010b')[-8:]

        if count == 0:
            for bit in rep:
                if bit == '0':
                    break
                count += 1

            if count == 0:
                continue

            if count == 1 or count > 4:
                return False
        else:
            if not (rep[0] == '1' and rep[1] == '0'):
                return False

        count -= 1

    return count == 0
