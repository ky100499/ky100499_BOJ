MOD = int(1e9)

N = int(input())

# dp[i][j][s] -> i자리 수 중 j로 끝나며 상태가 s인 계단 수의 개수
dp = [[[0]*(1<<10) for _ in range(10)] for _ in range(N+1)]
for i in range(1, 10):
    dp[1][i][1<<i] = 1

for i in range(1, N):
    for j in range(10):
        # dp[i][j] -> dp[i+1][j-1] and dp[i+1][j+1]
        # state가 j를 포함하는 경우에 한해서만
        # j-1, j+1에 or 연산한 state에 경우의 수 더하기
        for s in range(1<<10):
            if s & (1<<j) == 1<<j:
                if j > 0:
                    dp[i+1][j-1][s|(1<<(j-1))] += dp[i][j][s]
                    dp[i+1][j-1][s|(1<<(j-1))] %= MOD
                if j < 9:
                    dp[i+1][j+1][s|(1<<(j+1))] += dp[i][j][s]
                    dp[i+1][j+1][s|(1<<(j+1))] %= MOD

ans = 0
for i in range(10):
    ans = (ans + dp[N][i][(1<<10)-1]) % MOD
print(ans)
