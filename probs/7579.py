import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
A = sorted(zip(map(int, input().split()), map(int, input().split())), key=lambda x: (x[1], x[0]))

dp = [[0]*10001 for _ in range(N+1)]
for i, (m, c) in zip(range(1, N+1), A):
    for j in range(10001):
        if j < c:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-c]+m)

for i, m in enumerate(dp[-1]):
    if m >= M:
        print(i)
        break
