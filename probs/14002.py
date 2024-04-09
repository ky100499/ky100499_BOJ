import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def bt(i):
    if i == -1:
        return

    bt(prev[i])
    print(A[i], end=' ')

N = int(input())
A = list(map(int, input().split()))

dp = [1]*N
prev = [-1]*N
for i in range(N):
    for j in range(i):
        if A[i] > A[j] and dp[j]+1 > dp[i]:
            dp[i] = dp[j]+1
            prev[i] = j
m = max(dp)
print(m)

i = dp.index(m)
bt(i)
