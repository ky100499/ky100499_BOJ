import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop, heapify

INF = 10**12

def dijkstra(s):
    dist = [INF]*(N+1)
    dist[s] = 0

    pq = [(0, s)]
    while pq:
        _, s = heappop(pq)
        for t, d in edges[s].items():
            if dist[t] > dist[s]+d:
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))
    return dist

N = int(input())
P = map(int, input().split())
M = int(input())

edges = [{} for _ in range(N+1)]
for _ in range(M):
    a, b, c = map(int, input().split())
    if b in edges[a]:
        edges[a][b] = min(edges[a][b], c)
    else:
        edges[a][b] = c
    edges[b][a] = c

dists = [dijkstra(p) for p in P]
m, ans = 0, 0
for i in range(1, N+1):
    mm = min([dists[x][i] for x in range(3)])
    if mm > m:
        m = mm
        ans = i
print(ans)
