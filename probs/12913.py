import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**12

def dijkstra():
    dist = [[INF]*(K+1) for _ in range(N)]
    dist[0][0] = 0

    pq = [(0, 0, 0)]
    while pq:
        _, s, k = heappop(pq)
        if s == 1:
            return dist[s][k]
        for t, d in enumerate(edges[s]):
            if s == t:
                continue
            if dist[t][k] > dist[s][k] + d:
                dist[t][k] = dist[s][k] + d
                heappush(pq, (dist[t][k], t, k))
            if k < K and dist[t][k+1] > dist[s][k] + d/2:
                dist[t][k+1] = dist[s][k] + d/2
                heappush(pq, (dist[t][k+1], t, k+1))

N, K = map(int, input().split())

edges = []
for _ in range(N):
    edges.append(list(map(int, input().strip())))

print(dijkstra())
