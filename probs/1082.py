import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
P = list(map(int, input().split()))
M = int(input())

ans = -1
dp = [[-1]*(M+1) for _ in range(M)]
for i, p in enumerate(P):
    if p <= M:
        dp[0][p] = max(dp[0][p], i)
        ans = max(ans, dp[0][p])

for i in range(1, M):
    for n, p in enumerate(P):
        for j in range(p, M+1):
            if dp[i-1][j-p] != -1:
                dp[i][j] = max(dp[i][j], 10*dp[i-1][j-p]+n)
                ans = max(ans, dp[i][j])
print(ans)
