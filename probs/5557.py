import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
dp = [[0]*21 for _ in range(N)]
for i, n in enumerate(map(int, input().split())):
    if i == 0:
        dp[i][n] = 1
    elif i == N-1:
        print(dp[i-1][n])
    else:
        for j, m in enumerate(dp[i-1]):
            if m != 0:
                if j-n >= 0:
                    dp[i][j-n] += dp[i-1][j]
                if j+n <= 20:
                    dp[i][j+n] += dp[i-1][j]
