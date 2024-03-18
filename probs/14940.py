import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

n, m = map(int, input().split())
b = [list(map(int, input().split())) for _ in range(n)]

q = deque()
for i, j in [(i, j) for i in range(n) for j in range(m)]:
    if b[i][j] == 2:
        q.append((i, j, 0))

ans = [[-b[i][j] for j in range(m)] for i in range(n)]
d = [[-1, 0], [0, -1], [1, 0], [0, 1]]
visited = {}
while q:
    i, j, k = q.popleft()
    if (i, j) in visited:
        continue
    visited[i, j] = 1
    ans[i][j] = k

    for di, dj in d:
        ni, nj = i + di, j + dj
        if 0 <= ni < n and 0 <= nj < m and b[ni][nj] == 1:
            q.append((ni, nj, k+1))
print('\n'.join(map(lambda x: ' '.join(map(str, x)), ans)))
