import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def dfs(i, j):
    dp[i][j] = 1
    c = 0
    for di, dj in [[-1,0],[0,-1],[1,0],[0,1]]:
        ni, nj = i+di, j+dj
        if 0 <= ni < N and 0 <= nj < M and B[ni][nj] == 0 and dp[ni][nj] == 0:
            c += dfs(ni, nj)
    dp[i][j] = 0

    return c+1

def prop(i, j, c, v):
    dp[i][j] = c
    V[i][j] = v
    for di, dj in [[-1,0],[0,-1],[1,0],[0,1]]:
        ni, nj = i+di, j+dj
        if 0 <= ni < N and 0 <= nj < M and B[ni][nj] == 0 and dp[ni][nj] == 0:
            prop(ni, nj, c, v)

N, M = map(int, input().split())
B = [list(map(int, input().rstrip())) for _ in range(N)]
dp = [[0]*M for _ in range(N)]
V = [[0]*M for _ in range(N)]
v = 1

for i in range(N):
    for j in range(M):
        if B[i][j] == 0 and dp[i][j] == 0:
            prop(i, j, dfs(i, j), v)
            v += 1

for i in range(N):
    for j in range(M):
        if B[i][j] == 1:
            dp[i][j] = 1
            visited = set()
            for di, dj in [[-1,0],[0,-1],[1,0],[0,1]]:
                ni, nj = i+di, j+dj
                if 0 <= ni < N and 0 <= nj < M and B[ni][nj] == 0 and V[ni][nj] not in visited:
                    dp[i][j] += dp[ni][nj]
                    visited.add(V[ni][nj])

for i in range(N):
    for j in range(M):
        print(dp[i][j] * B[i][j], end='')
    print()
