import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

MOD = int(1e9)+3

N, K = map(int, [input(), input()])

# dp[i][j] -> i번째까지 j가지 색상을 선택, (i번째 선택, 미선택)
dp = [[[0, 0] for _ in range(K+1)] for _ in range(N)]

# Case 1: 0번째 선택
# ans: dp[-1][K][1]
dp[0][0] = [0, 0]
dp[0][1] = [1, 0]

for i in range(1, N):
    for j in range(1, K+1):
        dp[i][j][0] = dp[i-1][j-1][1]
        dp[i][j][1] = sum(dp[i-1][j]) % MOD
ans = dp[-1][K][1]

# Case 1: 0번째 미선택
# ans: sum(dp[-1][K])
dp[0][0] = [0, 1]
dp[0][1] = [0, 0]

for i in range(1, N):
    dp[i][0] = [0, 1]
    for j in range(1, K+1):
        dp[i][j][0] = dp[i-1][j-1][1]
        dp[i][j][1] = sum(dp[i-1][j]) % MOD
ans = (ans + sum(dp[-1][K])) % MOD

print(ans)
