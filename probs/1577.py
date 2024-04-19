import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, M = map(int, input().split())
K = int(input())
fix = []
for _ in range(K):
    x1, y1, x2, y2 = map(int, input().split())
    if x1 == x2:
        fix.append((x1, min(y1, y2), x2, max(y1, y2)))
    else:
        fix.append((min(x1, x2), y1, max(x1, x2), y2))

ans = [[0]*(N+1) for _ in range(M+1)]
ans[0][0] = 1
q = deque([(0, 0)])
visited = {}
while q:
    x, y = q.popleft()
    if (x, y) in visited:
        continue
    visited[x, y] = 1

    for dx, dy in [[1, 0], [0, 1]]:
        nx, ny = x+dx, y+dy
        if nx <= M and ny <= N and (y, x, ny, nx) not in fix:
            ans[nx][ny] += ans[x][y]
            q.append((nx, ny))

print(ans[-1][-1])
