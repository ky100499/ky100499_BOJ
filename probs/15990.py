import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

MOD = int(1e9)+9
MAX = int(1e5)

dp = [[0]*3 for _ in range(MAX+1)]
dp[1] = [1, 0, 0]
dp[2] = [0, 1, 0]
dp[3] = [1, 1, 1]

for i in range(4, MAX+1):
    dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % MOD
    dp[i][1] = (dp[i-2][2] + dp[i-2][0]) % MOD
    dp[i][2] = (dp[i-3][0] + dp[i-3][1]) % MOD

for _ in range(int(input())):
    print(sum(dp[int(input())]) % MOD)
