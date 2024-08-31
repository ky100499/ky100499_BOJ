import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = int(1e9)

N = int(input())
C = [list(map(int, input().split())) for _ in range(N)]
S, cnt = 0, 0
for i, s in enumerate(input().rstrip()):
    if s == 'Y':
        cnt += 1
        S |= 1 << i
P = int(input())

if cnt >= P:
    print(0)
    exit(0)

dp = [INF]*(1<<N)
dp[S] = 0
pq = [(0, S, cnt)]
while pq:
    c, s, n = heappop(pq)

    if c > dp[s]:
        continue

    if n == P:
        print(c)
        break

    for i in range(N):
        if s&(1<<i):
            for j in range(N):
                if not s&(1<<j):
                    ns, nc = s|(1<<j), c+C[i][j]
                    if dp[ns] > nc:
                        dp[ns] = nc
                        heappush(pq, (nc, ns, n+1))
else:
    print(-1)
