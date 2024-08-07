import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e9)

M, N = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(M)]

dist = [[INF]*N for _ in range(M)]
pq = []

if B[0][0] != -1:
    dist[0][0] = B[0][0]
    pq = [(B[0][0], 0, 0)]

while pq:
    d, m, n = heappop(pq)

    if dist[m][n] < d:
        continue

    if (m, n) == (M-1, N-1):
        print(d)
        break

    for dm, dn in ((-1,0),(0,-1),(1,0),(0,1)):
        nm, nn = m+dm, n+dn
        if 0 <= nm < M and 0 <= nn < N and B[nm][nn] != -1:
            nd = d+B[nm][nn]
            if dist[nm][nn] > nd:
                dist[nm][nn] = nd
                heappush(pq, (nd, nm, nn))

else:
    print(-1)
