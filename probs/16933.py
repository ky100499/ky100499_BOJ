import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

INF = 10**8

N, M, K = map(int, input().split())
B = [list(map(int, input().strip())) for _ in range(N)]

dist = [[[INF]*(K+1) for _ in range(M)] for _ in range(N)]
dist[0][0][0] = 1

q1, q2 = deque([(1, 0, 0, 0)]), deque()
while q1 or q2:
    if not q1:
        d, i, j, k = q2.popleft()
    elif not q2:
        d, i, j, k = q1.popleft()
    elif q1[0] > q2[0]:
        d, i, j, k = q2.popleft()
    else:
        d, i, j, k = q1.popleft()

    if dist[i][j][k] < d:
        continue

    if (i, j) == (N-1, M-1):
        print(d)
        break

    for di, dj in [(-1,0), (0,-1), (1,0), (0,1)]:
        ni, nj = i+di, j+dj
        if 0 <= ni < N and 0 <= nj < M:
            if B[ni][nj] == 0 and dist[ni][nj][k] > (nd := dist[i][j][k]+1):
                dist[ni][nj][k] = nd
                q1.append((nd, ni, nj, k))
            elif k < K and B[ni][nj] == 1 and d % 2 and dist[ni][nj][k+1] > (nd := dist[i][j][k]+1):
                dist[ni][nj][k+1] = nd
                q1.append((nd, ni, nj, k+1))
            elif k < K and B[ni][nj] == 1 and d % 2 == 0 and dist[ni][nj][k+1] > (nd := dist[i][j][k]+2):
                dist[ni][nj][k+1] = nd
                q2.append((nd, ni, nj, k+1))
else:
    print(-1)
