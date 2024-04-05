import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
arr = list(map(int, input().split()))

dp = [1]*N

for i in range(N):
    for j in range(i, -1, -1):
        if arr[i] > arr[j]:
            dp[i] = max(dp[i], dp[j]+1)
print(max(dp))