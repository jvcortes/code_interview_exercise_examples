#!/usr/bin/python3


def canUnlockAll(boxes):
    """
    Determines if all the boxes (list of numbers) inside a list
    can be unlocked.

    Each box can contain an integer indicating the index of another box.

    The first box is unlocked

    Parameters:
        boxes (list): list of lists.
    """

    i = 0
    unlocked = []
    keys = []

    if boxes:
        boxes = list(enumerate(boxes))
        unlocked.append(boxes[i])
    else:
        return False

    while len(boxes) != len(unlocked):
        box = unlocked[i]
        if set(box[1]).issubset(set(keys)):
            if i == len(unlocked) - 1:
                break
            else:
                i += 1
                continue
        for key in box[1]:
            if key >= len(boxes):
                continue
            if box == boxes[key]:
                continue
            if key in keys:
                continue
            if boxes[key]:
                unlocked.append(boxes[key])
                keys.append(key)

        if i == len(unlocked) - 1:
            break
        i += 1

    if len(boxes) == len(unlocked):
        return True
    return False
