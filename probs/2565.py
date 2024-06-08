import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

N = int(input())
pq = []
for _ in range(N):
    heappush(pq, tuple(map(int, input().split())))

dp = [[0, 0] for _ in range(501)]
ans = 0
while pq:
    a, b = heappop(pq)
    dp[a] = [b, 1]
    for i in range(1, a):
        if dp[i][0] < b:
            dp[a][1] = max(dp[a][1], dp[i][1]+1)
            ans = max(ans, dp[a][1])
print(N - ans)
