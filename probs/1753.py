import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

import heapq

INF = 10**8

def dijkstra(s, edges):
    distance = [0 if i == s else INF for i in range(V+1)]
    pq = []
    heapq.heappush(pq, (0, s))

    while pq:
        d, s = heapq.heappop(pq)
        for to, dist in edges[s]:
            if distance[to] > d+dist:
                distance[to] = d+dist
                heapq.heappush(pq, (distance[to], to))

    return distance

V, E = map(int, input().split())
K = int(input())
edges = [[] for _ in range(V+1)]
for _ in range(E):
    u, v, w = map(int, input().split())
    for i, (node, weight) in enumerate(edges[u]):
        if node == v:
            edges[u][i] = (v, min(weight, w))
            break
    else:
        edges[u].append((v, w))

for i, d in enumerate(dijkstra(K, edges)):
    if i == 0:
        continue
    print('INF' if d == INF else d)
