import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

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

N, M = map(int, input().split())
edges = [{} for _ in range(N+1)]
for _ in range(M):
    a, b, c = map(int, input().split())
    if b in edges[a]:
        edges[a][b] = min(edges[a][b], c)
    else:
        edges[a][b] = c
    edges[b][a] = edges[a][b]
print(dijkstra(1)[-1])
