N = int(input())

dp = [0 for _ in range(N+1)]
dp[1] = 1

for i in range(2, N+1):
    if i % 2:
        dp[i] = dp[i-1]
    else:
        dp[i] = (dp[i-1] + dp[i//2]) % 1_000_000_000

print(dp[N])
