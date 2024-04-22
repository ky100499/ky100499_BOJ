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
        d, s = heappop(pq)
        for t, td in edges[s]:
            if dist[t] > d+td:
                dist[t] = d+td
                heappush(pq, (d+td, t))
    return dist

for _ in range(int(input())):
    N, D, C = map(int, input().split())
    edges = [[] for _ in range(N+1)]
    for _ in range(D):
        a, b, s = map(int, input().split())
        edges[b].append((a, s))

    injected = list(filter(lambda x: x != INF, dijkstra(C)))
    print(len(injected), max(injected))
