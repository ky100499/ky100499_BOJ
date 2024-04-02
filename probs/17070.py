import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
house = [list(map(int, input().split())) for _ in range(N)]

dp = [[[0, 0, 0] for _ in range(N)] for _ in range(N)]
for i in range(1, N):
    if house[0][i] == 1:
        break
    dp[0][i] = [1, 0, 0]

for i in range(1, N):
    for j in range(2, N):
        # dp[i][j] -> (가로, 세로, 대각선) 에서 올 수 있는 경우의 수
        if house[i][j] == 1:
            continue

        up = house[i-1][j] == 0
        left = house[i][j-1] == 0

        if up and left:
            dp[i][j][2] = sum(dp[i-1][j-1])
            dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2]
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2]
        if not up and left:
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2]
        if up and not left:
            dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2]

print(sum(dp[-1][-1]))
