import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**10

def dijkstra(s):
    dist = [INF]*(N+1)
    dist[s] = 0
    pq = [(0, s)]

    while pq:
        d, s = heappop(pq)
        for t, td in edges[s]:
            if td == INF:
                continue
            if dist[t] > d+td:
                dist[t] = d+td
                heappush(pq, (d+td, t))
    return dist

for case in range(int(input())):
    N, P, M = map(int, input().split())

    X, V = [], []
    for _ in range(P):
        x, v = map(int, input().split())
        X.append(x)
        V.append(v)

    edges = [[] for _ in range(N+1)]
    for _ in range(M):
        D, L, *C = map(int, input().split())
        for i in range(L-1):
            a, b = C[i], C[i+1]
            edges[a].append((b, D))
            edges[b].append((a, D))


    res = [dijkstra(x) for x in X]
    ans = INF
    for i in range(1, N+1):
        tmp = 0
        for r, v in zip(res, V):
            tmp = max(tmp, r[i]*v)
            if tmp == INF:
                break
        ans = min(ans, tmp)
    print(f'Case #{case+1}: {ans if ans < INF else -1}')
