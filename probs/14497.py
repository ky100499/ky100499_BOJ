import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e9)
mv = [[-1,0],[0,-1],[1,0],[0,1]]

N, M = map(int, input().split())
x1, y1, x2, y2 = map(lambda x: int(x)-1, input().split())
B = [input().rstrip() for _ in range(N)]

dist = [[INF]*(M) for _ in range(N)]
dist[x1][y1] = 0
pq = [(0, x1, y1)]

while pq:
    cd, x, y = heappop(pq)

    if dist[x][y] < cd:
        continue

    if (x, y) == (x2, y2):
        print(cd)
        break

    for dx, dy in mv:
        nx, ny = x+dx, y+dy
        if 0 <= nx < N and 0 <= ny < M:
            if B[nx][ny] in '1#' and dist[nx][ny] > cd+1:
                dist[nx][ny] = cd+1
                heappush(pq, (cd+1, nx, ny))
            elif B[nx][ny] == '0' and dist[nx][ny] > cd:
                dist[nx][ny] = cd
                heappush(pq, (cd, nx, ny))
