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

INF = 999999

N, M, X = map(int, input().split())

edges = [[INF]*(N+1) for _ in range(N+1)]
edges_rev = [[INF]*(N+1) for _ in range(N+1)]
for _ in range(M):
    s, e, t = map(int, input().split())
    edges[s][e] = t
    edges_rev[e][s] = t

dist_go = [INF]*(N+1)
dist_back = [INF]*(N+1)
dist_go[X] = 0
dist_back[X] = 0
dijkstra(X, edges_rev, dist_go)
dijkstra(X, edges, dist_back)
ans = 0
for i in range(1, N+1):
    ans = max(ans, dist_go[i]+dist_back[i])
print(ans)
