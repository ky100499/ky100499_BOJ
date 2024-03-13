import sys
input = sys.stdin.readline

from collections import deque

M, N = map(int, input().split())

box = []
for _ in range(N):
    box.append(list(map(int, input().split())))

q = deque()
empty = 0
for i in range(N):
    for j in range(M):
        if box[i][j] == 1:
            q.append((i, j, 0))
        if box[i][j] == -1:
            empty += 1

visited = []
ans = 0
grown = 0
while q:
    i, j, t = q.popleft()
    if (i, j) in visited: continue
    visited.append((i, j))
    box[i][j] = 1
    grown += 1
    ans = t
    if i > 0 and box[i-1][j] == 0:
        q.append((i-1, j, t+1))
    if j > 0 and box[i][j-1] == 0:
        q.append((i, j-1, t+1))
    if i+1 < N and box[i+1][j] == 0:
        q.append((i+1, j, t+1))
    if j+1 < M and box[i][j+1] == 0:
        q.append((i, j+1, t+1))

if grown + empty == N * M:
    print(ans)
else:
    print(-1)
