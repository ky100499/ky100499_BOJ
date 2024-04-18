import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

def dijkstra():
    dist = [[INF]*N for _ in range(N)]
    dist[0][0] = maze[0][0]
    pq = [(maze[0][0], 0, 0)]   # (d, x, y)

    while pq:
        d, r, c = heappop(pq)

        if r == c == N-1:
            return d

        for dr, dc in [[-1,0],[0,-1],[1,0],[0,1]]:
            nr, nc = r+dr, c+dc
            if 0 <= nr < N and 0 <= nc < N and dist[nr][nc] > d+maze[nr][nc]:
                dist[nr][nc] = d+maze[nr][nc]
                heappush(pq, (dist[nr][nc], nr, nc))

i = 1
while True:
    N = int(input())
    if N == 0:
        break

    maze = [list(map(int, input().split())) for _ in range(N)]
    print(f'Problem {i}: {dijkstra()}')
    i += 1
