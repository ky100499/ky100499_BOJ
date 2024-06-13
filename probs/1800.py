import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e12)

N, P, K = map(int, input().split())
edges = [{} for _ in range(N+1)]
for _ in range(P):
    a, b, c = map(int, input().split())
    edges[a][b] = c
    edges[b][a] = c

l, h = 0, INF
ans = INF
while l <= h:
    m = (l+h)//2

    dist = [INF]*(N+1)
    dist[1] = 0

    pq = [(0, 1)]
    while pq:
        sd, s = heappop(pq)

        if dist[s] < sd:
            continue

        if s == N:
            if sd <= K:
                ans = m
                h = m-1
            else:
                l = m+1
            break

        for t, d in edges[s].items():
            w = int(d > m)
            if dist[t] > sd+w:
                dist[t] = sd+w
                heappush(pq, (sd+w, t))
    else:
        print(-1)
        break
if ans != INF:
    print(ans)
