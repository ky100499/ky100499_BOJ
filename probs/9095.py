for _ in range(int(input())):
    n = int(input())
    dp = [0] * 11
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4
    for i in range(4, n+1):
        for j in range(max(1, i-3), i):
            dp[i] += dp[j]
    print(dp[n])
