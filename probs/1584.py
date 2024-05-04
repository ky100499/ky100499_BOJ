import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

mv = [[-1,0], [0,-1], [1,0], [0,1]]

def dijkstra():
    dist = [[INF]*501 for _ in range(501)]
    dist[0][0] = 0

    pq = [(0, 0, 0)]
    while pq:
        d, x, y = heappop(pq)

        if x==500 and y==500:
            return d

        for dx, dy in mv:
            nx, ny = x+dx, y+dy
            if 0 <= nx <= 500 and 0 <= ny <= 500 and b[nx][ny] < 2 and dist[nx][ny] > d+b[nx][ny]:
                dist[nx][ny] = d+b[nx][ny]
                heappush(pq, (dist[nx][ny], nx, ny))
    return -1

b = [[0]*501 for _ in range(501)]

for _ in range(int(input())):
    x1, y1, x2, y2 = map(int, input().split())
    for x in range(min(x1, x2), max(x1, x2)+1):
        for y in range(min(y1, y2), max(y1, y2)+1):
            b[x][y] = 1
for _ in range(int(input())):
    x1, y1, x2, y2 = map(int, input().split())
    for x in range(min(x1, x2), max(x1, x2)+1):
        for y in range(min(y1, y2), max(y1, y2)+1):
            b[x][y] = 2

print(dijkstra())
