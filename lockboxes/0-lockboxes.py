#!/usr/bin/python3

def keys_collected(T, R):
    res = []
    for e in R:
        res += T[e]
    return res


def canUnlockAll(boxes):
    unlocked = {0}
    can_unlock_box = True

    while can_unlock_box:
        can_unlock_box = False

        for j in keys_collected(boxes, list(unlocked)):
            if j < len(boxes) and j not in unlocked:
                unlocked.add(j)
                can_unlock_box = True

    locked_boxes_count = len(boxes) - len(unlocked)

    if locked_boxes_count == 0:
        return True 
    else:
        return False