import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

A, B, C = (input().strip() for _ in range(3))

dp = [[[0]*(len(A)+1) for _ in range(len(B)+1)] for _ in range(len(C)+1)]
for i, c in enumerate(C):
    for j, b in enumerate(B):
        for k, a in enumerate(A):
            if a == b == c:
                dp[i+1][j+1][k+1] = dp[i][j][k]+1
            else:
                dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k], dp[i+1][j][k+1], dp[i][j+1][k+1])
print(dp[-1][-1][-1])
