import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e9)
MAX = int(6000*(2**0.5))+1

primes = [1]*(MAX+1)
primes[0] = primes[1] = 0
for i in range(2, MAX+1):
    if primes[i]:
        for j in range(i*i, MAX+1, i):
            primes[j] = 0

x1, y1, x2, y2 = map(int, input().split())
N = int(input())
T = [(x1, y1), (x2, y2)]
G = [{} for _ in range(N+2)]
if primes[(d := int(((x1-x2)**2 + (y1-y2)**2) ** 0.5))]:
    G[0][1] = G[1][0] = d
for i in range(2, N+2):
    x, y = map(int, input().split())
    for j, (xx, yy) in enumerate(T):
        if primes[(d := int(((x-xx)**2 + (y-yy)**2) ** 0.5))]:
            G[i][j] = G[j][i] = d
    T.append((x, y))

dist = [INF]*(N+2)
dist[0] = 0
pq = [(0, 0)]

while pq:
    sd, s = heappop(pq)

    if dist[s] < sd:
        continue

    if s == 1:
        print(sd)
        break

    for t, d in G[s].items():
        if s == t:
            continue

        if dist[t] > sd+d:
            dist[t] = sd+d
            heappush(pq, (sd+d, t))
else:
    print(-1)
