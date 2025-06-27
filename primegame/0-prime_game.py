def isWinner(x, nums):
    """Determines the winner of each round of the Prime Game"""
    if x < 1 or not nums or len(nums) == 0:
        return None

    def sieve(n):
        """Returns the number of primes <= n"""
        is_prime = [True] * (n + 1)
        is_prime[0:2] = [False, False]
        count = 0
        for i in range(2, n + 1):
            if is_prime[i]:
                count += 1
                for j in range(i * 2, n + 1, i):
                    is_prime[j] = False
        return count

    maria_wins = 0
    ben_wins = 0

    # Precompute number of primes up to max_n
    max_n = max(nums)
    prime_counts = [0] * (max_n + 1)
    count = 0
    is_prime = [True] * (max_n + 1)
    is_prime[0:2] = [False, False]
    for i in range(2, max_n + 1):
        if is_prime[i]:
            count += 1
            for j in range(i * 2, max_n + 1, i):
                is_prime[j] = False
        prime_counts[i] = count

    for n in nums:
        if prime_counts[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
