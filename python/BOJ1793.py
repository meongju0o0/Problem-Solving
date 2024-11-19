def dp(n, memo):
    if n in memo:
        return memo[n]
    else:
        memo[n] = dp(n - 1, memo) + 2 * dp(n - 2, memo)
        return memo[n]


if __name__ == "__main__":
    memo = {0: 1, 1: 1}
    while True:
        try:
            n = int(input())
            print(dp(n, memo))
        except EOFError:
            break