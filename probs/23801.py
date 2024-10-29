import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e12)

def dijkstra(s):
    dist = [INF]*(N+1)
    dist[s] = 0
    pq = [(0, s)]

    while pq:
        d, s = heappop(pq)

        if dist[s] < d:
            continue

        for t, w in G[s].items():
            if dist[t] > d+w:
                dist[t] = d+w
                heappush(pq, (d+w, t))

    return dist

N, M = map(int, input().split())
G = [{} for _ in range(N+1)]
for _ in range(M):
    u, v, w = map(int, input().split())
    if v in G[u]:
        G[u][v] = G[v][u] = min(G[u][v], w)
    else:
        G[u][v] = G[v][u] = w
X, Z = map(int, input().split())
input()

ans = INF
dx, dz = dijkstra(X), dijkstra(Z)
for p in map(int, input().split()):
    ans = min(ans, dx[p]+dz[p])
print(-1 if ans == INF else ans)
