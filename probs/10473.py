import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e9)

dep = tuple(map(float, input().split()))
dst = tuple(map(float, input().split()))
N = int(input())
G = [[0]*(N+2) for _ in range(N+2)]
C = [dep]
for i in range(1, N+1):
    x, y = map(float, input().split())
    C.append((x, y))
    for j, (xx, yy) in enumerate(C):
        G[i][j] = G[j][i] = ((x-xx)**2 + (y-yy)**2) ** 0.5
C.append(dst)
for i in range(N+1):
    G[-1][i] = G[i][-1] = ((dst[0]-C[i][0])**2 + (dst[1]-C[i][1])**2) ** 0.5

dist = [INF]*(N+2)
dist[0] = 0
pq = [(0, 0)]

while pq:
    sd, s = heappop(pq)

    if dist[s] < sd:
        continue

    if s == N+1:
        print(sd)
        break

    for t, d in enumerate(G[s]):
        if s == t:
            continue

        dt = 2 + abs(d-50)/5
        if s == 0:
            dt = d/5

        if dist[t] > sd+dt:
            dist[t] = sd+dt
            heappush(pq, (sd+dt, t))
