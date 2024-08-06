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
        sd, s = heappop(pq)

        if dist[s] < sd:
            continue

        for t, d in G[s].items():
            if H[s] < H[t] and dist[t] > sd+d:
                dist[t] = sd+d
                heappush(pq, (sd+d, t))

    return dist

N, M, D, E = map(int, input().split())
H = [0]+list(map(int, input().split()))

G = [{} for _ in range(N+1)]
for _ in range(M):
    a, b, n = map(int, input().split())
    if b in G[a]:
        G[a][b] = G[b][a] = min(G[a][b], n)
    else:
        G[a][b] = G[b][a] = n

ans = None
for i, d1, d2 in zip(range(N), dijkstra(1), dijkstra(N)):
    if d1 != INF and d2 != INF:
        v = H[i]*E - (d1+d2)*D
        if ans is None:
            ans = v
        else:
            ans = max(ans, v)
print('Impossible' if ans is None else ans)
