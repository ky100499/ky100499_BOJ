import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

R, C = map(int, input().split())
b = []
w = [[-1]*C for _ in range(R)]
wq = deque()
d = [[0]*C for _ in range(R)]
dq = deque()
for i in range(R):
    row = list(input().strip())
    b.append(row)
    for j, c in enumerate(row):
        if c == '*':
            w[i][j] = 0
            wq.append((i, j))
        elif c == 'D':
            goal = (i, j)
        elif c == 'S':
            dq.append((i, j))

while wq:
    i, j = wq.popleft()
    for di, dj in [[-1, 0], [0, -1], [1, 0], [0, 1]]:
        ni, nj = i+di, j+dj
        if 0<=ni<R and 0<=nj<C and b[ni][nj] != 'X' and b[ni][nj] != 'D' and w[ni][nj] == -1:
            w[ni][nj] = w[i][j]+1
            wq.append((ni, nj))

while dq:
    i, j = dq.popleft()
    if (i, j) == goal:
        print(d[i][j])
        break
    for di, dj in [[-1, 0], [0, -1], [1, 0], [0, 1]]:
        ni, nj = i+di, j+dj
        if 0<=ni<R and 0<=nj<C and b[ni][nj] != 'X' and d[ni][nj] == 0 and (w[ni][nj] == -1 or w[ni][nj] > d[i][j]+1):
            d[ni][nj] = d[i][j]+1
            dq.append((ni, nj))
else:
    print('KAKTUS')
