import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

INF = int(1e9)

dp = [INF]*(8_000_001)
dp[1] = 0
q = deque([1])
while q:
    n = q.popleft()
    if n > 1 and dp[n-1] > dp[n]+1:
        dp[n-1] = dp[n]+1
        q.append(n-1)
    if n <= 4_000_000 and dp[2*n] > dp[n]+1:
        dp[2*n] = dp[n]+1
        q.append(2*n)

for _ in range(int(input())):
    print(dp[int(input())])
