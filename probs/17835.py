import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**12

def dijkstra(starts):
    dist = [INF]*(N+1)
    pq = []
    for s in starts:
        dist[s] = 0
        heappush(pq, (0, s))

    while pq:
        sd, s = heappop(pq)

        if sd > dist[s]:
            continue

        for t, d in edges[s].items():
            if dist[t] > dist[s] + d:
                dist[t] = dist[s] + d
                heappush(pq, (dist[t], t))
    return dist

N, M, K = map(int, input().split())

edges = [{} for _ in range(N+1)]
for _ in range(M):
    u, v, c = map(int, input().split())
    if u in edges[v]:
        edges[v][u] = min(edges[v][u], c)
    else:
        edges[v][u] = c

itv = list(map(int, input().split()))

dist = dijkstra(itv)[1:]
max_d = max(dist)
print(dist.index(max_d)+1)
print(max_d)
