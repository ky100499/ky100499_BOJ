import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, M = map(int, input().split())
b = [list(map(lambda x:x, input().strip())) for _ in range(N)]

q = deque()
for i, j in [(i, j) for i in range(N) for j in range(M)]:
    if b[i][j] == 'I':
        q.append((i, j))

visited = {}
cnt = 0
while q:
    i, j = q.popleft()
    if (i, j) in visited:
        continue
    visited[i, j] = 1

    if b[i][j] == 'P':
        cnt += 1

    d = [[-1, 0], [0, -1], [1, 0], [0, 1]]
    for di, dj in d:
        ni, nj = i + di, j + dj
        if 0 <= ni < N and 0 <= nj < M and b[ni][nj] in 'OP':
            q.append((ni, nj))
print(cnt if cnt else 'TT')
