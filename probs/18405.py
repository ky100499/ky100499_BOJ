import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, K = map(int, input().split())
M = [[0]*N for _ in range(N)]
virus = []
for i in range(N):
    for j, v in enumerate(map(int, input().split())):
        M[i][j] = v
        if v != 0:
            virus.append((v, i, j, 0))
virus.sort()
S, X, Y = map(int, input().split())

q = deque(virus)
while q:
    v, i, j, s = q.popleft()
    if s == S:
        break
    for di, dj in [(-1,0),(0,-1),(1,0),(0,1)]:
        ni, nj = i+di, j+dj
        if 0 <= ni < N and 0 <= nj < N and M[ni][nj] == 0:
            M[ni][nj] = v
            q.append((v, ni, nj, s+1))
print(M[X-1][Y-1])
