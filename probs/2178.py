import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, M = map(int, input().split())
B = [list(map(int, input().rstrip())) for _ in range(N)]

q = deque([(0, 0)])
V = [[0]*M for _ in range(N)]
V[0][0] = 1
while q:
    x, y = q.popleft()

    if x == N-1 and y == M-1:
        print(B[x][y])
        break

    for dx, dy in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
        nx, ny = x+dx, y+dy
        if 0 <= nx < N and 0 <= ny < M and B[nx][ny] and not V[nx][ny]:
            V[nx][ny] = 1
            B[nx][ny] = B[x][y]+1
            q.append((nx, ny))
