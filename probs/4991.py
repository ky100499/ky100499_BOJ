import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

INF = int(1e9)

while True:
    W, H = map(int, input().split())
    if W == H == 0:
        break

    B = []
    dusts = []
    for i in range(H):
        B.append(input().rstrip())
        for j, c in enumerate(B[i]):
            if c == '*':
                dusts.append((i, j))
            if c == 'o':
                s = (i, j)
    B[s[0]] = B[s[0]][:s[1]] + '.' + B[s[0]][s[1]+1:]

    dist = [[[INF]*(1<<len(dusts)) for _ in range(W)] for _ in range(H)]
    dist[s[0]][s[1]][0] = 0
    q = deque([(0, *s, 0)])
    while q:
        cd, x, y, v = q.popleft()

        if v == (1<<len(dusts)) - 1:
            print(cd)
            break

        for dx, dy in [[-1,0], [0,1], [1,0], [0,-1]]:
            nx, ny = x+dx, y+dy
            if 0 <= nx < H and 0 <= ny < W:
                if B[nx][ny] == '.' and dist[nx][ny][v] > cd+1:
                    dist[nx][ny][v] = cd+1
                    q.append((cd+1, nx, ny, v))
                elif B[nx][ny] == '*' and dist[nx][ny][(nv := v|(1<<dusts.index((nx, ny))))] > cd+1:
                    dist[nx][ny][nv] = cd+1
                    q.append((cd+1, nx, ny, nv))
    else:
        print(-1)
