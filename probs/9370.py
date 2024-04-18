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
        _, s = heappop(pq)
        for t, d in enumerate(edges[s]):
            if d == INF:
                continue
            if dist[t] > dist[s]+d:
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))
    return dist

for _ in range(int(input())):
    N, M, T = map(int, input().split())
    s, g, h = map(int, input().split())

    edges = [[INF]*(N+1) for _ in range(N+1)]
    for _ in range(M):
        a, b, d = map(int, input().split())
        edges[a][b] = min(edges[a][b], d*2)
        edges[b][a] = edges[a][b]
    edges[g][h] -= 1
    edges[h][g] -= 1

    cand = [int(input()) for _ in range(T)]
    cand.sort()

    dist = dijkstra(s)
    for c in cand:
        if dist[c] % 2:
            print(c, end=' ')
    print()
