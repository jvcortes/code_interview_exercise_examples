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

    if boxes:
        unlocked.append(boxes[0])
    else:
        return False

    def unlock(boxes, box, unlocked):
        for key in box:
            if key >= len(boxes):
                continue

            if boxes[key] or not boxes[key]:
                if boxes[key] not in unlocked:
                    unlocked.append(boxes[key])
                else:
                    continue

    while i < len(unlocked):
        unlock(boxes, unlocked[i], unlocked)
        i += 1

    if len(unlocked) == len(boxes):
        return True
    else:
        return False
