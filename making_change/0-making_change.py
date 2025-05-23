#!/usr/bin/python3
"""coin flip"""


def makeChange(coins, total):
    """function that flips"""

    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0
    for coin in coins:
        for amount in range(coin, total + 1):
            if dp[amount - coin] != float('inf'):
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
