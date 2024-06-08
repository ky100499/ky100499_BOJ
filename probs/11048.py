import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
C = [list(map(int, input().split())) for _ in range(N)]

dp = [[0]*M for _ in range(N)]
dp[0][0] = C[0][0]
for i in range(1, N):
    dp[i][0] = dp[i-1][0]+C[i][0]
for i in range(1, M):
    dp[0][i] = dp[0][i-1]+C[0][i]
for i in range(1, N):
    for j in range(1, M):
        dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+C[i][j]
print(dp[-1][-1])
