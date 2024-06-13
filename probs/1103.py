import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

def dfs(i, j, d):
    global ans

    if dp[i][j] != 0:
        if visited[i][j]:
            print(-1)
            exit(0)
        elif dp[i][j] >= d:
            return
    dp[i][j] = d
    visited[i][j] = 1
    ans = max(ans, d)

    for di, dj in [(-B[i][j],0), (0,-B[i][j]), (B[i][j],0), (0,B[i][j])]:
        ni, nj = i+di, j+dj
        if 0 <= ni < N and 0 <= nj < M and B[ni][nj] != 0:
            dfs(ni, nj, d+1)

    visited[i][j] = 0

N, M = map(int, input().split())
B = [list(map(lambda x: int(x) if x.isdecimal() else 0, input().strip())) for _ in range(N)]

dp = [[0]*M for _ in range(N)]
visited = [[0]*M for _ in range(N)]
ans = 0
dfs(0, 0, 1)
print(ans)
