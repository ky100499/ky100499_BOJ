import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e9)

def dijkstra():
    dist = [INF]*(N+1)
    dist[1] = 0
    prev = [-1]*(N+1)

    pq = [(0, 1)]
    while pq:
        sd, s = heappop(pq)

        if dist[s] < sd:
            continue

        if s == N:
            break

        for t, d in edges[s].items():
            if dist[t] > sd+d:
                prev[t] = s
                dist[t] = sd+d
                heappush(pq, (sd+d, t))

    return dist, prev

N, M = map(int, input().split())
edges = [{} for _ in range(N+1)]
for _ in range(M):
    a, b, t = map(int, input().split())
    edges[a][b] = edges[b][a] = t

dist, prev = dijkstra()
min_d = dist[N]
ans = 0
curr = N
while prev[curr] != -1:
    tmp = edges[prev[curr]][curr]
    edges[prev[curr]][curr] = INF
    ndist, _ = dijkstra()
    if ndist[N] == INF:
        ans = -1
        break
    else:
        ans = max(ans, ndist[N] - min_d)
    edges[prev[curr]][curr] = tmp
    curr = prev[curr]

print(ans)
