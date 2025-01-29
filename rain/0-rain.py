#!/usr/bin/python
""" ret Integer indicating total amount of rainwater retained. """


def rain(walls):
    """calcullate square units of water will be retained"""
    left, right = 0, len(walls) - 1
    left_max, right_max = 0, 0
    water_units = 0

    while left < right:
        if walls[left] < walls[right]:
            if walls[left] > left_max:
                left_max = walls[left]
            else:
                water_units += left_max - walls[left]
            left += 1
        else:
            if walls[right] > right_max:
                right_max = walls[right]
            else:
                water_units += right_max - walls[right]
            right -= 1

    return water_units
