import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**12

def d_w():
    dist = [[INF]*2 for _ in range(N+1)]
    dist[1] = [0, INF]
    pq = [(0, 1, 1)]

    while pq:
        sd, s, run = heappop(pq)

        if sd > dist[s][run^1]:
            continue

        for t, d in edges[s].items():
            d = d / 2 if run else d * 2
            if dist[t][run] > dist[s][run^1]+d:
                dist[t][run] = dist[s][run^1]+d
                heappush(pq, (dist[t][run], t, run^1))

    return dist

def d_f():
    dist = [INF]*(N+1)
    dist[1] = 0
    pq = [(0, 1)]

    while pq:
        sd, s = heappop(pq)

        if sd > dist[s]:
            continue

        for t, d in edges[s].items():
            if dist[t] > dist[s]+d:
                dist[t] = dist[s]+d
                heappush(pq, (dist[t], t))

    return dist

N, M = map(int, input().split())

edges = [{} for _ in range(N+1)]
for _ in range(M):
    a, b, t = map(int, input().split())
    edges[a][b] = t
    edges[b][a] = t

cnt = 0
for w, f in zip(d_w(), d_f()):
    cnt += int(min(w) > f)
print(cnt)
