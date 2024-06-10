import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
P = list(map(int, input().split()))
M = int(input())

dp = [[-1]*M for _ in range(M)]
for i, p in enumerate(P):
    dp[0][p] = max(dp[0][p], i)

for i in range(1, M):
