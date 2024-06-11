import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

MAX = 80001

N = int(input())

dp = [[0]*MAX for _ in range(N+1)]
for i, w in enumerate(reversed(list(map(int, input().split())))):
    dp[i+1][40000-w] = dp[i+1][40000+w] = 1
    for j in range(w, MAX-w):
        if dp[i][j]:
            dp[i+1][j] = dp[i+1][j-w] = dp[i+1][j+w] = 1

int(input())
print(*map(lambda x: 'NY'[dp[-1][40000+int(x)] or dp[-1][40000-int(x)]], input().split()))
