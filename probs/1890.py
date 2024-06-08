import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
B = [list(map(int, input().split())) for _ in range(N)]

dp = [[0]*N for _ in range(N)]
dp[0][0] = 1
for i in range(N):
    for j in range(N):
        if B[i][j] == 0:
            continue
        if i+B[i][j] < N:
            dp[i+B[i][j]][j] += dp[i][j]
        if j+B[i][j] < N:
            dp[i][j+B[i][j]] += dp[i][j]
print(dp[-1][-1])
