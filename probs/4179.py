import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

R, C = map(int, input().split())
maze = []
fires, jihun = [], []
for i in range(R):
    row = list(input().strip())
    for j in range(C):
        if row[j] in '.#':
            row[j] = '.#'.index(row[j])
        elif row[j] == 'F':
            row[j] = 2
            fires.append((i, j))
        else:
            row[j] = 0
            jihun.append((i, j))
    maze.append(row)

t = 0
visited = set()
escape = False
while jihun and not escape:
    t += 1

    new_fires = []
    for fire in fires:
        x, y = fire
        for dx, dy in [[-1,0],[0,-1],[1,0],[0,1]]:
            nx, ny = x+dx, y+dy
            if 0 <= nx < R and 0 <= ny < C and maze[nx][ny] == 0:
                maze[nx][ny] = 2
                new_fires.append((nx, ny))
    fires = new_fires

    new_jihun = []
    for jh in jihun:
        if jh[0] in (0, R-1) or jh[1] in (0, C-1):
            escape = True
            break

        x, y = jh
        if jh in visited:
            continue
        visited.add(jh)

        for dx, dy in [[-1,0],[0,-1],[1,0],[0,1]]:
            nx, ny = x+dx, y+dy
            if 0 <= nx < R and 0 <= ny < C and maze[nx][ny] == 0:
                new_jihun.append((nx, ny))
    jihun = new_jihun

if escape:
    print(t)
else:
    print('IMPOSSIBLE')
