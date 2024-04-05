import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

while True:
    L, R, C = map(int, input().split())
    if not L|R|C:
        break

    bld = []
    q = deque()
    for i in range(L):
        fl = []
        for j in range(R):
            row = list(input().strip())
            if 'S' in row:
                q.append((i, j, row.index('S'), 0))
            fl.append(row)
        bld.append(fl)
        input()

    visited = set()
    while q:
        x, y, z, t = q.popleft()
        if bld[x][y][z] == 'E':
            print(f'Escaped in {t} minute(s).')
            break
        if (x, y, z) in visited:
            continue
        visited.add((x, y, z))

        d = [
            [-1, 0, 0], [1, 0, 0],
            [0, -1, 0], [0, 1, 0],
            [0, 0, -1], [0, 0, 1],
        ]

        for dx, dy, dz in d:
            nx, ny, nz = x+dx, y+dy, z+dz
            if 0<=nx<L and 0<=ny<R and 0<=nz<C and bld[nx][ny][nz] != '#':
                q.append((nx, ny, nz, t+1))
    else:
        print('Trapped!')
