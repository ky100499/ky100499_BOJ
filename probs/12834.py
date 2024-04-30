import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**12

def dijkstra(s):
    dist = [INF]*(V+1)
    dist[s] = 0

    pq = [(0, s)]
    while pq:
        _, s = heappop(pq)
        for t, d in edges[s]:
            if dist[t] > dist[s]+d:
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))
    return list(map(lambda x: -1 if x == INF else x, dist))

N, V, E = map(int, input().split())
A, B = map(int, input().split())

H = list(map(int, input().split()))

edges = [[] for _ in range(V+1)]
for _ in range(E):
    a, b, l = map(int, input().split())
    edges[a].append((b, l))
    edges[b].append((a, l))

ans = 0
for h in H:
    d = dijkstra(h)
    ans += d[A]+d[B]
print(ans)
