import sys
input = sys.stdin.readline

N = int(input())
dp = [[0]*2 for _ in range(N)]
dp[0][1] = -1000
for i, a in enumerate(map(int, input().split())):
    dp[i][0] = a
    if i > 0:
        dp[i][1] = max(dp[i-1]) + a

print(max(map(max, dp)))
