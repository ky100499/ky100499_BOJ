import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

N, M, K = map(int, input().split())
G = [{} for _ in range(N+1)]

for _ in range(M):
    a, b, c = map(int, input().split())
    if b in G[a]:
        G[a][b] = min(G[a][b], c)
    else:
        G[a][b] = c

dist = [[] for _ in range(N+1)]
dist[1].append(0)
pq = [(0, 1)]
while pq:
    sd, s = heappop(pq)

    if dist[s] and -dist[s][0] < sd:
        continue

    for t, d in G[s].items():
        if len(dist[t]) < K or -dist[t][0] > sd+d:
            if len(dist[t]) == K:
                heappop(dist[t])
            heappush(dist[t], -(sd+d))
            heappush(pq, (sd+d, t))
for d in dist[1:]:
    print(-d[0] if len(d) == K else -1)
