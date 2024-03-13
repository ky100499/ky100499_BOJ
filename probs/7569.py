import sys
input = sys.stdin.readline

from collections import deque

M, N, H = map(int, input().split())

box = []
for _ in range(H):
    _box = []
    for _ in range(N):
        _box.append(list(map(int, input().split())))
    box.append(_box)

q = deque()
empty = 0
for i in range(H):
    for j in range(N):
        for k in range(M):
            if box[i][j][k] == 1:
                q.append((i, j, k, 0))
            if box[i][j][k] == -1:
                empty += 1

visited = {}
ans = 0
grown = 0
while q:
    i, j, k, t = q.popleft()
    if (i, j, k) in visited: continue
    visited[(i, j, k)] = 1
    box[i][j][k] = 1
    grown += 1
    ans = t
    if i > 0 and box[i-1][j][k] == 0:
        q.append((i-1, j, k, t+1))
    if j > 0 and box[i][j-1][k] == 0:
        q.append((i, j-1, k, t+1))
    if k > 0 and box[i][j][k-1] == 0:
        q.append((i, j, k-1, t+1))
    if i+1 < H and box[i+1][j][k] == 0:
        q.append((i+1, j, k, t+1))
    if j+1 < N and box[i][j+1][k] == 0:
        q.append((i, j+1, k, t+1))
    if k+1 < M and box[i][j][k+1] == 0:
        q.append((i, j, k+1, t+1))

if grown + empty == N * M * H:
    print(ans)
else:
    print(-1)
