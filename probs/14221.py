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
        _, s = heappop(pq)
        for t, d in edges[s].items():
            if dist[t] > dist[s] + d:
                dist[t] = dist[s] + d
                heappush(pq, (dist[t], t))
    return dist

N, M = map(int, input().split())

edges = [{} for _ in range(N+1)]
for _ in range(M):
    u, v, c = map(int, input().split())
    if v in edges[u]:
        edges[u][v] = min(edges[u][v], c)
    else:
        edges[u][v] = c
    edges[v][u] = edges[u][v]

input()

cands = list(map(int, input().split()))
stores = list(map(int, input().split()))

m = INF
for i, d in enumerate(dijkstra(stores)):
    if i in cands and m > d:
        m = d
        ans = i
print(ans)
