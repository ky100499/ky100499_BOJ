import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

def dijkstra():
    dist = [[INF]*N for _ in range(N)]
    dist[0][0] = 0
    pq = [(0, 0, 0)]

    while pq:
        d, r, c = heappop(pq)

        if r == c == N-1:
            return d

        for dr, dc in [[-1,0],[0,-1],[1,0],[0,1]]:
            nr, nc = r+dr, c+dc
            if 0 <= nr < N and 0 <= nc < N and dist[nr][nc] > d+(maze[nr][nc]^1):
                dist[nr][nc] = d+(maze[nr][nc]^1)
                heappush(pq, (dist[nr][nc], nr, nc))

N = int(input())
maze = [list(map(int, input().strip())) for _ in range(N)]
print(dijkstra())
