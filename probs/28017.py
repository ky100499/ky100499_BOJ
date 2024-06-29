import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
T = [list(map(int, input().split())) for _ in range(N)]

dp = [T[0][:], [0]*M]
for i in range(1, N):
    for j in range(M):
        dp[i%2][j] = T[i][j] + min(dp[(i-1)%2][:j]+dp[(i-1)%2][j+1:])
print(min(dp[(N-1)%2]))
