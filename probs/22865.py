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

dist = [INF]*(N+1)
dist[0] = 0
for p in P:
    for i, d in enumerate(dijkstra(p)):
        if d == INF:
            dist[i] = 0
        else:
            dist[i] = min(dist[i], d)
print(dist.index(max(dist)))
