import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**12

def dijkstra(x, y):
    dist = [[INF]*W for _ in range(H)]
    dist[x][y] = 0

    pq = [(0, x, y)]
    while pq:
        d, x, y = heappop(pq)

        for dx, dy in [[-1,0],[0,-1],[1,0],[0,1]]:
            nx, ny = x+dx, y+dy
            if 0 <= nx < H and 0 <= ny < W:
                if dist[nx][ny] > dist[x][y]+plane[nx][ny]:
                    dist[nx][ny] = dist[x][y]+plane[nx][ny]
                    heappush(pq, (dist[nx][ny], nx, ny))
            else:
                return d

for _ in range(int(input())):
    K, W, H = map(int, input().split())
    cl = {'E': -1}
    for _ in range(K):
        k, v = input().split()
        cl[k] = int(v)

    plane = []
    for r in range(H):
        row = list(map(lambda x: cl[x], input().strip()))
        if -1 in row:
            c = row.index(-1)
            en = (r, c)
            row[c] = 0
        plane.append(row)

    print(dijkstra(*en))
