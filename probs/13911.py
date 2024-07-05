import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e9)

def dijkstra(starts):
    dist = [INF]*(V+1)
    pq = []
    for s in starts:
        dist[s] = 0
        heappush(pq, (0, s))

    while pq:
        sd, s = heappop(pq)

        if dist[s] < sd:
            continue

        for t, d in G[s].items():
            if dist[t] > sd+d:
                dist[t] = sd+d
                heappush(pq, (sd+d, t))

    return dist

V, E = map(int, input().split())
G = [{} for _ in range(V+1)]
for _ in range(E):
    u, v, w = map(int, input().split())
    if v in G[u]:
        G[u][v] = G[v][u] = min(G[u][v], w)
    else:
        G[u][v] = G[v][u] = w
_, x = map(int, input().split())
M = list(map(int, input().split()))
_, y = map(int, input().split())
S = list(map(int, input().split()))

ans = INF
for md, sd in zip(dijkstra(M), dijkstra(S)):
    if 0 < md <= x and 0 < sd <= y:
        ans = min(ans, md+sd)
print(-1 if ans == INF else ans)
