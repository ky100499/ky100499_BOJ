import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
G = [list(map(int, input().split())) for _ in range(N)]

dp = [[0]*M for _ in range(N)]
dp[0][0] = G[0][0]
for i in range(1, M):
    dp[0][i] = dp[0][i-1] + G[0][i]
l, r = [0]*M, [0]*M
for i in range(1, N):
    l[0] = dp[i-1][0]+G[i][0]
    r[-1] = dp[i-1][-1]+G[i][-1]
    for j in range(1, M):
        l[j] = max(l[j-1], dp[i-1][j]) + G[i][j]
        r[-j-1] = max(r[-j], dp[i-1][-j-1]) + G[i][-j-1]
    for j in range(M):
        dp[i][j] = max(l[j], r[j])

print(dp[-1][-1])
