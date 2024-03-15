X = int(input())

dp = [1000000 for _ in range(X)] + [0]

if X == 1:
    print(0)
else:
    while X > 1:
        if X % 3 == 0:
            dp[X // 3] = min(dp[X // 3], dp[X] + 1)
        if X % 2 == 0:
            dp[X // 2] = min(dp[X // 2], dp[X] + 1)
        if X > 1:
            dp[X - 1] = min(dp[X - 1], dp[X] + 1)
        X -= 1
    print(dp[1])
