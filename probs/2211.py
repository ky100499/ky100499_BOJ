import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**8

N, M = map(int, input().split())

edges = [{} for _ in range(N+1)]
for _ in range(M):
    a, b, c = map(int, input().split())
    edges[a][b] = c
    edges[b][a] = c

dist = [INF] * (N+1)
dist[1] = 0
prev = [-1] * (N+1)
pq = [(0, 1)]

while pq:
    _, s = heappop(pq)
    for t, d in edges[s].items():
        if dist[t] > dist[s]+d:
            dist[t] = dist[s]+d
            prev[t] = s
            heappush(pq, (dist[t], t))

rest = set()
for i in range(2, N+1):
    curr = i
    while prev[curr] != -1:
        a, b = sorted([curr, prev[curr]])
        rest.add((a, b))
        curr = prev[curr]

print(len(rest))
for r in rest:
    print(*r)
