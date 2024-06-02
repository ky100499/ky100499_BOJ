N = int(input())

dp = [0, 1]
for i in range(N-1):
    dp = [sum(dp), dp[0]]
print(sum(dp))
