import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**12

def dijkstra(s):
    dist = [INF]*(N+1)
    dist[s] = 0

    pq = [(0, s)]
    while pq:
        _, s = heappop(pq)
        for t, d in edges[s]:
            if dist[t] > dist[s]+d:
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))
    return dist

for _ in range(int(input())):
    N, M = map(int, input().split())

    edges = [[] for _ in range(N+1)]
    for _ in range(M):
        a, b, c = map(int, input().split())
        edges[a].append((b, c))
        edges[b].append((a, c))

    K = int(input())
    friends = list(map(int, input().split()))

    dist = [0]*(N+1)
    for f in friends:
        for i, d in enumerate(dijkstra(f)):
            dist[i] += d

    ans = 0
    for i in range(1, N+1):
        if dist[i] < dist[ans]:
            ans = i
    print(ans)
