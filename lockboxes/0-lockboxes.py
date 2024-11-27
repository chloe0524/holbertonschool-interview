#!/usr/bin/python3
''' lockboxes python script '''


def keys_collected(boxes, unlocked_boxes):
    keys = []
    for box in unlocked_boxes:
        keys += boxes[box]
    return keys


def canUnlockAll(boxes):
    unlocked = {0}
    can_unlock_box = True

    while can_unlock_box:
        can_unlock_box = False

        for key in keys_collected(boxes, list(unlocked)):
            if key < len(boxes) and key not in unlocked:
                unlocked.add(key)
                can_unlock_box = True

    locked_boxes_count = len(boxes) - len(unlocked)

    if locked_boxes_count == 0:
        return True
    else:
        return False
