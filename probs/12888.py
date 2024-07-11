import sys
input = sys.stdin.readline

H = int(input())

dp = [0]*61
dp[0] = dp[1] = 1
for i in range(2, H+1):
    for j in range(0, i-1):
        dp[i] += dp[j]
    dp[i] = dp[i]*2+1
print(dp[H])
