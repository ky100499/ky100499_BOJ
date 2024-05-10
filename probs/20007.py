import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop, heapify

INF = 10**12

def dijkstra(s):
    dist = [INF]*N
    dist[s] = 0

    pq = [(0, s)]
    while pq:
        _, s = heappop(pq)
        for t, d in edges[s].items():
            if dist[t] > dist[s]+d:
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))
    return dist

N, M, X, Y = map(int, input().split())
edges = [{} for _ in range(N)]
for _ in range(M):
    a, b, c = map(int, input().split())
    edges[a][b] = c
    edges[b][a] = c

dist = dijkstra(Y)
heapify(dist)

s = 0
cnt = 1
while dist:
    d = heappop(dist)
    if 2 * d > X:
        dist.append(d)
        break
    elif s+2*d > X:
        cnt += 1
        s = 0
    s += 2*d
print(-1 if dist else cnt)
