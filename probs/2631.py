import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
A = [int(input()) for _ in range(N)]

dp = [1]*N
for i in range(N):
    for j in range(i):
        if A[i] > A[j]:
            dp[i] = max(dp[i], dp[j]+1)

print(N - max(dp))
