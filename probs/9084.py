import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    N = int(input())
    P = list(map(int, input().split()))
    M = int(input())

    dp = [0]*(M+1)
    for p in P:
        if p > M:
            break
        dp[p] += 1
        for j in range(p, M+1):
            dp[j] += dp[j-p]
    print(dp[-1])
