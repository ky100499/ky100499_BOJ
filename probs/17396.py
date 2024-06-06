import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**12

N, M = map(int, input().split())
vis = list(map(int, input().split()))

edges = [{} for _ in range(N)]
for _ in range(M):
    a, b, t = map(int, input().split())
    if (not vis[a] or a == N-1) and (not vis[b] or b == N-1):
        edges[a][b] = t
        edges[b][a] = t

dist = [INF] * (N+1)
dist[0] = 0
pq = [(0, 0)]

while pq:
    sd, s = heappop(pq)

    if s == N-1:
        print(dist[s])
        break

    if sd > dist[s]:
        continue

    for t, d in edges[s].items():
        if dist[t] > dist[s]+d:
            dist[t] = dist[s]+d
            heappush(pq, (dist[t], t))
else:
    print(-1)
