import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = 10**8

N = int(input())
dp = [[[INF]*3, [INF]*3] for _ in range(3)]

c = list(map(int, input().split()))
for i in range(3):
    dp[i][0][i] = c[i]

for i in range(1, N):
    c = list(map(int, input().split()))
    for j in range(3):
        for k in range(3):
            for x in range(3):
                if k == x:
                    continue
                dp[j][i%2][k] = min(
                    dp[j][i%2][k],
                    dp[j][(i-1)%2][x] + c[k]
                )
        dp[j][(i-1)%2] = [INF]*3

for i in range(3):
    dp[i][(N-1)%2][i] = INF

print(min(map(lambda x: min(x[(N-1)%2]), dp)))
