import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

def dijkstra(s):
    dist = [INF]*(n+1)
    dist[s] = 0
    pq = [(0, s)]

    while pq:
        _, s = heappop(pq)
        for t, d in edges[s]:
            if dist[t] > dist[s]+d:
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))

    return dist

n, m = map(int, input().split())
edges = [[] for _ in range(n+1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    edges[a].append((b, c))
    edges[b].append((a, c))
s, t = map(int, input().split())
print(dijkstra(s)[t])
