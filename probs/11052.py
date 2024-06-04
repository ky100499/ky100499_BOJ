import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
P = [0]+list(map(int, input().split()))

dp = [0]*(N+1)

for i in range(1, N+1):
    dp[i] = P[i]
    for j in range(1, i//2+1):
        dp[i] = max(dp[i], dp[j]+dp[i-j])

print(dp[N])
