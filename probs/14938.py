import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

def dijkstra(s):
    dist = [INF]*n
    dist[s] = 0
    pq = [(0, s)]

    while pq:
        _, s = heappop(pq)
        for t, d in edges[s]:
            if dist[t] > dist[s]+d:
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))
    return dist

n, m, r = map(int, input().split())
items = list(map(int, input().split()))
edges = [[] for _ in range(n+1)]
for _ in range(r):
    a, b, l = map(int, input().split())
    edges[a-1].append((b-1, l))
    edges[b-1].append((a-1, l))

ans = 0
for i in range(n):
    item = 0
    for j, d in enumerate(dijkstra(i)):
        if d <= m:
            item += items[j]
    ans = max(ans, item)
print(ans)
