import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
A = [0]+list(map(int, input().split()))

# dp[i][j] -> i번째부터 j번째까지 팰린드롬인지?
dp = [[0]*(N+1) for _ in range(N+1)]
for i in range(1, N+1):
    dp[i][i] = 1

for i in range(1, N+1):
    for j in range(1, i):
        if A[i] == A[j]:
            if i == j+1:
                dp[j][i] = 1
            else:
                dp[j][i] = dp[j+1][i-1]

for _ in range(int(input())):
    S, E = map(int, input().split())
    print(dp[S][E])
