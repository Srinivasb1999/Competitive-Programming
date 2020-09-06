# Top Down Approach to the Staircase Problem

def nthStair(n, m, memo):
    if n == 0:
        return 1
    if n in memo:
        return memo[n]

    ways = 0
    for i in range(1, m + 1):
        if i <= n:
            ways += nthStair(n - i, m, memo)
    memo[n] = ways
    return ways


def staircase(n, m):
    # Your code goes here
    memo = {}
    return nthStair(n, m, memo)


print(staircase(4, 2))
