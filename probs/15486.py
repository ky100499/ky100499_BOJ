import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())

dp = [0]*(N+1)
for i in range(N):
    T, P = map(int, input().split())
    if i+T <= N:
        dp[i+T] = max(dp[i+T], dp[i]+P)
    dp[i+1] = max(dp[i], dp[i+1])
print(dp[-1])
