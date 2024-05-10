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
        for t, d in edges[s].items():
            if dist[t] > dist[s]+d:
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))
    return dist

V, E, P = map(int, input().split())
edges = [{} for _ in range(V+1)]
for _ in range(E):
    a, b, c = map(int, input().split())
    edges[a][b] = c
    edges[b][a] = c

mj = dijkstra(1)
gw = dijkstra(P)

if mj[V] == mj[P]+gw[V]:
    print('SAVE HIM')
else:
    print('GOOD BYE')
