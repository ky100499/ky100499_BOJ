import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

def dijkstra(s):
    dist = [INF]*(n+1)
    dist[s] = 0
    pq = [(0, s)]

    while pq:
        _, s = heappop(pq)
        for t, d in edges[s]:
            if dist[t] > dist[s]+d:
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))
    return dist

n = int(input())
edges = [[] for _ in range(n+1)]
for _ in range(int(input())):
    a, b, c = map(int, input().split())
    for i, (bb, cc) in enumerate(edges[a]):
        if b == bb:
            edges[a][i] = (b, min(c, cc))
            break
    else:
        edges[a].append((b, c))

for i in range(1, n+1):
    print(' '.join(map(lambda x: '0' if x == INF else str(x), dijkstra(i)[1:])))
