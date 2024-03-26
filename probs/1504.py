import sys
input = sys.stdin.readline

import heapq

input = open('input.txt', 'r').readline

def dijkstra(s, edges, distance):
    pq = []
    heapq.heappush(pq, (0, s))
    while pq:
        d, s = heapq.heappop(pq)
        for to, dist in enumerate(edges[s]):
            if dist == INF:
                continue
            if distance[to] > d + dist:
                distance[to] = d + dist
                heapq.heappush(pq, (distance[to], to))

INF = 10**8

N, E = map(int, input().split())
edges = [[INF]*(N+1) for _ in range(N+1)]
for i in range(1, N+1):
    edges[i][i] = 0
for _ in range(E):
    a, b, c = map(int, input().split())
    edges[a][b], edges[b][a] = c, c
v1, v2 = map(int, input().split())

d1 = [0 if i == 1 else INF for i in range(N+1)]
d2 = [0 if i == v1 else INF for i in range(N+1)]
d3 = [0 if i == v2 else INF for i in range(N+1)]
dijkstra(1, edges, d1)
dijkstra(v1, edges, d2)
dijkstra(v2, edges, d3)

if INF in [d1[v1], d2[v2], d3[N], d1[v2], d3[v1], d2[N]]:
    print(-1)
else:
    print(
        min(
            d1[v1]+d2[v2]+d3[N],
            d1[v2]+d3[v1]+d2[N]
        )
    )
