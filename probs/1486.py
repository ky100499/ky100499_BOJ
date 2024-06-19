import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e9)

N, M, T, D = map(int, input().split())
B = [[0]*M for _ in range(N)]
for i in range(N):
    for j, c in enumerate(input().rstrip()):
        c = ord(c)
        if c <= ord('Z'):
            B[i][j] = c-ord('A')
        else:
            B[i][j] = c-ord('a')+26

dist = [[INF]*M for _ in range(N)]
dist[0][0] = 0
pq = [(0, 0, 0)]
while pq:
    cd, x, y = heappop(pq)

    if dist[x][y] < cd:
        continue

    for dx, dy in [[-1,0], [0,1], [1,0], [0,-1]]:
        nx, ny = x+dx, y+dy
        if 0 <= nx < N and 0 <= ny < M and abs(B[x][y] - B[nx][ny]) <= T:
            if B[x][y] < B[nx][ny]:
                dt = (B[nx][ny] - B[x][y]) ** 2
            else:
                dt = 1
            if cd+dt <= D and dist[nx][ny] > cd+dt:
                dist[nx][ny] = cd+dt
                heappush(pq, (cd+dt, nx, ny))

dist2 = [[INF]*M for _ in range(N)]
dist2[0][0] = 0
pq = [(0, 0, 0)]
while pq:
    cd, x, y = heappop(pq)

    if dist2[x][y] < cd:
        continue

    for dx, dy in [[-1,0], [0,1], [1,0], [0,-1]]:
        nx, ny = x+dx, y+dy
        if 0 <= nx < N and 0 <= ny < M and abs(B[x][y] - B[nx][ny]) <= T:
            if B[x][y] > B[nx][ny]:
                dt = (B[nx][ny] - B[x][y]) ** 2
            else:
                dt = 1
            if cd+dt <= D and dist2[nx][ny] > cd+dt:
                dist2[nx][ny] = cd+dt
                heappush(pq, (cd+dt, nx, ny))

ans = 0
for i in range(N):
    for j in range(M):
        if dist[i][j]+dist2[i][j] <= D:
            ans = max(ans, B[i][j])
print(ans)
