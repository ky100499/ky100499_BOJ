import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

MOD = int(1e9)+7

N, M = map(int, input().split())
B = [[1]*(M+1) for _ in range(N+1)]
for _ in range(int(input())):
    x, y = map(int, input().split())
    B[x][y] = 0

dp = [[0]*(M+1) for _ in range(N+1)]
dp[1][1] = 1
for j in range(1, M+1):
    for i in range(1, N+1):
        if B[i][j]:
            if i > 1:
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD
            if j > 1:
                if j % 2 == 0:
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD
                    if i < N:
                        dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % MOD
                else:
                    if i > 1:
                        dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD
print(dp[-1][-1])
