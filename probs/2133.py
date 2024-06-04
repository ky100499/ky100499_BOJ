N = int(input())

'''
[0]
X
X
X

[1]
O
X
X

[2]
X
O
X

[3]
X
X
O

[4]
O
O
X

[5]
O
X
O

[6]
X
O
O
'''

dp = [[0]*7 for _ in range(N+1)]
dp[0] = [1, 0, 0, 0, 1, 0, 1]

for i in range(1, N):
    dp[i][1] = dp[i-1][6]
    dp[i][2] = dp[i-1][5]
    dp[i][3] = dp[i-1][4]
    dp[i][4] = dp[i][0] + dp[i-1][3]
    dp[i][5] = dp[i-1][2]
    dp[i][6] = dp[i][0] + dp[i-1][1]
    dp[i+1][0] = dp[i-1][0] + dp[i][1] + dp[i][3]

print(dp[-1][0])
