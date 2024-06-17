import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e9)
mv = [[-1,0],[0,-1],[1,0],[0,1]]

N, M = map(int, input().split())
B = ['']*N

trash = [[0]*M for _ in range(N)]
dist = [[(INF, INF)]*(M+1) for _ in range(N+1)]
pq = []

for i in range(N):
    for j, c in enumerate(input().rstrip()):
        if c == 'S':
            dist[i][j] = (0, 0)
            heappush(pq, (0, 0, i, j))
        elif c == 'g':
            for di, dj in mv:
                if 0 <= (ni:=i+di) < N and 0 <= (nj:=j+dj) < M:
                    trash[ni][nj] = 1
        B[i] += c

while pq:
    a, b, x, y = heappop(pq)

    if dist[x][y] < (a, b):
        continue

    if B[x][y] == 'F':
        print(a, b)
        break

    for dx, dy in mv:
        nx, ny = x+dx, y+dy
        if 0 <= nx < N and 0 <= ny < M:
            if B[nx][ny] == 'g' and dist[nx][ny] > (a+1, b):
                dist[nx][ny] = (a+1, b)
                heappush(pq, (a+1, b, nx, ny))
            elif B[nx][ny] == '.':
                if dist[nx][ny] > (a, nb:=b+trash[nx][ny]):
                    dist[nx][ny] = (a, nb)
                    heappush(pq, (a, nb, nx, ny))
            elif B[nx][ny] == 'F':
                dist[nx][ny] = (a, b)
                heappush(pq, (a, b, nx, ny))
