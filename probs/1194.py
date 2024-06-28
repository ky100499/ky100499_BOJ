import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e9)

doors = {chr(i): i - ord('A') for i in range(ord('A'), ord('F')+1)}
keys = {chr(i): i - ord('a') for i in range(ord('a'), ord('f')+1)}

N, M = map(int, input().split())
B = []
for i in range(N):
    B.append(input().rstrip())
    for j, c in enumerate(B[i]):
        if c == '0':
            s = (i, j)
B[s[0]] = B[s[0]][:s[1]] + '.' + B[s[0]][s[1]+1:]

dist = [[[INF]*(1<<6) for _ in range(M)] for _ in range(N)]
dist[s[0]][s[1]][0] = 0
pq = [(0, *s, 0)]
while pq:
    cd, x, y, k = heappop(pq)

    if dist[x][y][k] < cd:
        continue

    if B[x][y] == '1':
        print(cd)
        break

    for dx, dy in [[-1,0], [0,1], [1,0], [0,-1]]:
        nx, ny = x+dx, y+dy
        if 0 <= nx < N and 0 <= ny < M:
            if B[nx][ny] in '.1' and dist[nx][ny][k] > cd+1:
                dist[nx][ny][k] = cd+1
                heappush(pq, (cd+1, nx, ny, k))
            elif B[nx][ny] in keys and dist[nx][ny][(nk := k|(1<<keys[B[nx][ny]]))] > cd+1:
                dist[nx][ny][nk] = cd+1
                heappush(pq, (cd+1, nx, ny, nk))
            elif B[nx][ny] in doors and k & (1<<doors[B[nx][ny]]) and dist[nx][ny][k] > cd+1:
                dist[nx][ny][k] = cd+1
                heappush(pq, (cd+1, nx, ny, k))
else:
    print(-1)
