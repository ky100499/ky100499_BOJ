import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

def dijkstra(s):
    dist = [INF]*(D+1)
    dist[s] = 0

    pq = [(0, s)]
    while pq:
        _, s = heappop(pq)
        for t, d in edges[s]:
            if dist[t] > dist[s]+d:
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))
    return dist

N, D = map(int, input().split())
edges = [[(i+1, 1)] for i in range(D)]+[[]]
for _ in range(N):
    s, t, d = map(int, input().split())
    if t <= D:
        for i, v in enumerate(edges[s]):
            if v[0] == t:
                edges[s][i] = (t, min(d, v[1]))
                break
        else:
            edges[s].append((t, d))
print(dijkstra(0)[-1])
