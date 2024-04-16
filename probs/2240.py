import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

T, W = map(int, input().split())
dp = [[[0]*(W+1) for _ in range(2)] for _ in range(T)]

n = int(input())
if n == 1:
    dp[0][0][0] = 1
else:
    dp[0][1][1] = 1

for i in range(1, T):
    n = int(input())-1

    dp[i][n][0] = dp[i-1][n][0]+1
    dp[i][n^1][0] = dp[i-1][n^1][0]

    for j in range(1, W+1):
        dp[i][n][j] = max(dp[i-1][n][j], dp[i-1][n^1][j-1]) + 1
        dp[i][n^1][j] = max(dp[i-1][n][j-1], dp[i-1][n^1][j])

print(max(map(max, dp[-1])))
