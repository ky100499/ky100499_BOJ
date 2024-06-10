import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = 100000

N, M = map(int, input().split())
B = map(int, input().split())
C = map(int, input().split())

dp = [[INF]*(M+1) for _ in range(2)]
for i, m, c in zip(range(1, N+1), B, C):
    for j in range(1, M+1):
        if j <= m:
            dp[i%2][j] = min(dp[(i-1)%2][j], c)
        else:
            if dp[(i-1)%2][j-m] == INF:
                break
            dp[i%2][j] = min(dp[(i-1)%2][j], dp[(i-1)%2][j-m]+c)
print(dp[N%2][-1])
