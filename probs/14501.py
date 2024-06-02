input = open('input.txt', 'r').readline

N = int(input())
dp = [0]*(N+1)

for i in range(N):
    T, P = map(int, input().split())
    d = i+T
    while d <= N:
        dp[d] = max(dp[d], dp[i]+P)
        d += 1
print(max(dp))
