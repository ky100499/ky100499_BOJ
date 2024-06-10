import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e10)

for _ in range(int(input())):
    K = int(input())

    # dp[i][j] -> i장부터 j장까지 합칠 때 필요한 최소 비용
    # dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+S[j+1]-S[i])
    # ans: dp[0][-1]
    dp = [[INF]*K for _ in range(K)]
    S = [0]
    for s in map(int, input().split()):
        S.append(S[-1]+s)
    for i in range(K):
        dp[i][i] = 0

    for i in reversed(range(K)):
        for j in range(i+1, K):
            for k in range(i, j):
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+S[j+1]-S[i])
    print(dp[0][-1])
