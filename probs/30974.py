import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**12

def dijkstra(s):
    dist = [INF]*(N+1)
    dist[s] = 0

    pq = [(0, s)]

    while pq:
        _, s = heappop(pq)

        if s == N:
            break

        for t, w in edges[s].items():
            if dist[t] > dist[s]+w:
                dist[t] = dist[s]+w
                heappush(pq, (dist[t], t))
    return dist

primes = [1]*10_000_001
for i in range(2, 10_000_001):
    if primes[i] == 1:
        j = i*i
        while j < 10_000_001:
            primes[j] = 0
            j += i

N, M = map(int, input().split())
D = [0]+list(map(int, input().split()))
edges = [{} for _ in range(N+1)]
for _ in range(M):
    u, v, w = map(int, input().split())
    if primes[D[u]+D[v]]:
        if v in edges[u]:
            edges[u][v] = min(edges[u][v], w)
        else:
            edges[u][v] = w
        edges[v][u] = edges[u][v]

ans = dijkstra(1)[-1]
print('Now where are you?' if ans == INF else ans)
