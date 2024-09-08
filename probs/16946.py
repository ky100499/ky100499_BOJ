import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque, defaultdict as dd

N, M = map(int, input().split())
B = [list(map(int, input().rstrip())) for _ in range(N)]
V = [[0]*M for _ in range(N)]
A = dd(int)

v = 1
for i in range(N):
    for j in range(M):
        if not B[i][j] and not V[i][j]:
            q = deque([(i, j)])
            while q:
                x, y = q.popleft()

                if V[x][y]:
                    continue
                V[x][y] = v
                A[v] += 1

                for dx, dy in ((-1,0),(0,-1),(1,0),(0,1)):
                    nx, ny = x+dx, y+dy
                    if 0 <= nx < N and 0 <= ny < M and not B[nx][ny] and not V[nx][ny]:
                        q.append((nx, ny))
            v += 1

for i in range(N):
    for j in range(M):
        if B[i][j]:
            area = set()
            V[i][j] = 1
            for dx, dy in ((-1,0),(0,-1),(1,0),(0,1)):
                nx, ny = i+dx, j+dy
                if 0 <= nx < N and 0 <= ny < M and not B[nx][ny]:
                    area.add(V[nx][ny])
            for a in area:
                V[i][j] += A[a]

for i in range(N):
    print(*[B[i][j]*V[i][j]%10 for j in range(M)], sep='')
