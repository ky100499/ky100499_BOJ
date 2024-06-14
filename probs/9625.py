K = int(input())
dp = [[0]*2 for _ in range(K+1)]
dp[0][0] = 1

for i in range(1, K+1):
    dp[i] = [dp[i-1][1], sum(dp[i-1])]

print(*dp[-1])
