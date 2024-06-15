import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

INF = int(1e9)

def dfs(n, v):
    if v == (1<<N)-1:
        dp[n][v] = dist[n][0]
    elif dp[n][v] == INF:
        for i in range(N):
            if v & (1<<i) == 0:
                dp[n][v] = min(dp[n][v], dist[n][i] + dfs(i, v|(1<<i)))
    return dp[n][v]

N = int(input())
C = [tuple(map(int, input().split())) for _ in range(N)]

dist = [[0]*N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if i != j:
            dist[i][j] = dist[j][i] = ((C[i][0]-C[j][0])**2 + (C[i][1]-C[j][1])**2) ** 0.5

dp = [[INF]*(1<<N) for _ in range(N)]
print(dfs(0, 1))
