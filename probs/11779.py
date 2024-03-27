import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

def dijkstra(s):
    dist = [INF] * (n+1)
    dist[s] = 0
    prev = [-1] * (n+1)
    pq = [(0, s)]
    while pq:
        _, s = heappop(pq)
        for t, d in edges[s]:
            if dist[t] > dist[s] + d:
                dist[t] = dist[s] + d
                prev[t] = s
                heappush(pq, (dist[t], t))
    return (dist, prev)

def bt(prev, t):
    if t == -1:
        return []
    return bt(prev, prev[t]) + [t]

n = int(input())
m = int(input())
edges = [[] for _ in range(n+1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    for i, (vv, ww) in enumerate(edges[u]):
        if v == vv:
            edges[u][i] = (v, min(w, ww))
            break
    else:
        edges[u].append((v, w))

s, t = map(int, input().split())

dist, prev = dijkstra(s)
route = bt(prev, t)
print(dist[t])
print(len(route))
print(*route, sep=' ')
