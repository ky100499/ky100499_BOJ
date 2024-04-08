import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

def dijkstra(s):
    dist = [INF] * (N+1)
    dist[s] = 0

    pq = [(0, s)]
    while pq:
        _, s = heappop(pq)
        for t, d in edges[s]:
            if dist[t] > dist[s]+d:
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))
    return dist

N, M = map(int, input().split())

edges = [[] for _ in range(N+1)]
for _ in range(N-1):
    u, v, w = map(int, input().split())
    edges[u].append((v, w))
    edges[v].append((u, w))

for _ in range(M):
    s, t = map(int, input().split())
    print(dijkstra(s)[t])
