import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

INF = 10**8

N, M, K = map(int, input().split())
B = [list(map(int, input().strip())) for _ in range(N)]

V = [[[0]*(K+1) for _ in range(M)] for _ in range(N)]
V[0][0][0] = 1

q = deque([(1,0,0,0)])
while q:
    d, i, j, k = q.popleft()

    if (i, j) == (N-1, M-1):
        print(d)
        break

    stay = 0
    for di, dj in [(-1,0), (0,-1), (1,0), (0,1)]:
        ni, nj = i+di, j+dj
        if 0 <= ni < N and 0 <= nj < M:
            if B[ni][nj] == 0 and not V[ni][nj][k]:
                V[ni][nj][k] = 1
                q.append((d+1, ni, nj, k))
            if B[ni][nj] == 1 and k < K and not V[ni][nj][k+1]:
                if d%2:
                    V[ni][nj][k+1] = 1
                    q.append((d+1, ni, nj, k+1))
                elif not stay:
                    stay = 1
                    q.append((d+1, i, j, k))
else:
    print(-1)
