import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

n = int(input())
tri = []
for _ in range(n):
    tri.append(list(map(int, input().split())))

dp = [[0]*n for _ in range(n)]
dp[0][0] = tri[0][0]

for i in range(1, n):
    dp[i][0] = dp[i-1][0] + tri[i][0]
    dp[i][i] = dp[i-1][i-1] + tri[i][i]
    for j in range(1, i):
        dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j]
print(max(dp[n-1]))
