import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())

if N == 1:
    print(int(input()))
elif N == 2:
    print(int(input())+int(input()))
else:
    dp = [[0]*3 for _ in range(N)]

    for i in range(N):
        ipt = int(input())
        dp[i][0] = max(dp[i-2])+ipt if i > 1 else ipt
        dp[i][1] = dp[i-1][0]+ipt if i > 0 else 0
        dp[i][2] = max(dp[i-2]+dp[i-1]) if i > 1 else 0

    print(max(max(dp[-1]), dp[-2][1]))
