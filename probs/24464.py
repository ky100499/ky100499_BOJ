MOD = int(1e9)+7

N = int(input())
dp = [[1]*5, [0]*5]
for i in range(1, N):
    dp[i%2][0] = sum(dp[(i-1)%2][1:]) % MOD
    for j in range(1, 5):
        dp[i%2][j] = sum(
            dp[(i-1)%2][:max(j-1, 1)] +
            dp[(i-1)%2][min(j+2, 5):]
        ) % MOD
print(sum(dp[(N-1)%2]) % MOD)
