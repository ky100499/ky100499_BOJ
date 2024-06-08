import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

'''
dp[i][j] -> W: i개, H: j개 (i >= j)
dp[i][j] = dp[i-1][j] (W) + dp[i][j-1] (H)

약이 N개일 때 개수 -> W N개 H N개 -> dp[N][N]
'''

dp = [[0]*31 for _ in range(31)]
for i in range(1, 31):
    dp[i][0] = 1
    for j in range(1, i+1):
        dp[i][j] = dp[i-1][j] + dp[i][j-1]

while True:
    N = int(input())
    if N == 0:
        break

    print(dp[N][N])
