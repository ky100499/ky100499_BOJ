import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e12)

N, M, K = map(int, input().split())
edges = [{} for _ in range(N+1)]
for _ in range(M):
    u, v, w = map(int, input().split())
    if v in edges[u]:
        edges[u][v] = edges[v][u] = min(edges[u][v], w)
    else:
        edges[u][v] = edges[v][u] = w

dist = [[INF]*(K+1) for _ in range(N+1)]
dist[1][0] = 0
pq = [(0, 1, 0)]
while pq:
    sd, s, k = heappop(pq)

    if dist[s][k] < sd:
        continue

    if s == N:
        print(sd)
        break

    for t, d in edges[s].items():
        if dist[t][k] > sd+d:
            dist[t][k] = sd+d
            heappush(pq, (sd+d, t, k))
        if k < K and dist[t][k+1] > sd:
            dist[t][k+1] = sd
            heappush(pq, (sd, t, k+1))
