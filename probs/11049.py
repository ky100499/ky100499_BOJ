import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e10)

N = int(input())
M = list(tuple(map(int, input().split())) for _ in range(N))

# dp[i][j] -> i번째부터 j번째까지 행렬곱 연산 횟수
# dp[i][j] = dp[i][k]+dp[k+1][j]+M[i][0]*M[k][1]*M[j][1] for k in [i, j-1]
# ans: dp[0][N-1]
dp = [[INF]*N for _ in range(N)]
for i in range(N):
    dp[i][i] = 0
    if i > 0:
        dp[i-1][i] = M[i-1][0]*M[i-1][1]*M[i][1]
for n in range(1, N):
    for i in range(N-n):
        for k in range(n):
            dp[i][i+n] = min(dp[i][i+n], dp[i][i+k]+dp[i+k+1][i+n]+M[i][0]*M[i+k][1]*M[i+n][1])
print(dp[0][-1])
