import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e9)

N = int(input())
A = tuple(map(int, input().split()))
M = int(input())
C = [tuple(map(int, input().split())) for _ in range(M)]

cost = {}
cost[A] = 0
pq = [(0, A)]
while pq:
    sd, tp = heappop(pq)

    if cost[tp] < sd:
        continue

    for i in range(1, N):
        if tp[i] < tp[i-1]:
            break
    else:
        print(sd)
        break

    for l, r, c in C:
        l, r = l-1, r-1
        nt = tp[:l]+(tp[r],)+tp[l+1:r]+(tp[l],)+tp[r+1:]
        if nt not in cost or cost[nt] > sd+c:
            cost[nt] = sd+c
            heappush(pq, (sd+c, nt))
else:
    print(-1)
