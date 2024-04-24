import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

mv = [[-1,0], [0,1], [1,0], [0,-1]]

def dijkstra(s, goal):
    dist = [[INF]*W for _ in range(H)]
    dist[s[0]][s[1]] = 0

    visited = [[0]*W for _ in range(H)]

    pq = []
    for i in range(4):
        heappush(pq, (0, i, *s))

    while pq:
        n, d, x, y = heappop(pq)

        if (x, y) == goal:
            return n

        if visited[x][y] > 4:
            continue
        visited[x][y] += 1

        for dd in [-1, 0, 1]:
            nd = (d+dd)%4
            nx, ny = x+mv[nd][0], y+mv[nd][1]
            nn = n+int(dd!=0)
            if 0 <= nx < H and 0 <= ny < W and M[nx][ny] != '*' and dist[nx][ny] >= nn:
                dist[nx][ny] = nn
                heappush(pq, (nn, nd, nx, ny))

W, H = map(int, input().split())
M = []
C = []
for h in range(H):
    M.append(input().strip())
    for i, c in enumerate(M[-1]):
        if c == 'C':
            C.append((h, i))

print(dijkstra(*C))
