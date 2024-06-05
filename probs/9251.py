import sys
input = sys.stdin.readline

A = input().strip()
B = input().strip()

dp = [[0]*(len(B)+1) for _ in range(len(A)+1)]
ans = 0

'''
i) a == b
해당 문자 이전까지의 문자열에 대한 공통부분수열 + 1

ii) a != b
max( LCS(A[:i], B[:j+1]), LCS(A[:i+1], B[:j]) )
'''
for i, a in enumerate(A):
    for j, b in enumerate(B):
        if a == b:
            dp[i+1][j+1] = dp[i][j] + 1
            ans = max(ans, dp[i+1][j+1])
        else:
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])

print(ans)
