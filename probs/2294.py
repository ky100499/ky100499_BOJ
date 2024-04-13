import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = 10**8

N, K = map(int, input().split())
coins = list({int(input()) for _ in range(N)})
coins.sort()

dp = [INF]*(K+1)
for i in range(1, K+1):
    if i in coins:
        dp[i] = 1
    else:
        for coin in coins:
            if coin > i:
                break
            elif dp[i-coin] != INF:
                dp[i] = min(dp[i], dp[i-coin]+1)
print(-1 if dp[K] == INF else dp[K])
