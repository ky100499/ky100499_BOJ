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

V, E = map(int, input().split())
edges = [{} for _ in range(V+1)]
for _ in range(E):
    s, t, d = map(int, input().split())
    if t in edges[s]:
        edges[s][t] = min(edges[s][t], d)
        edges[t][s] = edges[s][t]
    else:
        edges[s][t] = d
        edges[t][s] = d

dist = {}
path = []
for p in map(int, input().split()):
    if path:
        prev = path[-1]
        if prev[0] not in dist:
            dist[prev[0]] = dijkstra(prev[0])
        if dist[prev[0]][p] != INF:
            path.append((p, dist[prev[0]][p]+prev[1]))
    else:
        path.append((p, 0))

me = dijkstra(int(input()))
ans = INF
for p, d in path:
    if me[p] <= d:
        ans = min(ans, p)

print(ans if ans != INF else -1)
