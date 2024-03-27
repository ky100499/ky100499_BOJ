import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

INF = 10**8

N, M = map(int, input().split())
board = []
for _ in range(N):
    board.append(list(map(int, input().strip())))

dist = [[0]*M for _ in range(N)]
dist_rev = [[0]*M for _ in range(N)]

q = deque([(0, 0, 1)])
while q:
    x, y, d = q.popleft()
    if dist[x][y] > 0:
        continue
    dist[x][y] = d
    for dx, dy in [[-1,0], [0,-1], [1,0], [0,1]]:
        nx, ny = x+dx, y+dy
        if 0 <= nx < N and 0 <= ny < M and board[nx][ny] == 0 and dist[nx][ny] == 0:
            q.append((nx, ny, d+1))
q = deque([(N-1, M-1, 1)])
while q:
    x, y, d = q.popleft()
    if dist_rev[x][y] > 0:
        continue
    dist_rev[x][y] = d
    for dx, dy in [[-1,0], [0,-1], [1,0], [0,1]]:
        nx, ny = x+dx, y+dy
        if 0 <= nx < N and 0 <= ny < M and board[nx][ny] == 0 and dist_rev[nx][ny] == 0:
            q.append((nx, ny, d+1))

ans = INF if dist_rev[0][0] == 0 else dist_rev[0][0]

for i, j in [(i, j) for i in range(N) for j in range(M)]:
    if board[i][j]:
        min_dists = []
        min_dists_rev = []
        for dx, dy in [[-1,0], [0,-1], [1,0], [0,1]]:
            nx, ny = i+dx, j+dy
            if 0 <= nx < N and 0 <= ny < M:
                if dist[nx][ny] > 0:
                    min_dists.append((dist[nx][ny], nx, ny))
                if dist_rev[nx][ny] > 0:
                    min_dists_rev.append((dist_rev[nx][ny], nx, ny))
        if min_dists and min_dists_rev:
            min_dists.sort()
            min_dists_rev.sort()
            if (min_dists[0][1], min_dists[0][2]) != (min_dists_rev[0][1], min_dists_rev[0][2]):
                ans = min(ans, min_dists[0][0]+min_dists_rev[0][0]+1)
print(-1 if ans == INF else ans)
