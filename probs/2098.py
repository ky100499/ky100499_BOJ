import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

INF = int(1e9)

def dfs(s, v):
    if v == (1<<N)-1:
        if G[s][0] == 0:
            dp[s][v] = INF//10
        else:
            dp[s][v] = G[s][0]
        dp[s][v]

    if dp[s][v] == INF:
        for i in range(N):
            if v & (1<<i):
                continue
            if G[s][i] != 0:
                dp[s][v] = min(dp[s][v], G[s][i] + dfs(i, v | (1<<i)))

    return dp[s][v]

N = int(input())
G = [list(map(int, input().split())) for _ in range(N)]

dp = [[INF]*(1<<N) for _ in range(N)]
print(dfs(0, 1))
