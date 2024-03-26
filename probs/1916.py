import sys
input = sys.stdin.readline

import heapq

input = open('input.txt', 'r').readline

def dijkstra(f, t, edges, distance):
    pq = []
    heapq.heappush(pq, (0, f))
    while pq:
        d, f = heapq.heappop(pq)
        for to, dist in enumerate(edges[f]):
            if dist == INF:
                continue
            if distance[to] > d + dist:
                distance[to] = d + dist
                heapq.heappush(pq, (distance[to], to))


INF = 9999999

N = int(input())
M = int(input())
edges = [[INF]*(N+1) for _ in range(N+1)]
for i in range(N+1):
    edges[i][i] = 0
for _ in range(M):
    f, t, d = map(int, input().split())
    edges[f][t] = min(edges[f][t], d)
f, t = map(int, input().split())
dist = [10e9]*(N+1)
dist[f] = 0
dijkstra(f, t, edges, dist)
print(dist[t])
