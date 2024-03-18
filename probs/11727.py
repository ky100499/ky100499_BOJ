input = open('input.txt', 'r').readline

n = int(input())

dp = [0] * max(n+1, 3)
dp[1], dp[2] = 1, 3

for i in range(3, n+1):
    dp[i] = (2*dp[i-2] + dp[i-1]) % 10007

print(dp[n])
