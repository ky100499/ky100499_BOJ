import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def dfs(x, y):
    if dp[x][y] != -1:
        return dp[x][y]
    dp[x][y] = 0

    for dx, dy in [[-1,0], [0,-1], [1,0], [0,1]]:
        nx, ny = x+dx, y+dy
        if 0 <= nx < M and 0 <= ny < N and H[x][y] > H[nx][ny]:
            dp[x][y] += dfs(nx, ny)

    return dp[x][y]

M, N = map(int, input().split())
H = [list(map(int, input().split())) for _ in range(M)]

dp = [[-1]*N for _ in range(M)]
dp[-1][-1] = 1

print(dfs(0, 0))
