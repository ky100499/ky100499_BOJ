import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
A = [list(map(int, input().strip())) for _ in range(N)]

ans = A[0][0]
dp = [[(0,0,0)]*M for _ in range(N)]
# (가로, 세로, 대각선) 으로 연속 유효
dp[0][0] = (A[0][0], A[0][0], A[0][0])

for i in range(1, N):
    if A[i][0]:
        dp[i][0] = (1, dp[i-1][0][1]+1, 1)
        ans = 1
for i in range(1, M):
    if A[0][i]:
        dp[0][i] = (dp[0][i-1][0]+1, 1, 1)
        ans = 1

for i in range(1, N):
    for j in range(1, M):
        if A[i][j]:
            r = dp[i][j-1][0]+1
            c = dp[i-1][j][1]+1
            d = min(r, c, dp[i-1][j-1][2]+1)
            dp[i][j] = (r, c, d)
            ans = max(ans, d)

print(ans*ans)
