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
        d, s = heappop(pq)
        for t in edges[s]:
            if dist[t] > d+1:
                dist[t] = d+1
                heappush(pq, (dist[t], t))
    return dist

N, M, K, X = map(int, input().split())
edges = [[] for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    edges[a].append(b)

exist = False
for i, d in enumerate(dijkstra(X)):
    if d == K:
        exist = True
        print(i)
if not exist:
    print(-1)
