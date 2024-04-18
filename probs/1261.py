import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

def dijkstra(s):
    dist = [[INF]*M for _ in range(N)]
    dist[0][0] = 0
    pq = [(0, *s)]    # (d, x, y)

    while pq:
        _, r, c = heappop(pq)

        if (r, c) == (N-1, M-1):
            return dist

        for dr, dc in [[-1,0],[0,-1],[1,0],[0,1]]:
            nr, nc = r+dr, c+dc
            if 0 <= nr < N and 0 <= nc < M and dist[nr][nc] > dist[r][c]+maze[r][c]:
                dist[nr][nc] = dist[r][c]+maze[r][c]
                heappush(pq, (dist[nr][nc], nr, nc))

M, N = map(int, input().split())
maze = [list(map(int, input().strip())) for _ in range(N)]
print(dijkstra((0, 0))[-1][-1])
