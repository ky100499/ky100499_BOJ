import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque, defaultdict as dd

N, M = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(M)]
R = [[-1]*N for _ in range(M)]
A = dd(int)
adj = set()

r = 0
for i in range(M):
    for j in range(N):
        if R[i][j] != -1:
            continue

        q = deque([(i, j)])
        while q:
            x, y = q.popleft()

            if R[x][y] != -1:
                continue
            R[x][y] = r
            A[r] += 1

            for d, (dx, dy) in enumerate(((0,-1),(-1,0),(0,1),(1,0))):
                nx, ny = x+dx, y+dy
                if 0 <= nx < M and 0 <= ny < N and R[nx][ny] == -1 and not B[x][y] & (1<<d):
                    q.append((nx, ny))
                elif 0 <= nx < M and 0 <= ny < N and R[nx][ny] != -1 and R[x][y] != R[nx][ny]:
                    adj.add((R[x][y], R[nx][ny]))
        r += 1

print(r)
print(max(A.values()))
print(max(map(lambda a: A[a[0]]+A[a[1]], adj)))
