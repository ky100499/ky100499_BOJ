import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop
from collections import deque

INF = 10**8

def dijkstra(s, g):
    dist = [INF]*N
    dist[s] = 0
    prev = [[] for _ in range(N)]
    pq = [(0, s)]

    while pq:
        _, s = heappop(pq)
        for t, d in edges[s].items():
            if dist[t] > dist[s]+d:
                prev[t] = [s]
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))
            elif dist[t] == dist[s]+d:
                prev[t].append(s)

    return dist, prev

while True:
    N, M = map(int, input().split())
    if N == 0:
        break

    S, D = map(int, input().split())

    edges = [{} for _ in range(N)]
    for _ in range(M):
        u, v, p = map(int, input().split())
        edges[u][v] = p

    _, prev = dijkstra(S, D)

    q = deque([D])
    while q:
        node = q.popleft()
        for p in prev[node]:
            if node in edges[p]:
                edges[p].pop(node)
                q.append(p)

    dist, _ = dijkstra(S, D)
    print(-1 if dist[D] == INF else dist[D])
