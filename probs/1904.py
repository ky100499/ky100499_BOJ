N = int(input())

if N < 3:
    print(N)
else:
    dp = [0]*N
    dp[0] = 1
    dp[1] = 2

    for i in range(2, N):
        dp[i] = (dp[i-1]+dp[i-2]) % 15746

    print(dp[-1])
