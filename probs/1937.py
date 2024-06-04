import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

def dfs(x, y):
    if dp[x][y] != -1:
        return dp[x][y]
    dp[x][y] = 1
    for dx, dy in [[-1,0],[0,-1],[1,0],[0,1]]:
        nx, ny = x+dx, y+dy
        if 0 <= nx < N and 0 <= ny < N and B[nx][ny] > B[x][y]:
            dp[x][y] = max(dp[x][y], dfs(nx, ny)+1)
    return dp[x][y]

N = int(input())
B = [list(map(int, input().split())) for _ in range(N)]

dp = [[-1]*N for _ in range(N)]

for x in range(N):
    for y in range(N):
        if dp[x][y] == -1:
            dfs(x, y)
print(max(map(max, dp)))
