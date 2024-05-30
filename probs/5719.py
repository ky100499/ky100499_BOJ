import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

def dijkstra(s, g):
    dist = [INF]*N
    dist[s] = 0
    prev = [-1]*N
    pq = [(0, s)]

    while pq:
        _, s = heappop(pq)
        if s == g:
            break
        for t, d in edges[s].items():
            if dist[t] > dist[s]+d:
                prev[t] = s
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))

    return dist, prev

while True:
    N, M = map(int, input().split())
    if N == 0:
        break

    S, D = map(int, input().split())

    edges = [{} for _ in range(N)]
    for _ in range(M):
        u, v, p = map(int, input().split())
        edges[u][v] = p

    min_d = INF
    while True:
        dist, prev = dijkstra(S, D)

        if dist[D] > min_d:
            print(-1 if dist[D] == INF else dist[D])
            break
        else:
            min_d = dist[D]

        node = D
        while prev[node] != -1:
            edges[prev[node]].pop(node)
            node = prev[node]
