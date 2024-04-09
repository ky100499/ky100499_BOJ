import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
kids = list(map(int, input().split()))

dp = [0]*(N+1)
for k in kids:
    dp[k] = dp[k-1]+1
print(N - max(dp))
